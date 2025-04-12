/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PolyculeAudioProcessor::PolyculeAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
    ), apvts(*this, nullptr, "Parameters", createParameters())
#endif
{

}

PolyculeAudioProcessor::~PolyculeAudioProcessor()
{
}

//==============================================================================
const juce::String PolyculeAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PolyculeAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PolyculeAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PolyculeAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PolyculeAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PolyculeAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PolyculeAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PolyculeAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String PolyculeAudioProcessor::getProgramName (int index)
{
    return {};
}

void PolyculeAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void PolyculeAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    //static filters
    lpInput->calc(3500.0, 1.0, 0.707, getSampleRate());
    lpDrive->calc(4000.0, 1.0, 0.707, getSampleRate());
}

void PolyculeAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PolyculeAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void PolyculeAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    midBoostFreq = apvts.getRawParameterValue("VOICE")->load() * 1400.0 + 600.0;
    midBoostGain = apvts.getRawParameterValue("HUMP")->load() * 24.0;
    trebleGain = apvts.getRawParameterValue("TREBLE")->load() * 48.0 - 24.0;
    bassFreq = 300.0 - (apvts.getRawParameterValue("BASS")->load() * 275.0);
    overdriveGain = apvts.getRawParameterValue("GAIN")->load() * 100.0;
    volume = apvts.getRawParameterValue("LEVEL")->load();

    clipModeState = apvts.getRawParameterValue("CLIPMODE")->load();
    diode1State = apvts.getRawParameterValue("DIODE1")->load();
    diode2State = apvts.getRawParameterValue("DIODE2")->load();
    diode3State = apvts.getRawParameterValue("DIODE3")->load();
    diode4State = apvts.getRawParameterValue("DIODE4")->load();

    midBoost->calc(midBoostFreq, midBoostGain, 0.707, getSampleRate());
    hsTone->calc(2000.0, trebleGain, 1.0, getSampleRate());
    hpInput->calc(bassFreq, 1.0, 0.707, getSampleRate());
    overdrive->setGain(overdriveGain);

    updateClippingMode(clipModeState, diode1State, diode2State, diode3State, diode4State);

    for (auto sample = 0; sample < buffer.getNumSamples(); ++sample)
    {
        //CHANNEL NUMBER MUST BE ZERO FOR MONO INPUTS ;)
        float x = buffer.getSample(0, sample); //get input sample

        x = lpInput->process(x);
        x = hpInput->process(x);

        x = midBoost->process(x);

        x = overdrive->clip(x);

        x = lpDrive->process(x);

        x = hsTone->process(x);
        
        //loop over two output channels and write processed sample to output
        for (auto channel = 0; channel < totalNumOutputChannels; ++channel)
        {
            float* outBuffer = buffer.getWritePointer(channel);

            outBuffer[sample] = x * volume;
        }  
    }   
}

void PolyculeAudioProcessor::updateClippingMode(bool mode, bool d1, bool d2, bool d3, bool d4)
{
    std::vector<bool> diodeArray = { d1, d2, d3, d4 };
    int numActiveF = 0;
    int numActiveR = 0;

    if (mode == false) {
        overdrive->setMode(soft_clip);
    }
    else
    {
        overdrive->setMode(hard_clip);
    }

    for (int i = 0; i < diodeArray.size(); i++)
    {
        if (diodeArray[i] == true)
        {
            if (i % 2 == 0)
            {
                numActiveF += 1;
            }

            else 
            {
                numActiveR += 1;
            }
        } 
        
        else
        {
            if (i % 2 == 0)
            {
                numActiveF -= 1;
            }

            else
            {
                numActiveR -= 1;
            }
        }
    }
    
    double clipF = (1 - (numActiveF * 0.5)) * 0.75 + 0.25;
    double clipR = -1 * (1 - (numActiveR * 0.5)) * 0.75 - 0.25;

    overdrive->setClipThreshold(clipF, clipR);
    
}

//==============================================================================
bool PolyculeAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* PolyculeAudioProcessor::createEditor()
{
    return new PolyculeAudioProcessorEditor (*this);
}

//==============================================================================
void PolyculeAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = apvts.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void PolyculeAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(apvts.state.getType()))
            apvts.replaceState(juce::ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PolyculeAudioProcessor();
}

juce::AudioProcessorValueTreeState::ParameterLayout PolyculeAudioProcessor::createParameters()
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;

    params.push_back(std::make_unique<juce::AudioParameterFloat>("TREBLE", "treble", 0.0f, 1.0f, 0.5f));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("HUMP", "hump", 0.0f, 1.0f, 0.0f));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("BASS", "bass", 0.0f, 1.0f, 1.0f));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("GAIN", "gain", 0.0f, 1.0f, 0.5f));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("VOICE", "voice", 0.0f, 1.0f, 0.0f));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("LEVEL", "level", 0.0f, 1.0f, 0.5f));

    params.push_back(std::make_unique<juce::AudioParameterBool>("CLIPMODE", "clipmode", false));
    params.push_back(std::make_unique<juce::AudioParameterBool>("DIODE1", "diode1", false));
    params.push_back(std::make_unique<juce::AudioParameterBool>("DIODE2", "diode2", false));
    params.push_back(std::make_unique<juce::AudioParameterBool>("DIODE3", "diode3", false));
    params.push_back(std::make_unique<juce::AudioParameterBool>("DIODE4", "diode4", false));

    return { params.begin(), params.end() };
}