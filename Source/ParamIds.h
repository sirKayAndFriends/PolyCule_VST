/*
  ==============================================================================

    ParamIds.h
    Created: 1 Apr 2025 3:08:37pm
    Author:  jwh93

  ==============================================================================
*/

#pragma once

namespace ParamIDs
{
    inline constexpr auto Bass{ "Bass"};
    inline constexpr auto Clipping{ "Clipping" };
    inline constexpr auto Diode_neg{ "Diode_neg" };
    inline constexpr auto Diode_pos{ "Diode_pos" };
    inline constexpr auto Gain{ "Gain" };
    inline constexpr auto Hump{ "Hump" };
    inline constexpr auto Level{ "Level" };
    inline constexpr auto Tone{ "Tone" };
    inline constexpr auto Voice{ "Voice" };
}

const std::vector<juce::String> parameters =
{
    ParamIDs::Bass,
    ParamIDs::Clipping,
    ParamIDs::Diode_neg,
    ParamIDs::Diode_pos,
    ParamIDs::Gain,
    ParamIDs::Hump,
    ParamIDs::Level,
    ParamIDs::Tone,
    ParamIDs::Voice,
};
