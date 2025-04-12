# Versatile Overdrive
An overdrive and distortion VST with a variety of voice and clipping options!
Guitar overdrive pedals often emphasise a set of frequencies alongside their clipping arrangements.  This pedal covers all the sounds in one box!  Read on to discover more!!

## Introduction
**Voice and Hump Controls**
- Control the centre frequency and amount of boost for the overdrive.  The **Voice** knob controls where on the frequency spectrum the boost will sit and the **Hump** knob 
controls how much that frequency is boosted, from "flat" to 8x gain.  The **Voice** knob slides from 600hz to 2000hz to cover the range from Tubescreamer, through Rat to 
treble boost.  This section is pre-clipping so will inherently affect the amount of distortion available

**Clipping**
- Choose your style of diode-like clipping with the **Clip** button: Soft or Hard clipping.  In Hard-Clipping mode the **Diode** buttons allow you to choose your 
arrangement: Number of diodes (1 - 4) and their symmetrical arrangement.

**Tone**
- Does what it says on the tin.  Bass control is a pre-drive cut and the treble is a post-drive shelf for cut and boost.

**Gain and Level**
- Pretty obvious really

## For the Nerds
The hard clipping is a simple clip~ object in PureData - it limits the signal between a minimum and maximum value.  A "no diode" option (possible but why?) clips the signal 
between -3 and 3.  Adding diodes moves these numbers down so two forward diodes and one reverse for asymmetrical clipping limits the signal between -2 and 1.

The soft clipping mode is a very simple diode transfer function from [Baltic Labs](https://baltic-lab.com/2023/08/dsp-diode-clipping-algorithm-for-overdrive-and-distortion-effects/).  This is an interesting article as it sorts out some of the zero-crossing issues that come up in other functions (quadratic for example). 

### Why is it called PolyCule?
Because its flexible, versatile and plays nicely with everyone.

### Future Developments
- Better anti-aliasing.  Actually, some anti-aliasing.


