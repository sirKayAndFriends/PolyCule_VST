/*
  ==============================================================================

    distortion.h
    Created: 8 Apr 2025 6:29:22pm
    Author:  jwh93

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"

enum mode
{
    soft_clip,
    hard_clip,
    half_wave_rect,
    fuzz,
    triode
};

class Distortion
{
public:
    Distortion(int setting);

    void setGain(double amount);

    void setMode(int setting);
    
    float clip(float input);

    void setClipThreshold(double forward, double reverse);


    //float rectify(float input);

private:

    int clipMode;
    double forwardClip, reverseClip;
    double gain;
};

