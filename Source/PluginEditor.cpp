/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PolyculeAudioProcessorEditor::PolyculeAudioProcessorEditor (PolyculeAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize(650, 400);
    setLookAndFeel(&polyLAF);

    clipSetting = false;

    bgRed = 0;
    bgGreen = 175;
    bgBlue = 91;

    knobCols =
    {
        PolyLAF::skColours::skPaleCyan,
        PolyLAF::skColours::skPaleCyan,
        PolyLAF::skColours::skPaleCyan, 
        PolyLAF::skColours::skForestGreen,
        PolyLAF::skColours::skBerryPink,
        PolyLAF::skColours::skDaisyYellow,
    };

    diodeHardCols =
    {
        PolyLAF::skColours::skCocoa,
        PolyLAF::skColours::skCocoa,
        PolyLAF::skColours::skCocoa,
        PolyLAF::skColours::skCocoa
    };

    diodeSoftCols =
    {
        PolyLAF::skColours::skTomato,
        PolyLAF::skColours::skTomato,
        PolyLAF::skColours::skCocoa,
        PolyLAF::skColours::skCocoa
    };
    
    panelWidth = getWidth();
    panelHeight = getHeight();
    knobSize = 100;
    buttonSize = knobSize / 2;
    margin = 30;

    knobX =
    {
        margin,
        (panelWidth / 2) - knobSize / 2,
        panelWidth - margin - knobSize
    };

    knobY =
    {
        margin,
        panelHeight / 2,
        panelHeight - margin - knobSize
    };

    miscX =
    {
        knobX[0] + knobSize + (knobX[1] - (knobX[0] + knobSize)) / 2,
        knobX[2] - (knobX[2] - (knobX[1] + knobSize)) / 2
    };

    int clipY = (panelHeight / 2) - buttonSize;
    int clipX = miscX[1] - buttonSize * 2;

    clipPos =
    {
        {knobX[2] + buttonSize / 2, clipY + buttonSize / 2},
        {clipX + buttonSize , clipY},
        {clipX + buttonSize * 2, clipY},
        {clipX + buttonSize, clipY + buttonSize},
        {clipX + buttonSize * 2, clipY + buttonSize}
    };

    knobPos =
    {
        {knobX[0], knobY[0]},//Treble
        {knobX[1], knobY[0]},//Mids
        {knobX[2], knobY[0]},//Bass
        {knobX[1], knobY[1]},//Voice
        {knobX[0], knobY[2]},//Gain
        {knobX[2], knobY[2]} //Level
    };

    for (int i = 0; i < allKnobs.size(); i++)
    {
        allKnobs[i]->setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        allKnobs[i]->setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
        allKnobs[i]->setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colour(knobCols[i]));
        allKnobs[i]->setRange(0.0, 1.0, 0.01);

        if (i == 1 || i == 2 || i == 3)
        {
            allKnobs[i]->setValue(0.0);
            allKnobs[i]->setDoubleClickReturnValue(true, 0.0);
        }

        else
        {
            allKnobs[i]->setValue(0.5);
            allKnobs[i]->setDoubleClickReturnValue(true, 0.5);
        }
        allKnobs[i]->addListener(this);
        addAndMakeVisible(allKnobs[i]);

        allLabels[i]->setText(labelText[i], juce::NotificationType::dontSendNotification);
        allLabels[i]->setFont(polyLAF.getPluginFont().boldened().withHeight(24.0f));
        allLabels[i]->setJustificationType(juce::Justification::centred);
        allLabels[i]->setColour(juce::Label::ColourIds::textColourId, juce::Colour(juce::Colours::black));
        addAndMakeVisible(allLabels[i]);
    }  

    polyLAF.setMidVisual(miscX[0] - 50, knobY[1], 100, 75);
    updateFrequencyLabel(allKnobs[1]);
    updateFrequencyLabel(allKnobs[3]);

    for (int i = 0; i < clipButtons.size(); i++)
    {
        if (i == 0) {
            clipButtons[i]->setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colour(PolyLAF::skColours::skDaisyYellow));
            clipButtons[i]->setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colour(PolyLAF::skColours::skBerryPink));
            clipButtons[i]->setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colour(juce::Colours::black));
            clipButtons[i]->setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colour(juce::Colours::black));
            clipButtons[i]->setColour(juce::ComboBox::outlineColourId, juce::Colour(PolyLAF::skColours::skClear));
            clipButtons[i]->setToggleState(false, false);
        }
        else
        {
            clipButtons[i]->setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colour(PolyLAF::skColours::skClear));
            clipButtons[i]->setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colour(PolyLAF::skColours::skClear));
            clipButtons[i]->setColour(juce::ComboBox::outlineColourId, juce::Colour(PolyLAF::skColours::skClear));
        }

        clipButtons[i]->setClickingTogglesState(true);
        clipButtons[i]->addListener(this);
        addAndMakeVisible(clipButtons[i]);
    }

    addAndMakeVisible(voiceLabel);
    voiceLabel.setText("600", juce::dontSendNotification);
    voiceLabel.setFont(polyLAF.getPluginFont().boldened().withHeight(24.0f));
    voiceLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(titleLabel);
    titleLabel.setText("P  O  L  Y  C  U  L  E", juce::dontSendNotification);
    titleLabel.setFont(polyLAF.getPluginFont().boldened().withHeight(38.0f));
    titleLabel.setJustificationType(juce::Justification::centred);
}

PolyculeAudioProcessorEditor::~PolyculeAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

//==============================================================================
void PolyculeAudioProcessorEditor::paint (juce::Graphics& g)
{
    //0, 175, 153
    //255, 175, 153;
    //144, 175, 255;
    polyLAF.drawPanel(g, 0.0f, 0.0f, getWidth(), getHeight(), juce::Colour(bgRed, bgGreen, bgBlue));

    for (int i = 0; i < allKnobs.size(); i++)
    {
        allKnobs[i]->setBounds(knobPos[i][0], knobPos[i][1], knobSize, knobSize);
        allLabels[i]->setBounds(knobPos[i][0], knobPos[i][1] + knobSize, knobSize, 25);
    }

    for (int i = 0; i < clipPos.size(); i++)
    {
        clipButtons[i]->setBounds(clipPos[i][0], clipPos[i][1], buttonSize, buttonSize);
    }

    for (int i = 0; i < 4; i++)
    {
        if (clipSetting == true)
        {
            if (i % 2 == 0)
            {
                polyLAF.diode(g, clipPos[i + 1][0], clipPos[i + 1][1], buttonSize, diodeHardCols[i], false);
            }
            else
            {
                polyLAF.diode(g, clipPos[i + 1][0], clipPos[i + 1][1], buttonSize, diodeHardCols[i], true);
            }
            
        }
        else if (clipSetting == false)
        {
            if (i % 2 == 0)
            {
                polyLAF.diode(g, clipPos[i + 1][0], clipPos[i + 1][1], buttonSize, diodeSoftCols[i], false);

            }
            else
            {
                polyLAF.diode(g, clipPos[i + 1][0], clipPos[i + 1][1], buttonSize, diodeSoftCols[i], true);

            }
        }
        
    }

    voiceLabel.setBounds(miscX[0] - knobSize / 2, polyLAF.lineY, knobSize, 35);
    voiceLabel.setText(voiceFreq, juce::dontSendNotification);

    titleLabel.setBounds((panelWidth / 2) - ((panelWidth / 2) / 2), panelHeight  - (panelHeight/ 5), panelWidth / 2, 100);

    polyLAF.drawMidVisual(g, voiceSlider, humpSlider);
}

void PolyculeAudioProcessorEditor::resized()
{
}

void PolyculeAudioProcessorEditor::updateFrequencyLabel(juce::Slider* slider)
{
    if (slider == &mVoiceSlider)
    {
        double sliderVal = slider->getValue();
      
        //scale to Hz values and send to label
        double scaled = (sliderVal * 1400) + 600;
        int scaledVal = juce::roundDoubleToInt(scaled);
        std::string hz = "Hz";
        voiceFreq = std::to_string(scaledVal) + hz;

        //change background colour!
        if (sliderVal <= 0.5)
        {
            bgRed = sliderVal * 510;
        }

        if (sliderVal > 0.5)
        {
            double reverseVal = 1 - ((sliderVal - 0.5) * 2);
            double bPercentage = (sliderVal - 0.5) / (1 - 0.5);
            double rPercentage = (reverseVal - 0.5) / (1 - 0.5);
            bgRed = rPercentage * (255 - 144) + 144;
            bgBlue = bPercentage * (255 - 91) + 91;
        }
        
        voiceSlider = polyLAF.controlMin + (sliderVal * polyLAF.controlWidth);
        repaint();
    }

    if (slider == &mHumpSlider)
    {
        double humpSliderVal = slider->getValue();
        humpSlider = polyLAF.lineY - (humpSliderVal * polyLAF.humpHeight);
        repaint();
    }
}

void PolyculeAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    bool toggleState = button->getToggleState();

    if (button == &clipButton)
    {
        processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_CLIPPING, toggleState);

        if (toggleState == true)
        {
            button->setButtonText("HARD CLIP");
            clipSetting = true;
        }

        if (toggleState == false)
        {
            button->setButtonText("SOFT CLIP");
            clipSetting = false;
        }
    } 

    if (clipButton.getToggleState() == true)
    {
        if (button == &diode1)
        {
            processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_DIODE_POS, toggleState);

            if (toggleState == true)
            {
                diodeHardCols.at(0) = PolyLAF::skColours::skTomato;
            }
            else
            {
                diodeHardCols.at(0) = PolyLAF::skColours::skCocoa;
            }
        }

        if (button == &diode2)
        {

            processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_DIODE_NEG, toggleState);
            if (toggleState == true)
            {
                diodeHardCols.at(1) = PolyLAF::skColours::skTomato;
            }
            else
            {
                diodeHardCols.at(1) = PolyLAF::skColours::skCocoa;
            }
        }

        if (button == &diode3)
        {
            processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_DIODE_POS, toggleState);

            if (toggleState == true)
            {
                diodeHardCols.at(2) = PolyLAF::skColours::skTomato;
            }
            else
            {
                diodeHardCols.at(2) = PolyLAF::skColours::skCocoa;
            }
        }

        if (button == &diode4)
        {
            processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_DIODE_NEG, toggleState);

            if (toggleState == true)
            {
                diodeHardCols.at(3) = PolyLAF::skColours::skTomato;
            }
            else
            {
                diodeHardCols.at(3) = PolyLAF::skColours::skCocoa;
            }
        }
    }
    else
    {
        clipSetting = false;
    }

    repaint();
}

void PolyculeAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &mBassSlider)
    {
        processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_BASS, mBassSlider.getValue());
    }

    if (slider == &mGainSlider)
    {
        processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_GAIN, mGainSlider.getValue());
    }

    if (slider == &mHumpSlider)
    {
        processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_HUMP, mHumpSlider.getValue());
        updateFrequencyLabel(slider);
    }

    if (slider == &mVoiceSlider)
    {
        processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_VOICE, mVoiceSlider.getValue());
        updateFrequencyLabel(slider);
    }

    if (slider == &mTrebleSlider)
    {
        processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_TONE, mTrebleSlider.getValue());
    }

    if (slider == &mLevelSlider)
    {
        processor.sendFloatToPlugin(HV_POLYCULE_PARAM_IN_LEVEL, mLevelSlider.getValue());
    }
}
