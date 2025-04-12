/*
  ==============================================================================

    distortion.cpp
    Created: 8 Apr 2025 6:29:11pm
    Author:  jwh93

  ==============================================================================
*/

#include "distortion.h"
#include "JuceHeader.h"

Distortion::Distortion(int setting)
{
    forwardClip = 1.0;
    reverseClip = -1.0;
    gain = 0.5;

    clipMode = setting;
}

void Distortion::setGain(double amount)
{
    gain = amount;
}

void Distortion::setMode(int setting)
{
    clipMode = setting;
}

void Distortion::setClipThreshold(double forward, double reverse)
{
    forwardClip = forward;
    reverseClip = reverse;
}


float Distortion::clip(float input)
{
    float output = 0.0f;

    switch (clipMode)
    {
        case soft_clip:
        {
            //gain boost
            input = input * gain;

            //diode transfer function
            if (input < 0.0f)
            {
                output = -1.0f + exp(input);
            }
            else if (input > 0.0f)
            {
                output = 1.0f - exp(-input);
            }
            else if (input == 0.0f)
            {
                output = 0.0f;
            }
            
            return output * 0.5;
            break;
        }
        
        case hard_clip:
        {
            input = input * gain;

            if (input >= forwardClip)
            {
                output = forwardClip;
            }
            else if (input <= reverseClip)
            {
                output = reverseClip;
            }

            else {
                output = input;
            }

            return output * 0.5;
            break;
        }

        default:
        {
            output = input;
        }
    } 
}




