/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <../JuceLibraryCode/JuceHeader.h>
#include "customClasses/distortion.h"
#include "customClasses/skFilters.h"
 
//==============================================================================
/**
*/

enum moveableFilter
{
    boost,
    treble,
    bass
};


class PolyculeAudioProcessor : public juce::AudioProcessor
{
public:
    //==============================================================================
    PolyculeAudioProcessor();
    ~PolyculeAudioProcessor() override;

    //==============================================================================
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    void updateClippingMode(bool mode, bool d1, bool d2, bool d3, bool d4);

    juce::AudioProcessorValueTreeState apvts;

private:
    //==============================================================================

    Distortion* overdrive = new Distortion(soft_clip);
    Peq* midBoost = new Peq(peak);
    Peq* hpInput = new Peq(highpass);
    Peq* lpInput = new Peq(lowpass);
    Peq* lpDrive = new Peq(lowpass);
    Peq* hsTone = new Peq(highshelf);

    double midBoostFreq;
    double midBoostGain;
    double trebleGain;
    double bassFreq;
    double overdriveGain;
    double volume;

    bool clipModeState;
    bool diode1State;
    bool diode2State;
    bool diode3State;
    bool diode4State;

    juce::AudioProcessorValueTreeState::ParameterLayout createParameters();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PolyculeAudioProcessor)
};
