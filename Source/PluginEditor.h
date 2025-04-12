/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <../JuceLibraryCode/JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class PolyLAF : public juce::LookAndFeel_V4
{
public:

    enum skColours {
        skLavendar = 0xffaa46d8,
        skLightBlue = 0xff00c3ff,
        skPaleCyan = 0xff00eaff,
        skDaisyYellow = 0xfffff700,
        skPaleYellow = 0xffffff4d,
        skCream = 0xffffff90,
        skMauve = 0xffbb00c0,
        skPalePurple = 0xffbb56ff,
        skPeach = 0xffffbaae,
        skBerryPink = 0xffd800a5,
        skPrincessPink = 0xffff38c3,
        skStrawbYog = 0xffffcfff,
        skRaspberry = 0xffff0064,
        skTomato = 0xffff0000,
        skMintGreen = 0xff5cfff9,
        skBarleyGreen = 0xff3ee8bb,
        skForestGreen = 0xff00e500,
        skDuckEgg = 0xff3ee1ff,
        skCocoa = 0xff550030,
        skClear = 0x00ffffff,
        skWhite = 0xffffffff,
        skBlack = 0xff000000
    };

    //basic data type for diode visualss (NOT BUTTONS)
    struct diodeData {
        juce::Button* button;//pointer to button linked with drawing graphic
        juce::Point<int> xy;
        juce::Point<float> midPoint;
        juce::Rectangle<float> bounds;
        std::vector<juce::Point<float>> triangle;//tip, left, right
        std::vector<juce::Point<float>> wire;
        std::vector<juce::Point<float>> cathode;

        bool state;
        int softColour;
        int hardColour;
        int unitSize;
        double lineThickness;
        bool reverse;
    } diodeData1, diodeData2, diodeData3, diodeData4;

    //array of struct pointers
    struct diodeData* diodeCollection[4] =
    {
        &diodeData1,
        &diodeData2,
        &diodeData3,
        &diodeData4
    };

    int lineStartX;
    int visualWidth;
    int lineEndX;
    float visualCurveWidth;
    int controlMin;
    int controlMax;  
    float controlWidth;
    int lineY;
    int maxY ;
    int humpHeight;

    juce::Path curve1;
    juce::Point<float> curveStart, controlDot, curveEnd, lineStart, lineEnd;

    static const juce::Font& getPluginFont()
    {
        static juce::Font quicksand(juce::Font(juce::Typeface::createSystemTypefaceFor(BinaryData::QuicksandRegular_otf,
            BinaryData::QuicksandRegular_otfSize)));

        return quicksand;
    };

    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider) override
    {
        auto radius = (float)juce::jmin(width / 2, height / 2);
        auto knobRect = juce::Rectangle<float>(x,y, width, height);
        auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto fill = slider.findColour(juce::Slider::rotarySliderFillColourId);

        juce::Point<float> centre(knobRect.getCentreX(), knobRect.getCentreY());

        g.setColour(fill);
        g.fillEllipse(knobRect);      

        juce::Path p;
        auto pointerThickness = 4.0f;
        p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, radius);
        p.applyTransform(juce::AffineTransform::rotation(angle).translated(centre));

        auto centreDot = juce::Rectangle<float>(pointerThickness, pointerThickness).withCentre(centre);

        g.setColour(juce::Colours::black);
        g.fillPath(p);
        g.fillEllipse(centreDot);
    }

    void drawPanel(juce::Graphics& g, float x, float y, float width, float height, juce::Colour bgCol)
    {
        juce::Rectangle<float> bgPanel(x, y, width, height);
        g.setColour(juce::Colour(bgCol));
        g.fillRect(bgPanel);
    }

    void drawLabels(juce::Slider* knob, juce::String& text)
    {
        juce::Label label;
        label.setText(text, juce::NotificationType::dontSendNotification);
        label.setFont(getPluginFont());
        label.setJustificationType(juce::Justification::centred);
        label.setColour(juce::Label::ColourIds::textColourId, juce::Colour(juce::Colours::black));
        juce::Rectangle<int> knobBounds = knob->getBounds();
        label.setBounds(knobBounds.getX(), knobBounds.getY(), knobBounds.getWidth(), knobBounds.getHeight());
    }

    void setMidVisual(int x, int y, int width, int height)
    {
        lineStartX = x;
        lineY = y;

        visualWidth = width;
        lineEndX = lineStartX + visualWidth; //450
        //CONTROL DOT (central point) defines other points
        visualCurveWidth = visualWidth / 4.0f; //100
        controlMin = lineStartX + (visualCurveWidth / 2); //50 + 50
        controlMax = lineEndX - (visualCurveWidth / 2); //450 - 50  
        controlWidth = controlMax - controlMin;
        //bounds = 100 -> 400 = 300
        maxY = lineY - height;
        humpHeight = lineY - maxY;
    }

    void drawMidVisual(juce::Graphics& g, float& peakX, float& peakY)
    {
        float lineThickness = 2.5f;
        
        auto centre = juce::Point<float>(lineStartX + (visualWidth / 2), lineY);
        auto box = juce::Rectangle<float>(visualWidth + (lineThickness * 2), humpHeight+(lineThickness * 2)).withCentre(centre);
        
        lineStart.setXY(lineStartX, lineY);//100
        lineEnd.setXY(lineEndX, lineY);//400
        curveStart.setXY(peakX - (visualCurveWidth / 2), lineY);//200
        curveEnd.setXY(peakX + (visualCurveWidth / 2), lineY);//300
        controlDot.setXY(peakX, peakY);

        curve1.clear();
        curve1.startNewSubPath(lineStart);
        curve1.lineTo(curveStart);
        curve1.quadraticTo(controlDot, curveEnd);
        curve1.lineTo(lineEnd);

        g.setColour(juce::Colour(juce::Colours::black));
        g.strokePath(curve1, juce::PathStrokeType(lineThickness));
        g.drawRect(box, lineThickness);
    }

    void diodeInit(juce::Button* button, int x, int y, int size, int colour, bool state, bool reverse, int index)
    {
        double thick = 4.0;
        //set const variables
        diodeCollection[index]->bounds = juce::Rectangle<float>(x, y, size, size);
        diodeCollection[index]->button = button;
        diodeCollection[index]->xy = juce::Point(x, y);
        diodeCollection[index]->unitSize = size;
        diodeCollection[index]->state = state;
        diodeCollection[index]->lineThickness = thick;
        diodeCollection[index]->reverse = reverse;
        diodeCollection[index]->hardColour = colour;
        diodeCollection[index]->softColour = colour;
        diodeCollection[index]->reverse = reverse;

        //work out points for drawing
        float midPointX(x + size / 2);
        diodeCollection[index]->triangle = {
            juce::Point<float>(midPointX, y + size / 3),
            juce::Point<float>(midPointX - size / 5, y + (size * 0.66)),
            juce::Point<float>(midPointX + size / 5, y + (size * 0.66))
        };

        diodeCollection[index]->wire = {
            juce::Point<float>(midPointX, y),
            juce::Point<float>(midPointX, y + size)
        };

        diodeCollection[index]->cathode = {
            juce::Point<float>(midPointX - size / 4, y + size / 3 - (thick / 2.0)),
            juce::Point<float>(midPointX + size / 4, y + size / 3 - (thick / 2.0))
        };

        diodeCollection[index]->midPoint = juce::Point(midPointX, y + size / 2.0f);
    }


    void drawDiode(juce::Graphics& g, int index, bool clipMode)
    {
        juce::Path diodeSymbol;

        if (clipMode == false)
        {
            g.setColour(juce::Colour(diodeCollection[index]->softColour));
        }
        else 
        {
            g.setColour(juce::Colour(diodeCollection[index]->hardColour));
        }
        

        //vertical line "wire"
        diodeSymbol.startNewSubPath(diodeCollection[index]->wire[0]);
        diodeSymbol.lineTo(diodeCollection[index]->wire[1]);
        
        //Triangle
        diodeSymbol.addTriangle(diodeCollection[index]->triangle[0], diodeCollection[index]->triangle[1], diodeCollection[index]->triangle[2]);     

        //horizontal line "cathode"
        diodeSymbol.startNewSubPath(diodeCollection[index]->cathode[0]);
        diodeSymbol.lineTo(diodeCollection[index]->cathode[1]);

        if (diodeCollection[index]->reverse == true)
        {
            juce::AffineTransform rotation = juce::AffineTransform::rotation(juce::MathConstants<float>::pi, diodeCollection[index]->midPoint.x, diodeCollection[index]->midPoint.y);
            diodeSymbol.applyTransform(rotation);
        }

        g.fillPath(diodeSymbol);
        g.strokePath(diodeSymbol, juce::PathStrokeType(diodeCollection[index]->lineThickness));
        g.strokePath(diodeSymbol, juce::PathStrokeType(diodeCollection[index]->lineThickness));

        g.setColour(juce::Colour(PolyLAF::skColours::skCocoa));
        g.drawEllipse(diodeCollection[index]->bounds, diodeCollection[index]->lineThickness);
        diodeSymbol.clear();
    }

    void diodeSort(juce::Button* button, bool state)
    {
        for (int i = 0; i < sizeof(diodeCollection); i++)
        {
            if (diodeCollection[i]->button == button)
            {
                if (state == true)
                {
                    diodeCollection[i]->hardColour = skColours::skTomato;
                    break;
                }

                else
                {
                    diodeCollection[i]->hardColour = skColours::skCocoa;
                    break;
                }
            }
        }
    }
};



class PolyculeAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                      public juce::Slider::Listener,
                                      public juce::Button::Listener
{
public:
    PolyculeAudioProcessorEditor (PolyculeAudioProcessor&);
    ~PolyculeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override;
    void buttonClicked(juce::Button* button) override;
    void updateFrequencyLabel(juce::Slider* slider);
    
private:

    juce::Slider mBassSlider, mGainSlider, mHumpSlider, mTrebleSlider, mVoiceSlider, mLevelSlider;
    juce::TextButton clipButton{ "SOFT CLIP" };
    juce::Label voiceLabel;
    juce::Label titleLabel;
    juce::Label treble, hump, bass, voice, level, gain;
    juce::TextButton diode1{ "" }, diode2{ "" }, diode3{ "" }, diode4{ "" };

    int bgRed, bgGreen, bgBlue;
    juce::Colour voiceCol;

    std::vector<juce::String> labelText
    {
        "Treble",
        "Hump",
        "Bass",
        "Voice",
        "Gain",
        "Level"
    };

    std::vector<juce::Label*> allLabels
    {
        &treble,
        &hump,
        &bass,
        &voice,
        &gain,
        &level
    };

    std::vector<juce::Slider*> allKnobs
    {
        &mTrebleSlider,
        &mHumpSlider,
        &mBassSlider,
        &mVoiceSlider,
        &mGainSlider,
        &mLevelSlider              
    };

    std::vector<juce::Button*> clipButtons
    {
        &clipButton,
        &diode1,
        &diode2,
        &diode3,
        &diode4
    };

    std::vector<int> knobX;
    std::vector<int> knobY;
    std::vector<int> miscX;
    std::vector<std::vector<int>> knobPos;
    std::vector<std::vector<int>> clipPos;
    std::vector<int> knobCols;

    int panelWidth;
    int panelHeight;
    int knobSize;
    int buttonSize;
    int margin;

    float voiceSlider, humpSlider;

    std::string voiceFreq;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> trebleSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> humpSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> bassSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> voiceSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> levelSliderAttachment;

    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> clipModeButtonAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> diode1ButtonAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> diode2ButtonAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> diode3ButtonAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> diode4ButtonAttachment;


    PolyLAF polyLAF;
    PolyculeAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PolyculeAudioProcessorEditor)
};
