/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "ParamIds.h"

//==============================================================================
PolyculeAudioProcessor::PolyculeAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
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
    context = hv_polycule_new(sampleRate);
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

    for (auto i = totalNumOutputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (auto i = totalNumInputChannels; i < totalNumInputChannels; i++)
    {
        buffer.clear(i, 0, buffer.getNumSamples());
    }

    int bufferOffset = 0;
    int samplesLastSegment = buffer.getNumSamples() - bufferOffset;
    if (samplesLastSegment > 0)
    {
        renderPlugin(buffer, samplesLastSegment, bufferOffset);
    }
}

void PolyculeAudioProcessor::renderPlugin(juce::AudioBuffer<float>& buffer, int sampleCount, int bufferOffset)
{
    float* outputBuffers[2] = { nullptr, nullptr };
    outputBuffers[0] = buffer.getWritePointer(0) + bufferOffset;
    if (getTotalNumOutputChannels() > 1) {
        outputBuffers[1] = buffer.getWritePointer(1) + bufferOffset;
    }

    float* inputBuffers[2] = { nullptr, nullptr };
    inputBuffers[0] = buffer.getWritePointer(0) + bufferOffset;
    if (getTotalNumInputChannels() > 1) {
        inputBuffers[1] = buffer.getWritePointer(1) + bufferOffset;
    }

    //tells the Heavy code to get to work. 
    //replace inputBuffers with NULL if you have no inputs
    hv_process(context, inputBuffers, outputBuffers, buffer.getNumSamples());
}

//this guy sends GUI data to the heavy code
void PolyculeAudioProcessor::sendFloatToPlugin(hv_uint32_t receiverHash, float pitch) {
    if (context) hv_sendFloatToReceiver(context, receiverHash, pitch);
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
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PolyculeAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PolyculeAudioProcessor();
}
