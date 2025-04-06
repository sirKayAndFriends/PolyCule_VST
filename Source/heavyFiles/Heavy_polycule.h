/** SKAF */

#ifndef _HEAVY_POLYCULE_H_
#define _HEAVY_POLYCULE_H_

#include "HvHeavy.h"

#ifdef __cplusplus
extern "C" {
#endif

#if HV_APPLE
#pragma mark - Heavy Context
#endif

typedef enum {
  HV_POLYCULE_PARAM_IN_BASS = 0x18E7F0B7, // Bass
  HV_POLYCULE_PARAM_IN_CLIPPING = 0x300856D3, // Clipping
  HV_POLYCULE_PARAM_IN_DIODE_NEG = 0xB1C3A529, // Diode_neg
  HV_POLYCULE_PARAM_IN_DIODE_POS = 0xF4D0459, // Diode_pos
  HV_POLYCULE_PARAM_IN_GAIN = 0x677821DA, // Gain
  HV_POLYCULE_PARAM_IN_HUMP = 0xB2B2CA1D, // Hump
  HV_POLYCULE_PARAM_IN_LEVEL = 0x3D02EA21, // Level
  HV_POLYCULE_PARAM_IN_TONE = 0xE3C2D868, // Tone
  HV_POLYCULE_PARAM_IN_VOICE = 0xAC4A4490, // Voice
} Hv_polycule_ParameterIn;


/**
 * Creates a new patch instance.
 * Sample rate should be positive and in Hertz, e.g. 44100.0.
 */
HeavyContextInterface *hv_polycule_new(double sampleRate);

/**
 * Creates a new patch instance.
 * @param sampleRate  Sample rate should be positive (> 0) and in Hertz, e.g. 48000.0.
 * @param poolKb  Pool size is in kilobytes, and determines the maximum amount of memory
 *   allocated to messages at any time. By default this is 10 KB.
 * @param inQueueKb  The size of the input message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages between calls to
 *   process(). Default is 2 KB.
 * @param outQueueKb  The size of the output message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages to the default sendHook.
 *   See getNextSentMessage() for info on accessing these messages. Default is 0 KB.
 */
HeavyContextInterface *hv_polycule_new_with_options(double sampleRate, int poolKb, int inQueueKb, int outQueueKb);

/**
 * Free the patch instance.
 */
void hv_polycule_free(HeavyContextInterface *instance);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // _HEAVY_POLYCULE_H_
