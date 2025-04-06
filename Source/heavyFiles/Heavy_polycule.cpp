/** SKAF */

#include "Heavy_polycule.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_polycule *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_polycule_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_polycule));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_polycule(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_polycule_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_polycule));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_polycule(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_polycule_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_polycule();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_polycule::Heavy_polycule(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_9e4xL0L3);
  numBytes += sLine_init(&sLine_nGqTF2lq);
  numBytes += sLine_init(&sLine_OswWEXrK);
  numBytes += sLine_init(&sLine_Tc1HbscM);
  numBytes += sLine_init(&sLine_KpI4HxA3);
  numBytes += sBiquad_init(&sBiquad_s_wKdo07VT);
  numBytes += sLine_init(&sLine_ollV2Kg6);
  numBytes += sLine_init(&sLine_h2rTC68R);
  numBytes += sLine_init(&sLine_4LxtWRrK);
  numBytes += sLine_init(&sLine_ULIdzvfl);
  numBytes += sLine_init(&sLine_5uipgrk8);
  numBytes += sBiquad_init(&sBiquad_s_rnFtbM4i);
  numBytes += sLine_init(&sLine_EGJnCRU7);
  numBytes += sLine_init(&sLine_c35xVqS6);
  numBytes += sLine_init(&sLine_L6QI2sxz);
  numBytes += sLine_init(&sLine_2aqS4R4C);
  numBytes += sLine_init(&sLine_8CzXJsUm);
  numBytes += sBiquad_init(&sBiquad_s_SEeodoXi);
  numBytes += sLine_init(&sLine_wkTpzcvQ);
  numBytes += sLine_init(&sLine_V183eFbc);
  numBytes += sLine_init(&sLine_6nWJNpwK);
  numBytes += sLine_init(&sLine_aujPyI3o);
  numBytes += sLine_init(&sLine_hZX6p11G);
  numBytes += sBiquad_init(&sBiquad_s_5xrS1eni);
  numBytes += sLine_init(&sLine_zV1pENor);
  numBytes += sLine_init(&sLine_dEacS5S5);
  numBytes += sLine_init(&sLine_ig1MqdXn);
  numBytes += sLine_init(&sLine_5sbSW92o);
  numBytes += sLine_init(&sLine_0ufmkMY6);
  numBytes += sBiquad_init(&sBiquad_s_cbMwCZen);
  numBytes += sLine_init(&sLine_853HbX5T);
  numBytes += sLine_init(&sLine_tfawjeIt);
  numBytes += sLine_init(&sLine_mSP6osrT);
  numBytes += sLine_init(&sLine_UNC9iX7K);
  numBytes += sLine_init(&sLine_7fHdDRHo);
  numBytes += sBiquad_init(&sBiquad_s_P0cKR8Qx);
  numBytes += sLine_init(&sLine_CFcusdIv);
  numBytes += sLine_init(&sLine_ycUzQxqt);
  numBytes += sLine_init(&sLine_d2zk7NHW);
  numBytes += sLine_init(&sLine_hWxlgDVl);
  numBytes += sLine_init(&sLine_VCxDIKgm);
  numBytes += sBiquad_init(&sBiquad_s_2uDpJATX);
  numBytes += cVar_init_f(&cVar_IFqHHym8, 3.0f);
  numBytes += cVar_init_f(&cVar_ZqSXEZAv, 1.0f);
  numBytes += cBinop_init(&cBinop_WW4KDjK2, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_34bo36jI, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_0RmdBP81, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_ACtj0btH, 0.0f);
  numBytes += cBinop_init(&cBinop_kWSKR1HY, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_xbU2Syu3, 44100.0f); // __div
  numBytes += cVar_init_f(&cVar_1mWQw5eI, 0.0f);
  numBytes += cBinop_init(&cBinop_JsYKaaJb, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_1iggz5hh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_cegagA1a, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_pFAZIk2o, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_oBBW4syz, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_k4udKMhm, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_rCVE6Mzx, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_cW5Lsfh9, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Xg39tw28, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0MODuUKy, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_F9UbFMyW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6sFgKLWy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_OdmWq08A, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RvXiE4wD, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_EctSGFui, 1.0f);
  numBytes += cVar_init_f(&cVar_7H9YyhX8, 2000.0f);
  numBytes += cBinop_init(&cBinop_xatg3L5l, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_gi2tqjb9, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_3qxZhCIB, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_XGbdzjfD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_NI2Q2oPZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4tUamFjx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4Myxjjx5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_xpKwmZ35, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_gVIcgklg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_pUlP29M1, 0.0f); // __pow
  numBytes += cVar_init_f(&cVar_VoOQtFQq, 0.0f);
  numBytes += cVar_init_f(&cVar_RroKyjkR, 12000.0f);
  numBytes += cVar_init_f(&cVar_ntWgL4QV, 0.707f);
  numBytes += cVar_init_f(&cVar_YyyaxPh2, 0.0f);
  numBytes += cBinop_init(&cBinop_U9CASsdy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_A6GJgRHU, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_RiG46JpJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ZAn4Ugp9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_MSLowEsR, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_80Jtb1iq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Dn0Hr70b, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_wDOTRzCx, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ZTvcqTk2, 0.0f);
  numBytes += cVar_init_f(&cVar_yxencfLj, 0.5f);
  numBytes += cVar_init_f(&cVar_bxFajgMm, 0.0f);
  numBytes += cVar_init_f(&cVar_I8Dzr7p9, 0.707f);
  numBytes += cVar_init_f(&cVar_5ZndH7bp, 3500.0f);
  numBytes += cVar_init_f(&cVar_qRciwK3D, 0.0f);
  numBytes += cBinop_init(&cBinop_MB7oZ5bd, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_iazfOgiI, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_MACiWWpo, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_8XlyzY0b, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DP2qh9KM, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_y9BuMGNa, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_R9efVThn, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_2ghouWSh, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_oYZ1FsTQ, 25.0f);
  numBytes += cBinop_init(&cBinop_JGlLEteq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4cscjnoz, 44100.0f); // __div
  numBytes += cVar_init_f(&cVar_rRdNVMw8, 0.707f);
  numBytes += cVar_init_f(&cVar_2cbZCCNK, 0.0f);
  numBytes += cBinop_init(&cBinop_tGsmIjqt, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_2RdC4ltE, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_FsQFvinu, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RIZRGPuA, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zJXHPS2e, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_kM3GwGSd, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_j76N8V0w, 1.0f);
  numBytes += cVar_init_f(&cVar_HCYGsdHC, 0.0f);
  numBytes += cVar_init_f(&cVar_KRne8x6H, 0.5f);
  numBytes += cVar_init_f(&cVar_qUvNarj0, 0.25f);
  numBytes += cVar_init_f(&cVar_h0mjgQhB, 0.0f);
  numBytes += cVar_init_f(&cVar_tiRp9ue3, 0.5f);
  numBytes += sVarf_init(&sVarf_CEpoV4ys, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ebO7RRGI, 3.0f);
  numBytes += cBinop_init(&cBinop_kPgmCLGF, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_J7yIm0MD, 0.0f);
  numBytes += cBinop_init(&cBinop_HjQdwr65, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_Yrgzoglk, 0.0f);
  numBytes += cBinop_init(&cBinop_IzZJGVQd, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_CZ74PW29, 0.707f);
  numBytes += cBinop_init(&cBinop_QtFJLpTQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ec8b7Lhl, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_TpyysmKi, 44100.0f); // __div
  numBytes += cVar_init_f(&cVar_3yo146eR, 600.0f);
  numBytes += cBinop_init(&cBinop_LEG3jHU4, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_anHedki1, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_e5EUbfw9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_LQWbGX2T, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_W2F1tf6l, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_8N37bZab, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_sPT8t41g, 0.0f); // __pow
  numBytes += cVar_init_f(&cVar_dRKZ5BG3, 12000.0f);
  numBytes += cBinop_init(&cBinop_a5QmDK2I, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_fLQneWkK, 44100.0f); // __div
  numBytes += cVar_init_f(&cVar_a67gk6IJ, 0.707f);
  numBytes += cVar_init_f(&cVar_n5wAL7E1, 0.0f);
  numBytes += cBinop_init(&cBinop_IyAlHXJX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_p4uBiqjt, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_MOQvxTDu, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_QnXCXKcy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_PpHVlJi5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KvZGPGWE, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_kFaIg4s4, 0.0f);
  numBytes += cBinop_init(&cBinop_Uf55ORtn, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_YjxtLSy7, 44100.0f); // __div
  numBytes += cVar_init_f(&cVar_dypgIm5q, 0.707f);
  numBytes += cVar_init_f(&cVar_SbkGaTKJ, 0.0f);
  numBytes += cVar_init_f(&cVar_u5FS8vlw, 4000.0f);
  numBytes += cBinop_init(&cBinop_WpfpMcYB, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_OfopRk2a, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_leBbH8Se, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ScmL81if, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_W6zj9iZ9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_juz5HF1J, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_FOjFmYSA, 0.0f);
  numBytes += sVarf_init(&sVarf_xerhqfUe, -3.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TN6iClnE, 2.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_dHuDnzxh, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_8Vx7XtOF, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_32XBK37Z, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_8cf4WXdB, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_XwToN5DN, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_4fREovV8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OKELXIQ2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sqtSypp4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jEvqjtKG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_W5h4cIYu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9YgrJmHN, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_polycule::~Heavy_polycule() {
  // nothing to free
}

HvTable *Heavy_polycule::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_polycule::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x18E7F0B7: { // Bass
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oR02XZuF_sendMessage);
      break;
    }
    case 0x300856D3: { // Clipping
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Yg0UBiKt_sendMessage);
      break;
    }
    case 0xB1C3A529: { // Diode_neg
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7SvxpBcp_sendMessage);
      break;
    }
    case 0xF4D0459: { // Diode_pos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NrKxKd7X_sendMessage);
      break;
    }
    case 0x677821DA: { // Gain
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_c3Udbkss_sendMessage);
      break;
    }
    case 0xB2B2CA1D: { // Hump
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_veL8rFxp_sendMessage);
      break;
    }
    case 0x3D02EA21: { // Level
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NnwMaz6j_sendMessage);
      break;
    }
    case 0xE3C2D868: { // Tone
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_B2ngd8XP_sendMessage);
      break;
    }
    case 0xAC4A4490: { // Voice
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Vhd0e2Fm_sendMessage);
      break;
    }
    case 0xEF15F25F: { // 1031-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AxBMWFrv_sendMessage);
      break;
    }
    case 0x5CC3A960: { // 1031-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_n1hRzgVZ_sendMessage);
      break;
    }
    case 0xAA413D24: { // 1031-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Qgl5KGCK_sendMessage);
      break;
    }
    case 0x6D76EE6A: { // 1072-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mqX08En5_sendMessage);
      break;
    }
    case 0x140BBCAE: { // 1072-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mH83Twnq_sendMessage);
      break;
    }
    case 0xAF039EF3: { // 1072-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xXry9poh_sendMessage);
      break;
    }
    case 0x4A01A80D: { // 1113-A
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QCyszybr_sendMessage);
      break;
    }
    case 0x26AB6D6A: { // 1113-sqrtA-alpha-2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LRChYx4n_sendMessage);
      break;
    }
    case 0x43F9CB30: { // 1113-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oyqM5JtJ_sendMessage);
      break;
    }
    case 0x5757AB67: { // 1113-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FINoPYCW_sendMessage);
      break;
    }
    case 0xF763418F: { // 1157-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3C8nGPPp_sendMessage);
      break;
    }
    case 0x1AD52B1A: { // 1157-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vYHOlTRf_sendMessage);
      break;
    }
    case 0xA662AE75: { // 1157-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IqXJgm8e_sendMessage);
      break;
    }
    case 0xF6BAB8C1: { // 1198-A
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nTVwhylI_sendMessage);
      break;
    }
    case 0x2C43DCAA: { // 1198-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IIqd3GpY_sendMessage);
      break;
    }
    case 0xE0617EE4: { // 1198-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3QNuqrQ6_sendMessage);
      break;
    }
    case 0x6D98BE77: { // 1198-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Kat1M39k_sendMessage);
      break;
    }
    case 0xFC150D1A: { // 1352-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9IMH91wU_sendMessage);
      break;
    }
    case 0x88484FF4: { // 1352-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YuzfBRAg_sendMessage);
      break;
    }
    case 0x14F88F88: { // 1352-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RFVsvOge_sendMessage);
      break;
    }
    case 0xC04CB69A: { // 1393-alpha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_p3CzG4Fj_sendMessage);
      break;
    }
    case 0x31BB3A38: { // 1393-wcos
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yJSwzRvy_sendMessage);
      break;
    }
    case 0xFE8599E8: { // 1393-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_C0bhJVHm_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6WFEt1jK_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_polycule::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "Bass";
        info->hash = 0x18E7F0B7;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 1: {
        info->name = "Clipping";
        info->hash = 0x300856D3;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 2: {
        info->name = "Diode_neg";
        info->hash = 0xB1C3A529;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 3: {
        info->name = "Diode_pos";
        info->hash = 0xF4D0459;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 4: {
        info->name = "Gain";
        info->hash = 0x677821DA;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 5: {
        info->name = "Hump";
        info->hash = 0xB2B2CA1D;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 6: {
        info->name = "Level";
        info->hash = 0x3D02EA21;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 7: {
        info->name = "Tone";
        info->hash = 0xE3C2D868;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 8: {
        info->name = "Voice";
        info->hash = 0xAC4A4490;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 9;
}



/*
 * Send Function Implementations
 */


void Heavy_polycule::cMsg_4x3oilWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TC9o2kz8_sendMessage);
}

void Heavy_polycule::cSystem_TC9o2kz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 4.0f, 0, m, &cBinop_WcA0Hefp_sendMessage);
}

void Heavy_polycule::cVar_IFqHHym8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8cf4WXdB, HV_BINOP_SUBTRACT, 0, m, &cBinop_8cf4WXdB_sendMessage);
}

void Heavy_polycule::cVar_ZqSXEZAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sqtSypp4, m);
}

void Heavy_polycule::cMsg_vL9a4nRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_d2zk7NHW, 0, m, NULL);
}

void Heavy_polycule::cMsg_T44yElEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ycUzQxqt, 0, m, NULL);
}

void Heavy_polycule::cMsg_ORs2JGqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_CFcusdIv, 0, m, NULL);
}

void Heavy_polycule::cMsg_XS5iyhlb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VCxDIKgm, 0, m, NULL);
}

void Heavy_polycule::cMsg_e1RMSDlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_hWxlgDVl, 0, m, NULL);
}

void Heavy_polycule::cUnop_3DhoQbrM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7ZgxpWmI_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_TAbWBTBr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WW4KDjK2, HV_BINOP_MULTIPLY, 1, m, &cBinop_WW4KDjK2_sendMessage);
}

void Heavy_polycule::cBinop_WW4KDjK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0RmdBP81, HV_BINOP_ADD, 0, m, &cBinop_0RmdBP81_sendMessage);
}

void Heavy_polycule::cBinop_sue5sZ8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0RmdBP81, HV_BINOP_ADD, 1, m, &cBinop_0RmdBP81_sendMessage);
}

void Heavy_polycule::cBinop_34bo36jI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ACtj0btH, 1, m, &cVar_ACtj0btH_sendMessage);
}

void Heavy_polycule::cBinop_0RmdBP81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_34bo36jI, HV_BINOP_ADD, 0, m, &cBinop_34bo36jI_sendMessage);
}

void Heavy_polycule::cBinop_rrz9kOvO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TAbWBTBr_sendMessage);
}

void Heavy_polycule::cCast_nHvJ9QlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_sue5sZ8Q_sendMessage);
}

void Heavy_polycule::cCast_Rh37OuFq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_rrz9kOvO_sendMessage);
}

void Heavy_polycule::cVar_ACtj0btH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A4VE89cJ_sendMessage(_c, 0, m);
}

void Heavy_polycule::cUnop_AHHHoaVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_vUja36ow_sendMessage);
}

void Heavy_polycule::cMsg_GRVKrbjC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lvZmeRxL_sendMessage);
}

void Heavy_polycule::cSystem_lvZmeRxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xbU2Syu3, HV_BINOP_DIVIDE, 1, m, &cBinop_xbU2Syu3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WHFUgMF1_sendMessage);
}

void Heavy_polycule::cBinop_vUja36ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xbU2Syu3, HV_BINOP_DIVIDE, 0, m, &cBinop_xbU2Syu3_sendMessage);
}

void Heavy_polycule::cBinop_kWSKR1HY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vrp50c0I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eRfzdcxr_sendMessage);
}

void Heavy_polycule::cBinop_xbU2Syu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kWSKR1HY, HV_BINOP_MULTIPLY, 1, m, &cBinop_kWSKR1HY_sendMessage);
}

void Heavy_polycule::cMsg_tYjdiNxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_AHHHoaVa_sendMessage);
}

void Heavy_polycule::cCast_WHFUgMF1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tYjdiNxk_sendMessage(_c, 0, m);
}

void Heavy_polycule::cVar_1mWQw5eI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 24.0f, 0, m, &cBinop_CFDGpu1y_sendMessage);
}

void Heavy_polycule::cBinop_Eoz0PwbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kWSKR1HY, HV_BINOP_MULTIPLY, 0, m, &cBinop_kWSKR1HY_sendMessage);
}

void Heavy_polycule::cBinop_ebGIIkw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_Eoz0PwbO_sendMessage);
}

void Heavy_polycule::cBinop_JsYKaaJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pFAZIk2o, HV_BINOP_ADD, 0, m, &cBinop_pFAZIk2o_sendMessage);
}

void Heavy_polycule::cBinop_1iggz5hh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NI2Q2oPZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_NI2Q2oPZ_sendMessage);
}

void Heavy_polycule::cBinop_cegagA1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1iggz5hh, HV_BINOP_MULTIPLY, 0, m, &cBinop_1iggz5hh_sendMessage);
}

void Heavy_polycule::cBinop_pFAZIk2o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cegagA1a, HV_BINOP_ADD, 0, m, &cBinop_cegagA1a_sendMessage);
}

void Heavy_polycule::cBinop_B4ZO7Tbg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pFAZIk2o, HV_BINOP_ADD, 1, m, &cBinop_pFAZIk2o_sendMessage);
}

void Heavy_polycule::cBinop_4dWyDkbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JsYKaaJb, HV_BINOP_MULTIPLY, 1, m, &cBinop_JsYKaaJb_sendMessage);
}

void Heavy_polycule::cCast_v0KGgi10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1iggz5hh, HV_BINOP_MULTIPLY, 1, m, &cBinop_1iggz5hh_sendMessage);
}

void Heavy_polycule::cCast_Q5731c6P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_4dWyDkbH_sendMessage);
}

void Heavy_polycule::cCast_w6ekVKib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_B4ZO7Tbg_sendMessage);
}

void Heavy_polycule::cUnop_kcVxJgKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XCIs4h9x_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_oBBW4syz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xpKwmZ35, HV_BINOP_MULTIPLY, 1, m, &cBinop_xpKwmZ35_sendMessage);
}

void Heavy_polycule::cBinop_k4udKMhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rCVE6Mzx, HV_BINOP_ADD, 0, m, &cBinop_rCVE6Mzx_sendMessage);
}

void Heavy_polycule::cBinop_rCVE6Mzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cW5Lsfh9, HV_BINOP_SUBTRACT, 0, m, &cBinop_cW5Lsfh9_sendMessage);
}

void Heavy_polycule::cBinop_glj3pwTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rCVE6Mzx, HV_BINOP_ADD, 1, m, &cBinop_rCVE6Mzx_sendMessage);
}

void Heavy_polycule::cBinop_R2TVZSKV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k4udKMhm, HV_BINOP_MULTIPLY, 1, m, &cBinop_k4udKMhm_sendMessage);
}

void Heavy_polycule::cBinop_cW5Lsfh9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oBBW4syz, HV_BINOP_MULTIPLY, 0, m, &cBinop_oBBW4syz_sendMessage);
}

void Heavy_polycule::cCast_wnYGApYe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_glj3pwTo_sendMessage);
}

void Heavy_polycule::cCast_Mexnbtin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oBBW4syz, HV_BINOP_MULTIPLY, 1, m, &cBinop_oBBW4syz_sendMessage);
}

void Heavy_polycule::cCast_lyEExz6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_R2TVZSKV_sendMessage);
}

void Heavy_polycule::cBinop_jLuFgeqI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kouEbsCf_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_VeSQbFES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_jLuFgeqI_sendMessage);
}

void Heavy_polycule::cBinop_YE8MpmLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 40.0f, 0, m, &cBinop_fShnzF6Z_sendMessage);
}

void Heavy_polycule::cBinop_CFDGpu1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -24.0f, 0, m, &cBinop_YE8MpmLJ_sendMessage);
}

void Heavy_polycule::cBinop_Xg39tw28_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0MODuUKy, HV_BINOP_ADD, 0, m, &cBinop_0MODuUKy_sendMessage);
}

void Heavy_polycule::cBinop_AKNTLWx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xg39tw28, HV_BINOP_MULTIPLY, 1, m, &cBinop_Xg39tw28_sendMessage);
}

void Heavy_polycule::cBinop_0MODuUKy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F9UbFMyW, HV_BINOP_SUBTRACT, 0, m, &cBinop_F9UbFMyW_sendMessage);
}

void Heavy_polycule::cBinop_6aQfvPOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0MODuUKy, HV_BINOP_ADD, 1, m, &cBinop_0MODuUKy_sendMessage);
}

void Heavy_polycule::cBinop_F9UbFMyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gVIcgklg, HV_BINOP_MULTIPLY, 1, m, &cBinop_gVIcgklg_sendMessage);
}

void Heavy_polycule::cBinop_x5SIAMJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_AKNTLWx0_sendMessage);
}

void Heavy_polycule::cCast_8HEdGADr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_6aQfvPOz_sendMessage);
}

void Heavy_polycule::cCast_NT72Oczj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_x5SIAMJh_sendMessage);
}

void Heavy_polycule::cBinop_6sFgKLWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4tUamFjx, HV_BINOP_MULTIPLY, 1, m, &cBinop_4tUamFjx_sendMessage);
}

void Heavy_polycule::cBinop_rP6ZRrw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6sFgKLWy, HV_BINOP_MULTIPLY, 1, m, &cBinop_6sFgKLWy_sendMessage);
}

void Heavy_polycule::cBinop_OdmWq08A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RvXiE4wD, HV_BINOP_ADD, 0, m, &cBinop_RvXiE4wD_sendMessage);
}

void Heavy_polycule::cBinop_nNPauLjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OdmWq08A, HV_BINOP_MULTIPLY, 1, m, &cBinop_OdmWq08A_sendMessage);
}

void Heavy_polycule::cBinop_RvXiE4wD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6sFgKLWy, HV_BINOP_MULTIPLY, 0, m, &cBinop_6sFgKLWy_sendMessage);
}

void Heavy_polycule::cBinop_g6UKIeBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RvXiE4wD, HV_BINOP_ADD, 1, m, &cBinop_RvXiE4wD_sendMessage);
}

void Heavy_polycule::cCast_CEdjMHsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_g6UKIeBD_sendMessage);
}

void Heavy_polycule::cCast_3xdndUNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_rP6ZRrw8_sendMessage);
}

void Heavy_polycule::cCast_KHBNQjpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_nNPauLjB_sendMessage);
}

void Heavy_polycule::cVar_EctSGFui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_VeSQbFES_sendMessage);
}

void Heavy_polycule::cUnop_6cgipBeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_GZhhobVH_sendMessage);
}

void Heavy_polycule::cVar_7H9YyhX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5bYZ6A1w_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_ebGIIkw4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tt9VCBTE_sendMessage);
}

void Heavy_polycule::cBinop_FkiukWLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xatg3L5l, HV_BINOP_MULTIPLY, 1, m, &cBinop_xatg3L5l_sendMessage);
}

void Heavy_polycule::cBinop_8D2MSav8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XGbdzjfD, HV_BINOP_MULTIPLY, 1, m, &cBinop_XGbdzjfD_sendMessage);
}

void Heavy_polycule::cBinop_xatg3L5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gi2tqjb9, HV_BINOP_ADD, 0, m, &cBinop_gi2tqjb9_sendMessage);
}

void Heavy_polycule::cBinop_gi2tqjb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_8D2MSav8_sendMessage);
}

void Heavy_polycule::cBinop_hw50gjbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FkiukWLl_sendMessage);
}

void Heavy_polycule::cBinop_Q2j1jaeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gi2tqjb9, HV_BINOP_ADD, 1, m, &cBinop_gi2tqjb9_sendMessage);
}

void Heavy_polycule::cCast_08zFfQf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Q2j1jaeZ_sendMessage);
}

void Heavy_polycule::cCast_4GQCVGZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_hw50gjbw_sendMessage);
}

void Heavy_polycule::cBinop_3qxZhCIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_QTonaFRn_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_XGbdzjfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e1RMSDlE_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_NI2Q2oPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ORs2JGqb_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_4tUamFjx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_T44yElEo_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_4Myxjjx5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_Y00u9mh7_sendMessage);
}

void Heavy_polycule::cBinop_xpKwmZ35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vL9a4nRD_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_GZhhobVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3qxZhCIB, HV_BINOP_MULTIPLY, 1, m, &cBinop_3qxZhCIB_sendMessage);
}

void Heavy_polycule::cBinop_gVIcgklg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XS5iyhlb_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_Y00u9mh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WOTwvuBu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gR4eKCa4_sendMessage);
}

void Heavy_polycule::cBinop_fShnzF6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hdvNVKj8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_30WAUaEv_sendMessage);
}

void Heavy_polycule::cBinop_vMXcu3BG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Myxjjx5, HV_BINOP_MULTIPLY, 1, m, &cBinop_4Myxjjx5_sendMessage);
}

void Heavy_polycule::cBinop_k6rCCrOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_g2pWcgHy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fehTIaCL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ez8M8jmB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JCfWyoDX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Usj3JcHj_sendMessage);
}

void Heavy_polycule::cMsg_kouEbsCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_vMXcu3BG_sendMessage);
}

void Heavy_polycule::cMsg_9mj57HS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pUlP29M1, HV_BINOP_POW, 0, m, &cBinop_pUlP29M1_sendMessage);
}

void Heavy_polycule::cMsg_A4VE89cJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_k6rCCrOn_sendMessage);
}

void Heavy_polycule::cBinop_pUlP29M1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RPVSr5IQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oilnR04g_sendMessage);
}

void Heavy_polycule::cSend_Uec6xybF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QCyszybr_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_QTonaFRn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LRChYx4n_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_7ZgxpWmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oyqM5JtJ_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_XCIs4h9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FINoPYCW_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_a0NX6AgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_polycule::cCast_oilnR04g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_6cgipBeO_sendMessage);
}

void Heavy_polycule::cCast_RPVSr5IQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Uec6xybF_sendMessage(_c, 0, m);
}

void Heavy_polycule::cCast_L3PlwFKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7H9YyhX8, 0, m, &cVar_7H9YyhX8_sendMessage);
}

void Heavy_polycule::cCast_uewwiyoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1mWQw5eI, 0, m, &cVar_1mWQw5eI_sendMessage);
}

void Heavy_polycule::cCast_fehTIaCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XGbdzjfD, HV_BINOP_MULTIPLY, 0, m, &cBinop_XGbdzjfD_sendMessage);
}

void Heavy_polycule::cCast_ez8M8jmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xpKwmZ35, HV_BINOP_MULTIPLY, 0, m, &cBinop_xpKwmZ35_sendMessage);
}

void Heavy_polycule::cCast_g2pWcgHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gVIcgklg, HV_BINOP_MULTIPLY, 0, m, &cBinop_gVIcgklg_sendMessage);
}

void Heavy_polycule::cCast_JCfWyoDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4tUamFjx, HV_BINOP_MULTIPLY, 0, m, &cBinop_4tUamFjx_sendMessage);
}

void Heavy_polycule::cCast_Usj3JcHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NI2Q2oPZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_NI2Q2oPZ_sendMessage);
}

void Heavy_polycule::cCast_gR4eKCa4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3qxZhCIB, HV_BINOP_MULTIPLY, 0, m, &cBinop_3qxZhCIB_sendMessage);
}

void Heavy_polycule::cCast_WOTwvuBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_a0NX6AgL_sendMessage(_c, 0, m);
}

void Heavy_polycule::cCast_dOF7D9bU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1mWQw5eI, 0, m, &cVar_1mWQw5eI_sendMessage);
}

void Heavy_polycule::cCast_gkqr9BG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7H9YyhX8, 0, m, &cVar_7H9YyhX8_sendMessage);
}

void Heavy_polycule::cCast_hdvNVKj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pUlP29M1, HV_BINOP_POW, 1, m, &cBinop_pUlP29M1_sendMessage);
}

void Heavy_polycule::cCast_30WAUaEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9mj57HS8_sendMessage(_c, 0, m);
}

void Heavy_polycule::cCast_5bYZ6A1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EctSGFui, 0, m, &cVar_EctSGFui_sendMessage);
}

void Heavy_polycule::cCast_tt9VCBTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ACtj0btH, 0, m, &cVar_ACtj0btH_sendMessage);
}

void Heavy_polycule::cCast_eRfzdcxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_3DhoQbrM_sendMessage);
}

void Heavy_polycule::cCast_vrp50c0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_kcVxJgKE_sendMessage);
}

void Heavy_polycule::cCast_z6AQlV6x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7H9YyhX8, 0, m, &cVar_7H9YyhX8_sendMessage);
}

void Heavy_polycule::cCast_9V7hCapE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EctSGFui, 1, m, &cVar_EctSGFui_sendMessage);
}

void Heavy_polycule::cVar_VoOQtFQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_hliilloW_sendMessage);
}

void Heavy_polycule::cMsg_Mpmqkd51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_9e4xL0L3, 0, m, NULL);
}

void Heavy_polycule::cMsg_CcIn2Eja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_nGqTF2lq, 0, m, NULL);
}

void Heavy_polycule::cMsg_7URQ0UUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_KpI4HxA3, 0, m, NULL);
}

void Heavy_polycule::cMsg_20uYitHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_OswWEXrK, 0, m, NULL);
}

void Heavy_polycule::cMsg_gogjVnb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Tc1HbscM, 0, m, NULL);
}

void Heavy_polycule::cBinop_tnjWLZg2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U9CASsdy, HV_BINOP_MULTIPLY, 0, m, &cBinop_U9CASsdy_sendMessage);
}

void Heavy_polycule::cBinop_1sjkqTAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_tnjWLZg2_sendMessage);
}

void Heavy_polycule::cVar_RroKyjkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WvmecrMm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_1sjkqTAB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nWmOfGCq_sendMessage);
}

void Heavy_polycule::cBinop_gGeTmOtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YyyaxPh2, 1, m, &cVar_YyyaxPh2_sendMessage);
}

void Heavy_polycule::cBinop_nIk51eYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_80Jtb1iq, HV_BINOP_MULTIPLY, 1, m, &cBinop_80Jtb1iq_sendMessage);
}

void Heavy_polycule::cVar_ntWgL4QV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_qsQ4GmWj_sendMessage);
}

void Heavy_polycule::cBinop_xdiqb7Ub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wDOTRzCx, HV_BINOP_MULTIPLY, 1, m, &cBinop_wDOTRzCx_sendMessage);
}

void Heavy_polycule::cBinop_zBzYHOch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_xdiqb7Ub_sendMessage);
}

void Heavy_polycule::cMsg_K2R7kAAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_zBzYHOch_sendMessage);
}

void Heavy_polycule::cBinop_gAazLBhB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZAn4Ugp9, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZAn4Ugp9_sendMessage);
}

void Heavy_polycule::cMsg_ujAD6Q9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_gAazLBhB_sendMessage);
}

void Heavy_polycule::cUnop_rhVihPMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_t4FEP91h_sendMessage(_c, 0, m);
}

void Heavy_polycule::cVar_YyyaxPh2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L9rYQuMU_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_RhoTQ84w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MSLowEsR, HV_BINOP_MULTIPLY, 1, m, &cBinop_MSLowEsR_sendMessage);
}

void Heavy_polycule::cMsg_EBHxAA7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_RhoTQ84w_sendMessage);
}

void Heavy_polycule::cMsg_clnapMdx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_McvJelpO_sendMessage);
}

void Heavy_polycule::cSystem_McvJelpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A6GJgRHU, HV_BINOP_DIVIDE, 1, m, &cBinop_A6GJgRHU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oHjuOjbp_sendMessage);
}

void Heavy_polycule::cUnop_LPKXjnFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_RarwKb6E_sendMessage);
}

void Heavy_polycule::cBinop_RarwKb6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A6GJgRHU, HV_BINOP_DIVIDE, 0, m, &cBinop_A6GJgRHU_sendMessage);
}

void Heavy_polycule::cBinop_U9CASsdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ml7vDW4M_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pFkHs7QI_sendMessage);
}

void Heavy_polycule::cBinop_A6GJgRHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U9CASsdy, HV_BINOP_MULTIPLY, 1, m, &cBinop_U9CASsdy_sendMessage);
}

void Heavy_polycule::cMsg_cwSdw3Yw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_LPKXjnFR_sendMessage);
}

void Heavy_polycule::cCast_oHjuOjbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cwSdw3Yw_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_n7SyTzjO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dn0Hr70b, HV_BINOP_MULTIPLY, 1, m, &cBinop_Dn0Hr70b_sendMessage);
}

void Heavy_polycule::cBinop_8GBmIdi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_n7SyTzjO_sendMessage);
}

void Heavy_polycule::cMsg_9Ul7dTfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_8GBmIdi0_sendMessage);
}

void Heavy_polycule::cBinop_Kynn60AW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5cVWvthe_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_qsQ4GmWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_Kynn60AW_sendMessage);
}

void Heavy_polycule::cUnop_VbCBFEdo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_fDtIXjPB_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_RiG46JpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_JNC3vMhX_sendMessage);
}

void Heavy_polycule::cBinop_ZAn4Ugp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7URQ0UUn_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_MSLowEsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CcIn2Eja_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_80Jtb1iq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gogjVnb4_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_Dn0Hr70b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Mpmqkd51_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_JNC3vMhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_CQYIxZ6i_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_wDOTRzCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_20uYitHd_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_WjNuivSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z1vBoEA1_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3H5xEBIZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TzV9MLbl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0KcyQMDT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kpel2lzl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S36iSkEO_sendMessage);
}

void Heavy_polycule::cBinop_4U7sl5k1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RiG46JpJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_RiG46JpJ_sendMessage);
}

void Heavy_polycule::cMsg_5cVWvthe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4U7sl5k1_sendMessage);
}

void Heavy_polycule::cMsg_L9rYQuMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_WjNuivSt_sendMessage);
}

void Heavy_polycule::cSend_CQYIxZ6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9IMH91wU_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_fDtIXjPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YuzfBRAg_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_t4FEP91h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RFVsvOge_sendMessage(_c, 0, m);
}

void Heavy_polycule::cCast_nWmOfGCq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YyyaxPh2, 0, m, &cVar_YyyaxPh2_sendMessage);
}

void Heavy_polycule::cCast_WvmecrMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ntWgL4QV, 0, m, &cVar_ntWgL4QV_sendMessage);
}

void Heavy_polycule::cCast_Nmk0LJfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ntWgL4QV, 1, m, &cVar_ntWgL4QV_sendMessage);
}

void Heavy_polycule::cCast_OOJgFhGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RroKyjkR, 0, m, &cVar_RroKyjkR_sendMessage);
}

void Heavy_polycule::cCast_TzV9MLbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_80Jtb1iq, HV_BINOP_MULTIPLY, 0, m, &cBinop_80Jtb1iq_sendMessage);
}

void Heavy_polycule::cCast_3H5xEBIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZAn4Ugp9, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZAn4Ugp9_sendMessage);
}

void Heavy_polycule::cCast_S36iSkEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dn0Hr70b, HV_BINOP_MULTIPLY, 0, m, &cBinop_Dn0Hr70b_sendMessage);
}

void Heavy_polycule::cCast_0KcyQMDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wDOTRzCx, HV_BINOP_MULTIPLY, 0, m, &cBinop_wDOTRzCx_sendMessage);
}

void Heavy_polycule::cCast_z1vBoEA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_polycule::cCast_kpel2lzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MSLowEsR, HV_BINOP_MULTIPLY, 0, m, &cBinop_MSLowEsR_sendMessage);
}

void Heavy_polycule::cCast_Ml7vDW4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_rhVihPMf_sendMessage);
}

void Heavy_polycule::cCast_pFkHs7QI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_VbCBFEdo_sendMessage);
}

void Heavy_polycule::cVar_ZTvcqTk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 275.0f, 0, m, &cBinop_jsZtCdz4_sendMessage);
}

void Heavy_polycule::cVar_yxencfLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_ZNObdoZ3_sendMessage);
}

void Heavy_polycule::cVar_bxFajgMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1400.0f, 0, m, &cBinop_5PUaP4ak_sendMessage);
}

void Heavy_polycule::cMsg_mT8BPEYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8CzXJsUm, 0, m, NULL);
}

void Heavy_polycule::cMsg_SdRzuRjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2aqS4R4C, 0, m, NULL);
}

void Heavy_polycule::cMsg_61xN53cU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_L6QI2sxz, 0, m, NULL);
}

void Heavy_polycule::cMsg_rrK2whjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_c35xVqS6, 0, m, NULL);
}

void Heavy_polycule::cMsg_dee55IeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_EGJnCRU7, 0, m, NULL);
}

void Heavy_polycule::cVar_I8Dzr7p9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_kI4scJ29_sendMessage);
}

void Heavy_polycule::cVar_5ZndH7bp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kca84uFz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_FgSvGsyx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dP4ZY4jH_sendMessage);
}

void Heavy_polycule::cUnop_LaANLhmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_g8CgzAX8_sendMessage(_c, 0, m);
}

void Heavy_polycule::cUnop_yGNxqQ7v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZCuinEPU_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_S2cIeSM1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DP2qh9KM, HV_BINOP_MULTIPLY, 1, m, &cBinop_DP2qh9KM_sendMessage);
}

void Heavy_polycule::cBinop_mJoLrax2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_S2cIeSM1_sendMessage);
}

void Heavy_polycule::cMsg_icYHSeEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_mJoLrax2_sendMessage);
}

void Heavy_polycule::cBinop_VawTUqqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qRciwK3D, 1, m, &cVar_qRciwK3D_sendMessage);
}

void Heavy_polycule::cVar_qRciwK3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YhDuXJrL_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_5FdnEC8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y9BuMGNa, HV_BINOP_MULTIPLY, 1, m, &cBinop_y9BuMGNa_sendMessage);
}

void Heavy_polycule::cMsg_d5eWVaV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_5FdnEC8v_sendMessage);
}

void Heavy_polycule::cUnop_JJyf1ZwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_LdKTVRKe_sendMessage);
}

void Heavy_polycule::cMsg_lBavK4Yr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UbsAhvsS_sendMessage);
}

void Heavy_polycule::cSystem_UbsAhvsS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iazfOgiI, HV_BINOP_DIVIDE, 1, m, &cBinop_iazfOgiI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PMTReij0_sendMessage);
}

void Heavy_polycule::cBinop_MB7oZ5bd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cVnJyltM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HKHdvDFW_sendMessage);
}

void Heavy_polycule::cBinop_LdKTVRKe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iazfOgiI, HV_BINOP_DIVIDE, 0, m, &cBinop_iazfOgiI_sendMessage);
}

void Heavy_polycule::cBinop_iazfOgiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MB7oZ5bd, HV_BINOP_MULTIPLY, 1, m, &cBinop_MB7oZ5bd_sendMessage);
}

void Heavy_polycule::cMsg_NsGEkfTi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_JJyf1ZwV_sendMessage);
}

void Heavy_polycule::cCast_PMTReij0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NsGEkfTi_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_lHPC7HBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8XlyzY0b, HV_BINOP_MULTIPLY, 1, m, &cBinop_8XlyzY0b_sendMessage);
}

void Heavy_polycule::cBinop_rB3X0Ovo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MB7oZ5bd, HV_BINOP_MULTIPLY, 0, m, &cBinop_MB7oZ5bd_sendMessage);
}

void Heavy_polycule::cBinop_FgSvGsyx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_rB3X0Ovo_sendMessage);
}

void Heavy_polycule::cBinop_ezCNSIwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R9efVThn, HV_BINOP_MULTIPLY, 1, m, &cBinop_R9efVThn_sendMessage);
}

void Heavy_polycule::cMsg_fJ9HOhnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ezCNSIwZ_sendMessage);
}

void Heavy_polycule::cBinop_PjBA4mnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PoAOO1tc_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_kI4scJ29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_PjBA4mnx_sendMessage);
}

void Heavy_polycule::cBinop_7w0f5cg6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2ghouWSh, HV_BINOP_MULTIPLY, 1, m, &cBinop_2ghouWSh_sendMessage);
}

void Heavy_polycule::cBinop_cxI7AChy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_7w0f5cg6_sendMessage);
}

void Heavy_polycule::cMsg_pn63Ncj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_cxI7AChy_sendMessage);
}

void Heavy_polycule::cBinop_MACiWWpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_h2hY5WMk_sendMessage);
}

void Heavy_polycule::cBinop_8XlyzY0b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SdRzuRjs_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_DP2qh9KM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_61xN53cU_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_y9BuMGNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rrK2whjm_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_R9efVThn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mT8BPEYA_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_2ghouWSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dee55IeD_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_h2hY5WMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lEPZXwwr_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_tZIDYP71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mzyIhvEr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qUYivrPn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QT9m1cpX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BBj65Enq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dNxDjF1h_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CWArySrj_sendMessage);
}

void Heavy_polycule::cBinop_oXidgDvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MACiWWpo, HV_BINOP_MULTIPLY, 1, m, &cBinop_MACiWWpo_sendMessage);
}

void Heavy_polycule::cMsg_YhDuXJrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tZIDYP71_sendMessage);
}

void Heavy_polycule::cMsg_PoAOO1tc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_oXidgDvd_sendMessage);
}

void Heavy_polycule::cSend_g8CgzAX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Qgl5KGCK_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_lEPZXwwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AxBMWFrv_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_ZCuinEPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_n1hRzgVZ_sendMessage(_c, 0, m);
}

void Heavy_polycule::cCast_BBj65Enq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DP2qh9KM, HV_BINOP_MULTIPLY, 0, m, &cBinop_DP2qh9KM_sendMessage);
}

void Heavy_polycule::cCast_qUYivrPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R9efVThn, HV_BINOP_MULTIPLY, 0, m, &cBinop_R9efVThn_sendMessage);
}

void Heavy_polycule::cCast_mzyIhvEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_polycule::cCast_CWArySrj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2ghouWSh, HV_BINOP_MULTIPLY, 0, m, &cBinop_2ghouWSh_sendMessage);
}

void Heavy_polycule::cCast_QT9m1cpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8XlyzY0b, HV_BINOP_MULTIPLY, 0, m, &cBinop_8XlyzY0b_sendMessage);
}

void Heavy_polycule::cCast_dNxDjF1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y9BuMGNa, HV_BINOP_MULTIPLY, 0, m, &cBinop_y9BuMGNa_sendMessage);
}

void Heavy_polycule::cCast_ByPLTu9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5ZndH7bp, 0, m, &cVar_5ZndH7bp_sendMessage);
}

void Heavy_polycule::cCast_VrsNn9rL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I8Dzr7p9, 1, m, &cVar_I8Dzr7p9_sendMessage);
}

void Heavy_polycule::cCast_cVnJyltM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_LaANLhmR_sendMessage);
}

void Heavy_polycule::cCast_HKHdvDFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_yGNxqQ7v_sendMessage);
}

void Heavy_polycule::cCast_dP4ZY4jH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qRciwK3D, 0, m, &cVar_qRciwK3D_sendMessage);
}

void Heavy_polycule::cCast_Kca84uFz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I8Dzr7p9, 0, m, &cVar_I8Dzr7p9_sendMessage);
}

void Heavy_polycule::cMsg_e3mTYVPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_hZX6p11G, 0, m, NULL);
}

void Heavy_polycule::cBinop_sLXKk8mb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JGlLEteq, HV_BINOP_MULTIPLY, 0, m, &cBinop_JGlLEteq_sendMessage);
}

void Heavy_polycule::cBinop_EGR7VkBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_sLXKk8mb_sendMessage);
}

void Heavy_polycule::cBinop_Gls0TVN8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zJXHPS2e, HV_BINOP_MULTIPLY, 1, m, &cBinop_zJXHPS2e_sendMessage);
}

void Heavy_polycule::cBinop_zUy81bzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Gls0TVN8_sendMessage);
}

void Heavy_polycule::cUnop_Q9OJG8Bu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xYkzmJAe_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_nl7thVYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FsQFvinu, HV_BINOP_MULTIPLY, 1, m, &cBinop_FsQFvinu_sendMessage);
}

void Heavy_polycule::cMsg_ePf1i2kD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_nl7thVYi_sendMessage);
}

void Heavy_polycule::cVar_oYZ1FsTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cz3GuwZ9_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_EGR7VkBQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zYLCj9nE_sendMessage);
}

void Heavy_polycule::cMsg_0GGW1BfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LbJrDoo6_sendMessage);
}

void Heavy_polycule::cSystem_LbJrDoo6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4cscjnoz, HV_BINOP_DIVIDE, 1, m, &cBinop_4cscjnoz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kg2Ck6ti_sendMessage);
}

void Heavy_polycule::cUnop_AFzJ9h8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_D2BKVp2l_sendMessage);
}

void Heavy_polycule::cBinop_JGlLEteq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_La00EYvP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BH0Va8pU_sendMessage);
}

void Heavy_polycule::cBinop_D2BKVp2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4cscjnoz, HV_BINOP_DIVIDE, 0, m, &cBinop_4cscjnoz_sendMessage);
}

void Heavy_polycule::cBinop_4cscjnoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JGlLEteq, HV_BINOP_MULTIPLY, 1, m, &cBinop_JGlLEteq_sendMessage);
}

void Heavy_polycule::cMsg_E7YlEsBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_AFzJ9h8w_sendMessage);
}

void Heavy_polycule::cCast_kg2Ck6ti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E7YlEsBS_sendMessage(_c, 0, m);
}

void Heavy_polycule::cVar_rRdNVMw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_hDcilXtX_sendMessage);
}

void Heavy_polycule::cBinop_HXOVfiuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RIZRGPuA, HV_BINOP_MULTIPLY, 1, m, &cBinop_RIZRGPuA_sendMessage);
}

void Heavy_polycule::cBinop_WWN6yWNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_HXOVfiuK_sendMessage);
}

void Heavy_polycule::cUnop_NthB2FSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_abbMA4qQ_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_MRZOO6yP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2cbZCCNK, 1, m, &cVar_2cbZCCNK_sendMessage);
}

void Heavy_polycule::cBinop_YCUjzOVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wkv9TcUD_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_hDcilXtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_YCUjzOVs_sendMessage);
}

void Heavy_polycule::cVar_2cbZCCNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NTEuAUjT_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_FkUtYNI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kM3GwGSd, HV_BINOP_MULTIPLY, 1, m, &cBinop_kM3GwGSd_sendMessage);
}

void Heavy_polycule::cBinop_j3ZZjNbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2RdC4ltE, HV_BINOP_MULTIPLY, 1, m, &cBinop_2RdC4ltE_sendMessage);
}

void Heavy_polycule::cBinop_ACgj3xUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_j3ZZjNbF_sendMessage);
}

void Heavy_polycule::cBinop_tGsmIjqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_ZRjLDUtw_sendMessage);
}

void Heavy_polycule::cBinop_2RdC4ltE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lmrOE1mD_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_FsQFvinu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e3mTYVPI_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_RIZRGPuA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yFdjtG68_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_zJXHPS2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3atxc0UZ_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_ZRjLDUtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Mm7luv3T_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_kM3GwGSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bWgH90Yt_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_5LqrTRRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ztrm8Z4J_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tKYmqA3V_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_48SuMUGW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TjXjUBcH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bmOYzIrs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_L7F3vP1m_sendMessage);
}

void Heavy_polycule::cBinop_asJNCnKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tGsmIjqt, HV_BINOP_MULTIPLY, 1, m, &cBinop_tGsmIjqt_sendMessage);
}

void Heavy_polycule::cMsg_NTEuAUjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5LqrTRRN_sendMessage);
}

void Heavy_polycule::cMsg_wkv9TcUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_asJNCnKp_sendMessage);
}

void Heavy_polycule::cSend_xYkzmJAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mH83Twnq_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_Mm7luv3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mqX08En5_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_abbMA4qQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xXry9poh_sendMessage(_c, 0, m);
}

void Heavy_polycule::cCast_36UMch34_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rRdNVMw8, 1, m, &cVar_rRdNVMw8_sendMessage);
}

void Heavy_polycule::cCast_k2fRJtaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oYZ1FsTQ, 0, m, &cVar_oYZ1FsTQ_sendMessage);
}

void Heavy_polycule::cCast_L7F3vP1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2RdC4ltE, HV_BINOP_MULTIPLY, 0, m, &cBinop_2RdC4ltE_sendMessage);
}

void Heavy_polycule::cCast_Ztrm8Z4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_polycule::cCast_tKYmqA3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FsQFvinu, HV_BINOP_MULTIPLY, 0, m, &cBinop_FsQFvinu_sendMessage);
}

void Heavy_polycule::cCast_bmOYzIrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zJXHPS2e, HV_BINOP_MULTIPLY, 0, m, &cBinop_zJXHPS2e_sendMessage);
}

void Heavy_polycule::cCast_TjXjUBcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RIZRGPuA, HV_BINOP_MULTIPLY, 0, m, &cBinop_RIZRGPuA_sendMessage);
}

void Heavy_polycule::cCast_48SuMUGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kM3GwGSd, HV_BINOP_MULTIPLY, 0, m, &cBinop_kM3GwGSd_sendMessage);
}

void Heavy_polycule::cCast_zYLCj9nE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2cbZCCNK, 0, m, &cVar_2cbZCCNK_sendMessage);
}

void Heavy_polycule::cCast_Cz3GuwZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rRdNVMw8, 0, m, &cVar_rRdNVMw8_sendMessage);
}

void Heavy_polycule::cCast_BH0Va8pU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Q9OJG8Bu_sendMessage);
}

void Heavy_polycule::cCast_La00EYvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_NthB2FSt_sendMessage);
}

void Heavy_polycule::cMsg_lmrOE1mD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wkTpzcvQ, 0, m, NULL);
}

void Heavy_polycule::cMsg_3atxc0UZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_V183eFbc, 0, m, NULL);
}

void Heavy_polycule::cMsg_yFdjtG68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_6nWJNpwK, 0, m, NULL);
}

void Heavy_polycule::cMsg_bWgH90Yt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_aujPyI3o, 0, m, NULL);
}

void Heavy_polycule::cVar_j76N8V0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_32XBK37Z, HV_BINOP_SUBTRACT, 0, m, &cBinop_32XBK37Z_sendMessage);
}

void Heavy_polycule::cVar_HCYGsdHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dHuDnzxh, HV_BINOP_ADD, 1, m, &cBinop_dHuDnzxh_sendMessage);
}

void Heavy_polycule::cVar_KRne8x6H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_osuPeVaE_sendMessage);
}

void Heavy_polycule::cVar_qUvNarj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CEpoV4ys, m);
}

void Heavy_polycule::cVar_h0mjgQhB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8Vx7XtOF, HV_BINOP_ADD, 1, m, &cBinop_8Vx7XtOF_sendMessage);
}

void Heavy_polycule::cVar_tiRp9ue3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 36.0f, 0, m, &cBinop_05NYFyG8_sendMessage);
}

void Heavy_polycule::cVar_ebO7RRGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XwToN5DN, HV_BINOP_SUBTRACT, 0, m, &cBinop_XwToN5DN_sendMessage);
}

void Heavy_polycule::cMsg_m4ukc4db_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0ufmkMY6, 0, m, NULL);
}

void Heavy_polycule::cMsg_W7TMMbMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_zV1pENor, 0, m, NULL);
}

void Heavy_polycule::cMsg_YLIQKlPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ig1MqdXn, 0, m, NULL);
}

void Heavy_polycule::cUnop_lZTumiiu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dqQlqJgO_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_kPgmCLGF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6FE5Ur2O_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_2aqkGwsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W2F1tf6l, HV_BINOP_MULTIPLY, 1, m, &cBinop_W2F1tf6l_sendMessage);
}

void Heavy_polycule::cMsg_6FE5Ur2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_2aqkGwsR_sendMessage);
}

void Heavy_polycule::cVar_J7yIm0MD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 24.0f, 0, m, &cBinop_R16pcd3H_sendMessage);
}

void Heavy_polycule::cBinop_QfgxnE0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Gdd6m9qu_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_F8fTk35X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_QfgxnE0l_sendMessage);
}

void Heavy_polycule::cBinop_SKWb7oAx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yrgzoglk, 1, m, &cVar_Yrgzoglk_sendMessage);
}

void Heavy_polycule::cBinop_HjQdwr65_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_SKWb7oAx_sendMessage);
}

void Heavy_polycule::cBinop_S2JZ2UP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 40.0f, 0, m, &cBinop_ckQbh13f_sendMessage);
}

void Heavy_polycule::cBinop_R16pcd3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -24.0f, 0, m, &cBinop_S2JZ2UP8_sendMessage);
}

void Heavy_polycule::cVar_Yrgzoglk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3vObl7xo_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_yyTXlP7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LQWbGX2T, HV_BINOP_MULTIPLY, 1, m, &cBinop_LQWbGX2T_sendMessage);
}

void Heavy_polycule::cBinop_tuumuoxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e5EUbfw9, HV_BINOP_MULTIPLY, 1, m, &cBinop_e5EUbfw9_sendMessage);
}

void Heavy_polycule::cBinop_Ii3ZVtYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ec8b7Lhl, HV_BINOP_MULTIPLY, 0, m, &cBinop_ec8b7Lhl_sendMessage);
}

void Heavy_polycule::cBinop_D2VjpSQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_Ii3ZVtYu_sendMessage);
}

void Heavy_polycule::cBinop_jomJUXmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_anHedki1, HV_BINOP_MULTIPLY, 1, m, &cBinop_anHedki1_sendMessage);
}

void Heavy_polycule::cBinop_IzZJGVQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XgWt3e53_sendMessage(_c, 0, m);
}

void Heavy_polycule::cMsg_XgWt3e53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_jomJUXmJ_sendMessage);
}

void Heavy_polycule::cVar_CZ74PW29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_F8fTk35X_sendMessage);
}

void Heavy_polycule::cBinop_QtFJLpTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TcYdwwB8_sendMessage);
}

void Heavy_polycule::cBinop_TcYdwwB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8N37bZab, HV_BINOP_MULTIPLY, 1, m, &cBinop_8N37bZab_sendMessage);
}

void Heavy_polycule::cMsg_opyukWPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wD4HL6Uw_sendMessage);
}

void Heavy_polycule::cSystem_wD4HL6Uw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TpyysmKi, HV_BINOP_DIVIDE, 1, m, &cBinop_TpyysmKi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xBEjogG9_sendMessage);
}

void Heavy_polycule::cUnop_onyBmimv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_hKrFyPvG_sendMessage);
}

void Heavy_polycule::cBinop_ec8b7Lhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qRFkg4Gi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lE7wBAEf_sendMessage);
}

void Heavy_polycule::cBinop_hKrFyPvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TpyysmKi, HV_BINOP_DIVIDE, 0, m, &cBinop_TpyysmKi_sendMessage);
}

void Heavy_polycule::cBinop_TpyysmKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ec8b7Lhl, HV_BINOP_MULTIPLY, 1, m, &cBinop_ec8b7Lhl_sendMessage);
}

void Heavy_polycule::cMsg_G8cOjACX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_onyBmimv_sendMessage);
}

void Heavy_polycule::cCast_xBEjogG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G8cOjACX_sendMessage(_c, 0, m);
}

void Heavy_polycule::cVar_3yo146eR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8w0siukR_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_D2VjpSQb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wgh4oSOl_sendMessage);
}

void Heavy_polycule::cUnop_ye9zohgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_TWFjXXmP_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_LEG3jHU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_fw5Fqe0W_sendMessage);
}

void Heavy_polycule::cBinop_anHedki1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m4ukc4db_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_e5EUbfw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8JlJojHw_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_LQWbGX2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G1TkLY3Q_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_W2F1tf6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YLIQKlPP_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_fw5Fqe0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8yCAl6kj_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_8N37bZab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W7TMMbMl_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_x8oWp35l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LEG3jHU4, HV_BINOP_MULTIPLY, 1, m, &cBinop_LEG3jHU4_sendMessage);
}

void Heavy_polycule::cBinop_M9WNUhzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kvgsmrkq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xzQ39nrh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_k9nXxSgg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kpB3VX0Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qAdS2S44_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lBZcCH3N_sendMessage);
}

void Heavy_polycule::cBinop_ckQbh13f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1zF3lEX7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JWAbMC2U_sendMessage);
}

void Heavy_polycule::cMsg_2zQi4RLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sPT8t41g, HV_BINOP_POW, 0, m, &cBinop_sPT8t41g_sendMessage);
}

void Heavy_polycule::cMsg_Gdd6m9qu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_x8oWp35l_sendMessage);
}

void Heavy_polycule::cMsg_3vObl7xo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_M9WNUhzg_sendMessage);
}

void Heavy_polycule::cBinop_sPT8t41g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KHQ80rZg_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_KHQ80rZg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nTVwhylI_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_8yCAl6kj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IIqd3GpY_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_dqQlqJgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3QNuqrQ6_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_TWFjXXmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Kat1M39k_sendMessage(_c, 0, m);
}

void Heavy_polycule::cCast_RqlvjwvO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3yo146eR, 0, m, &cVar_3yo146eR_sendMessage);
}

void Heavy_polycule::cCast_Vfyk1Oft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J7yIm0MD, 0, m, &cVar_J7yIm0MD_sendMessage);
}

void Heavy_polycule::cCast_lE7wBAEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_lZTumiiu_sendMessage);
}

void Heavy_polycule::cCast_qRFkg4Gi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_ye9zohgj_sendMessage);
}

void Heavy_polycule::cCast_Wgh4oSOl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yrgzoglk, 0, m, &cVar_Yrgzoglk_sendMessage);
}

void Heavy_polycule::cCast_8w0siukR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CZ74PW29, 0, m, &cVar_CZ74PW29_sendMessage);
}

void Heavy_polycule::cCast_JWAbMC2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2zQi4RLN_sendMessage(_c, 0, m);
}

void Heavy_polycule::cCast_1zF3lEX7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sPT8t41g, HV_BINOP_POW, 1, m, &cBinop_sPT8t41g_sendMessage);
}

void Heavy_polycule::cCast_d86G7Fu5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3yo146eR, 0, m, &cVar_3yo146eR_sendMessage);
}

void Heavy_polycule::cCast_qAa5cvO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J7yIm0MD, 0, m, &cVar_J7yIm0MD_sendMessage);
}

void Heavy_polycule::cCast_PPoC9Ir0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3yo146eR, 0, m, &cVar_3yo146eR_sendMessage);
}

void Heavy_polycule::cCast_zdyJU3qr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CZ74PW29, 1, m, &cVar_CZ74PW29_sendMessage);
}

void Heavy_polycule::cCast_lBZcCH3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8N37bZab, HV_BINOP_MULTIPLY, 0, m, &cBinop_8N37bZab_sendMessage);
}

void Heavy_polycule::cCast_kvgsmrkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_polycule::cCast_k9nXxSgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LQWbGX2T, HV_BINOP_MULTIPLY, 0, m, &cBinop_LQWbGX2T_sendMessage);
}

void Heavy_polycule::cCast_qAdS2S44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e5EUbfw9, HV_BINOP_MULTIPLY, 0, m, &cBinop_e5EUbfw9_sendMessage);
}

void Heavy_polycule::cCast_kpB3VX0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W2F1tf6l, HV_BINOP_MULTIPLY, 0, m, &cBinop_W2F1tf6l_sendMessage);
}

void Heavy_polycule::cCast_xzQ39nrh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_anHedki1, HV_BINOP_MULTIPLY, 0, m, &cBinop_anHedki1_sendMessage);
}

void Heavy_polycule::cMsg_G1TkLY3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5sbSW92o, 0, m, NULL);
}

void Heavy_polycule::cMsg_8JlJojHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dEacS5S5, 0, m, NULL);
}

void Heavy_polycule::cMsg_R4DUtnB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ULIdzvfl, 0, m, NULL);
}

void Heavy_polycule::cMsg_7TQBqTM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ollV2Kg6, 0, m, NULL);
}

void Heavy_polycule::cMsg_UnKx07L6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_h2rTC68R, 0, m, NULL);
}

void Heavy_polycule::cMsg_jcVtsOim_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_4LxtWRrK, 0, m, NULL);
}

void Heavy_polycule::cBinop_pyyD5enJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n5wAL7E1, 1, m, &cVar_n5wAL7E1_sendMessage);
}

void Heavy_polycule::cBinop_LR7qRyJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MOQvxTDu, HV_BINOP_MULTIPLY, 1, m, &cBinop_MOQvxTDu_sendMessage);
}

void Heavy_polycule::cBinop_jK5a28cz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_LR7qRyJQ_sendMessage);
}

void Heavy_polycule::cMsg_jI0sKwwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_jK5a28cz_sendMessage);
}

void Heavy_polycule::cBinop_awubPIHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a5QmDK2I, HV_BINOP_MULTIPLY, 0, m, &cBinop_a5QmDK2I_sendMessage);
}

void Heavy_polycule::cBinop_yyclLtnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_awubPIHt_sendMessage);
}

void Heavy_polycule::cBinop_im2IeI35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IyAlHXJX, HV_BINOP_MULTIPLY, 1, m, &cBinop_IyAlHXJX_sendMessage);
}

void Heavy_polycule::cMsg_zSOSWBfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_im2IeI35_sendMessage);
}

void Heavy_polycule::cBinop_ueY3ByoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QnXCXKcy, HV_BINOP_MULTIPLY, 1, m, &cBinop_QnXCXKcy_sendMessage);
}

void Heavy_polycule::cBinop_RFpayBpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_ueY3ByoX_sendMessage);
}

void Heavy_polycule::cMsg_TQ9009B4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_RFpayBpm_sendMessage);
}

void Heavy_polycule::cBinop_cMc0F9uF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PpHVlJi5, HV_BINOP_MULTIPLY, 1, m, &cBinop_PpHVlJi5_sendMessage);
}

void Heavy_polycule::cUnop_jmF2rwFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KSksH59S_sendMessage(_c, 0, m);
}

void Heavy_polycule::cVar_dRKZ5BG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jRioezKP_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_yyclLtnu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_03s8fgfP_sendMessage);
}

void Heavy_polycule::cBinop_va5RHXWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kDkw0RCD_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_Gt0TvWFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_va5RHXWr_sendMessage);
}

void Heavy_polycule::cBinop_lEj7sEZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p4uBiqjt, HV_BINOP_MULTIPLY, 1, m, &cBinop_p4uBiqjt_sendMessage);
}

void Heavy_polycule::cMsg_StYlJVoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_lEj7sEZM_sendMessage);
}

void Heavy_polycule::cUnop_ohdczAbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lEGmvfjk_sendMessage(_c, 0, m);
}

void Heavy_polycule::cMsg_9fs6SobJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RSDRoNHt_sendMessage);
}

void Heavy_polycule::cSystem_RSDRoNHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fLQneWkK, HV_BINOP_DIVIDE, 1, m, &cBinop_fLQneWkK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gFi2vKF9_sendMessage);
}

void Heavy_polycule::cUnop_rmu1hnn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_4rtOBCLG_sendMessage);
}

void Heavy_polycule::cBinop_a5QmDK2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NIYDXqj2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xIVpJlvV_sendMessage);
}

void Heavy_polycule::cBinop_4rtOBCLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fLQneWkK, HV_BINOP_DIVIDE, 0, m, &cBinop_fLQneWkK_sendMessage);
}

void Heavy_polycule::cBinop_fLQneWkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a5QmDK2I, HV_BINOP_MULTIPLY, 1, m, &cBinop_a5QmDK2I_sendMessage);
}

void Heavy_polycule::cMsg_AdAfoBwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_rmu1hnn2_sendMessage);
}

void Heavy_polycule::cCast_gFi2vKF9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AdAfoBwz_sendMessage(_c, 0, m);
}

void Heavy_polycule::cVar_a67gk6IJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_Gt0TvWFd_sendMessage);
}

void Heavy_polycule::cVar_n5wAL7E1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_07hjlwI6_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_IyAlHXJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UnKx07L6_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_p4uBiqjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M3WiOrko_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_MOQvxTDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7TQBqTM0_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_QnXCXKcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jcVtsOim_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_PpHVlJi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R4DUtnB3_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_I15Z20rf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_fjvu92z0_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_KvZGPGWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_I15Z20rf_sendMessage);
}

void Heavy_polycule::cBinop_YPQbxiVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wCk1AQ3S_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VuTAmyqw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6Bsnhcyy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qdcA5HGR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rwkhiiiK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HoQpL3jr_sendMessage);
}

void Heavy_polycule::cBinop_xAgZ2bzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KvZGPGWE, HV_BINOP_MULTIPLY, 1, m, &cBinop_KvZGPGWE_sendMessage);
}

void Heavy_polycule::cMsg_07hjlwI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YPQbxiVY_sendMessage);
}

void Heavy_polycule::cMsg_kDkw0RCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xAgZ2bzE_sendMessage);
}

void Heavy_polycule::cSend_lEGmvfjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_C0bhJVHm_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_KSksH59S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yJSwzRvy_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_fjvu92z0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_p3CzG4Fj_sendMessage(_c, 0, m);
}

void Heavy_polycule::cCast_jRioezKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a67gk6IJ, 0, m, &cVar_a67gk6IJ_sendMessage);
}

void Heavy_polycule::cCast_03s8fgfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n5wAL7E1, 0, m, &cVar_n5wAL7E1_sendMessage);
}

void Heavy_polycule::cCast_NIYDXqj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_ohdczAbR_sendMessage);
}

void Heavy_polycule::cCast_xIVpJlvV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_jmF2rwFD_sendMessage);
}

void Heavy_polycule::cCast_1KTvXhOZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dRKZ5BG3, 0, m, &cVar_dRKZ5BG3_sendMessage);
}

void Heavy_polycule::cCast_A6qphS88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a67gk6IJ, 1, m, &cVar_a67gk6IJ_sendMessage);
}

void Heavy_polycule::cCast_HoQpL3jr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MOQvxTDu, HV_BINOP_MULTIPLY, 0, m, &cBinop_MOQvxTDu_sendMessage);
}

void Heavy_polycule::cCast_qdcA5HGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QnXCXKcy, HV_BINOP_MULTIPLY, 0, m, &cBinop_QnXCXKcy_sendMessage);
}

void Heavy_polycule::cCast_6Bsnhcyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PpHVlJi5, HV_BINOP_MULTIPLY, 0, m, &cBinop_PpHVlJi5_sendMessage);
}

void Heavy_polycule::cCast_rwkhiiiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IyAlHXJX, HV_BINOP_MULTIPLY, 0, m, &cBinop_IyAlHXJX_sendMessage);
}

void Heavy_polycule::cCast_VuTAmyqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p4uBiqjt, HV_BINOP_MULTIPLY, 0, m, &cBinop_p4uBiqjt_sendMessage);
}

void Heavy_polycule::cCast_wCk1AQ3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_polycule::cMsg_M3WiOrko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5uipgrk8, 0, m, NULL);
}

void Heavy_polycule::cVar_kFaIg4s4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dHuDnzxh, HV_BINOP_ADD, 0, m, &cBinop_dHuDnzxh_sendMessage);
}

void Heavy_polycule::cMsg_9b47s6E6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mSP6osrT, 0, m, NULL);
}

void Heavy_polycule::cMsg_5suEOoJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_7fHdDRHo, 0, m, NULL);
}

void Heavy_polycule::cMsg_Ut76ehrp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_tfawjeIt, 0, m, NULL);
}

void Heavy_polycule::cMsg_itXrCo38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_853HbX5T, 0, m, NULL);
}

void Heavy_polycule::cBinop_aZC6PgV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W6zj9iZ9, HV_BINOP_MULTIPLY, 1, m, &cBinop_W6zj9iZ9_sendMessage);
}

void Heavy_polycule::cMsg_pfBuVoXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_aZC6PgV2_sendMessage);
}

void Heavy_polycule::cMsg_abHLbL3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7KclUbIu_sendMessage);
}

void Heavy_polycule::cSystem_7KclUbIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YjxtLSy7, HV_BINOP_DIVIDE, 1, m, &cBinop_YjxtLSy7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SPwrKFOP_sendMessage);
}

void Heavy_polycule::cUnop_ZnCzVpSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_2wKygA5e_sendMessage);
}

void Heavy_polycule::cBinop_Uf55ORtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oHQfWrzN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GKEVE3xV_sendMessage);
}

void Heavy_polycule::cBinop_2wKygA5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YjxtLSy7, HV_BINOP_DIVIDE, 0, m, &cBinop_YjxtLSy7_sendMessage);
}

void Heavy_polycule::cBinop_YjxtLSy7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Uf55ORtn, HV_BINOP_MULTIPLY, 1, m, &cBinop_Uf55ORtn_sendMessage);
}

void Heavy_polycule::cMsg_hRlc1cBl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_ZnCzVpSJ_sendMessage);
}

void Heavy_polycule::cCast_SPwrKFOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hRlc1cBl_sendMessage(_c, 0, m);
}

void Heavy_polycule::cVar_dypgIm5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_Iy9haA66_sendMessage);
}

void Heavy_polycule::cBinop_NnaUs8nj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ScmL81if, HV_BINOP_MULTIPLY, 1, m, &cBinop_ScmL81if_sendMessage);
}

void Heavy_polycule::cMsg_uDyKE03O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_NnaUs8nj_sendMessage);
}

void Heavy_polycule::cBinop_RVuUTO7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Uf55ORtn, HV_BINOP_MULTIPLY, 0, m, &cBinop_Uf55ORtn_sendMessage);
}

void Heavy_polycule::cBinop_JDp6UCXi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_RVuUTO7J_sendMessage);
}

void Heavy_polycule::cBinop_9VbC1k2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_juz5HF1J, HV_BINOP_MULTIPLY, 1, m, &cBinop_juz5HF1J_sendMessage);
}

void Heavy_polycule::cBinop_upg3OvfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_9VbC1k2g_sendMessage);
}

void Heavy_polycule::cMsg_bqwyHudi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_upg3OvfG_sendMessage);
}

void Heavy_polycule::cBinop_bj1yq9DT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f9BZsw4y_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_Iy9haA66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_bj1yq9DT_sendMessage);
}

void Heavy_polycule::cBinop_PwdnFuTh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SbkGaTKJ, 1, m, &cVar_SbkGaTKJ_sendMessage);
}

void Heavy_polycule::cVar_SbkGaTKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_759JmSPE_sendMessage(_c, 0, m);
}

void Heavy_polycule::cUnop_9bDA4EwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DOpaPyJQ_sendMessage(_c, 0, m);
}

void Heavy_polycule::cUnop_cubK1t29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7OIzZwCN_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_4TeKvnBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OfopRk2a, HV_BINOP_MULTIPLY, 1, m, &cBinop_OfopRk2a_sendMessage);
}

void Heavy_polycule::cVar_u5FS8vlw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IdI6YWX1_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_JDp6UCXi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vXN8e4Cs_sendMessage);
}

void Heavy_polycule::cBinop_FsO7FWjN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WpfpMcYB, HV_BINOP_MULTIPLY, 1, m, &cBinop_WpfpMcYB_sendMessage);
}

void Heavy_polycule::cBinop_5LkZF0lE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_FsO7FWjN_sendMessage);
}

void Heavy_polycule::cMsg_RhxdaEgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_5LkZF0lE_sendMessage);
}

void Heavy_polycule::cBinop_fTm7UCwJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Oje0xj7y_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_WpfpMcYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_itXrCo38_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_OfopRk2a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ekn87GW7_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_leBbH8Se_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_fTm7UCwJ_sendMessage);
}

void Heavy_polycule::cBinop_ScmL81if_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ut76ehrp_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_W6zj9iZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5suEOoJA_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_juz5HF1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9b47s6E6_sendMessage(_c, 0, m);
}

void Heavy_polycule::cBinop_jxMIO2sd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TCh30rhx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bNt6UR78_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yLwMMboY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kmyTbYum_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4ob5Fn7R_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7f26ysai_sendMessage);
}

void Heavy_polycule::cBinop_WTOufy7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_leBbH8Se, HV_BINOP_MULTIPLY, 1, m, &cBinop_leBbH8Se_sendMessage);
}

void Heavy_polycule::cMsg_f9BZsw4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_WTOufy7x_sendMessage);
}

void Heavy_polycule::cMsg_759JmSPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_jxMIO2sd_sendMessage);
}

void Heavy_polycule::cSend_DOpaPyJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vYHOlTRf_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_7OIzZwCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IqXJgm8e_sendMessage(_c, 0, m);
}

void Heavy_polycule::cSend_Oje0xj7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3C8nGPPp_sendMessage(_c, 0, m);
}

void Heavy_polycule::cCast_vXN8e4Cs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SbkGaTKJ, 0, m, &cVar_SbkGaTKJ_sendMessage);
}

void Heavy_polycule::cCast_IdI6YWX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dypgIm5q, 0, m, &cVar_dypgIm5q_sendMessage);
}

void Heavy_polycule::cCast_GKEVE3xV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_9bDA4EwY_sendMessage);
}

void Heavy_polycule::cCast_oHQfWrzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_cubK1t29_sendMessage);
}

void Heavy_polycule::cCast_g0bh6zaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_u5FS8vlw, 0, m, &cVar_u5FS8vlw_sendMessage);
}

void Heavy_polycule::cCast_hMBFis0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dypgIm5q, 1, m, &cVar_dypgIm5q_sendMessage);
}

void Heavy_polycule::cCast_7f26ysai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WpfpMcYB, HV_BINOP_MULTIPLY, 0, m, &cBinop_WpfpMcYB_sendMessage);
}

void Heavy_polycule::cCast_bNt6UR78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W6zj9iZ9, HV_BINOP_MULTIPLY, 0, m, &cBinop_W6zj9iZ9_sendMessage);
}

void Heavy_polycule::cCast_TCh30rhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_polycule::cCast_kmyTbYum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_juz5HF1J, HV_BINOP_MULTIPLY, 0, m, &cBinop_juz5HF1J_sendMessage);
}

void Heavy_polycule::cCast_4ob5Fn7R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ScmL81if, HV_BINOP_MULTIPLY, 0, m, &cBinop_ScmL81if_sendMessage);
}

void Heavy_polycule::cCast_yLwMMboY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OfopRk2a, HV_BINOP_MULTIPLY, 0, m, &cBinop_OfopRk2a_sendMessage);
}

void Heavy_polycule::cMsg_Ekn87GW7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_UNC9iX7K, 0, m, NULL);
}

void Heavy_polycule::cVar_FOjFmYSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8Vx7XtOF, HV_BINOP_ADD, 0, m, &cBinop_8Vx7XtOF_sendMessage);
}

void Heavy_polycule::cBinop_xEsm8liV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sqtSypp4, m);
}

void Heavy_polycule::cBinop_EDaRtRIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xerhqfUe, m);
}

void Heavy_polycule::cBinop_ZNObdoZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_W5h4cIYu, m);
}

void Heavy_polycule::cBinop_jsZtCdz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 25.0f, 0, m, &cBinop_VueRi6VJ_sendMessage);
}

void Heavy_polycule::cBinop_5PUaP4ak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 600.0f, 0, m, &cBinop_29OxxXjG_sendMessage);
}

void Heavy_polycule::cBinop_05NYFyG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 24.0f, 0, m, &cBinop_5tLxLZRk_sendMessage);
}

void Heavy_polycule::cBinop_hliilloW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Vfyk1Oft_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RqlvjwvO_sendMessage);
}

void Heavy_polycule::cBinop_osuPeVaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9YgrJmHN, m);
}

void Heavy_polycule::cBinop_dHuDnzxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1lPVZina_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6goYNGlb_sendMessage);
}

void Heavy_polycule::cBinop_GY38cGVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_osuPeVaE_sendMessage);
}

void Heavy_polycule::cBinop_29OxxXjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3yo146eR, 0, m, &cVar_3yo146eR_sendMessage);
}

void Heavy_polycule::cBinop_8Vx7XtOF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ty9xOWaL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fBjoVqSp_sendMessage);
}

void Heavy_polycule::cBinop_VueRi6VJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oYZ1FsTQ, 0, m, &cVar_oYZ1FsTQ_sendMessage);
}

void Heavy_polycule::cBinop_jY9aacAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_ZNObdoZ3_sendMessage);
}

void Heavy_polycule::cBinop_32XBK37Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 275.0f, 0, m, &cBinop_jsZtCdz4_sendMessage);
}

void Heavy_polycule::cBinop_8cf4WXdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EDaRtRIT_sendMessage);
}

void Heavy_polycule::cBinop_5tLxLZRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dOF7D9bU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gkqr9BG9_sendMessage);
}

void Heavy_polycule::cBinop_XwToN5DN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TN6iClnE, m);
}

void Heavy_polycule::cBinop_WcA0Hefp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RroKyjkR, 0, m, &cVar_RroKyjkR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dRKZ5BG3, 0, m, &cVar_dRKZ5BG3_sendMessage);
}

void Heavy_polycule::cCast_2mNCzQ36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HCYGsdHC, 1, m, &cVar_HCYGsdHC_sendMessage);
}

void Heavy_polycule::cCast_2jh2JvEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kFaIg4s4, 0, m, &cVar_kFaIg4s4_sendMessage);
}

void Heavy_polycule::cCast_9Wo6VQF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HCYGsdHC, 0, m, &cVar_HCYGsdHC_sendMessage);
}

void Heavy_polycule::cCast_XxoR7ac2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FOjFmYSA, 0, m, &cVar_FOjFmYSA_sendMessage);
}

void Heavy_polycule::cCast_SRY6HYXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_h0mjgQhB, 1, m, &cVar_h0mjgQhB_sendMessage);
}

void Heavy_polycule::cCast_PAsf272s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_h0mjgQhB, 0, m, &cVar_h0mjgQhB_sendMessage);
}

void Heavy_polycule::cCast_Ty9xOWaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XwToN5DN, HV_BINOP_SUBTRACT, 1, m, &cBinop_XwToN5DN_sendMessage);
}

void Heavy_polycule::cCast_fBjoVqSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ebO7RRGI, 0, m, &cVar_ebO7RRGI_sendMessage);
}

void Heavy_polycule::cCast_6goYNGlb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IFqHHym8, 0, m, &cVar_IFqHHym8_sendMessage);
}

void Heavy_polycule::cCast_1lPVZina_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8cf4WXdB, HV_BINOP_SUBTRACT, 1, m, &cBinop_8cf4WXdB_sendMessage);
}

void Heavy_polycule::cCast_WkPOe91C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_j76N8V0w, 0, m, &cVar_j76N8V0w_sendMessage);
}

void Heavy_polycule::cCast_jKhyhJJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_32XBK37Z, HV_BINOP_SUBTRACT, 1, m, &cBinop_32XBK37Z_sendMessage);
}

void Heavy_polycule::cReceive_6WFEt1jK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lBavK4Yr_sendMessage(_c, 0, m);
  cMsg_0GGW1BfH_sendMessage(_c, 0, m);
  cMsg_GRVKrbjC_sendMessage(_c, 0, m);
  cMsg_abHLbL3J_sendMessage(_c, 0, m);
  cMsg_opyukWPJ_sendMessage(_c, 0, m);
  cMsg_clnapMdx_sendMessage(_c, 0, m);
  cMsg_9fs6SobJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5ZndH7bp, 0, m, &cVar_5ZndH7bp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oYZ1FsTQ, 0, m, &cVar_oYZ1FsTQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uewwiyoz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L3PlwFKz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_u5FS8vlw, 0, m, &cVar_u5FS8vlw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qAa5cvO0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d86G7Fu5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RroKyjkR, 0, m, &cVar_RroKyjkR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dRKZ5BG3, 0, m, &cVar_dRKZ5BG3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZTvcqTk2, 0, m, &cVar_ZTvcqTk2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bxFajgMm, 0, m, &cVar_bxFajgMm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VoOQtFQq, 0, m, &cVar_VoOQtFQq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KRne8x6H, 0, m, &cVar_KRne8x6H_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZqSXEZAv, 0, m, &cVar_ZqSXEZAv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tiRp9ue3, 0, m, &cVar_tiRp9ue3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qUvNarj0, 0, m, &cVar_qUvNarj0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yxencfLj, 0, m, &cVar_yxencfLj_sendMessage);
  cMsg_4x3oilWE_sendMessage(_c, 0, m);
}

void Heavy_polycule::cReceive_LRChYx4n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cegagA1a, HV_BINOP_ADD, 1, m, &cBinop_cegagA1a_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cW5Lsfh9, HV_BINOP_SUBTRACT, 1, m, &cBinop_cW5Lsfh9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_F9UbFMyW, HV_BINOP_SUBTRACT, 1, m, &cBinop_F9UbFMyW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_34bo36jI, HV_BINOP_ADD, 1, m, &cBinop_34bo36jI_sendMessage);
}

void Heavy_polycule::cReceive_QCyszybr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_v0KGgi10_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_w6ekVKib_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q5731c6P_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3xdndUNh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CEdjMHsG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KHBNQjpY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Mexnbtin_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wnYGApYe_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lyEExz6F_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_08zFfQf0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4GQCVGZe_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8HEdGADr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NT72Oczj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nHvJ9QlT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Rh37OuFq_sendMessage);
}

void Heavy_polycule::cReceive_oyqM5JtJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JsYKaaJb, HV_BINOP_MULTIPLY, 0, m, &cBinop_JsYKaaJb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OdmWq08A, HV_BINOP_MULTIPLY, 0, m, &cBinop_OdmWq08A_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_k4udKMhm, HV_BINOP_MULTIPLY, 0, m, &cBinop_k4udKMhm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xatg3L5l, HV_BINOP_MULTIPLY, 0, m, &cBinop_xatg3L5l_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xg39tw28, HV_BINOP_MULTIPLY, 0, m, &cBinop_Xg39tw28_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WW4KDjK2, HV_BINOP_MULTIPLY, 0, m, &cBinop_WW4KDjK2_sendMessage);
}

void Heavy_polycule::cReceive_FINoPYCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Myxjjx5, HV_BINOP_MULTIPLY, 0, m, &cBinop_4Myxjjx5_sendMessage);
}

void Heavy_polycule::cReceive_9IMH91wU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_gGeTmOtD_sendMessage);
  cMsg_ujAD6Q9I_sendMessage(_c, 0, m);
}

void Heavy_polycule::cReceive_YuzfBRAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9Ul7dTfn_sendMessage(_c, 0, m);
  cMsg_EBHxAA7O_sendMessage(_c, 0, m);
  cMsg_K2R7kAAV_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_nIk51eYL_sendMessage);
}

void Heavy_polycule::cReceive_RFVsvOge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RiG46JpJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_RiG46JpJ_sendMessage);
}

void Heavy_polycule::cReceive_AxBMWFrv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VawTUqqx_sendMessage);
  cMsg_fJ9HOhnN_sendMessage(_c, 0, m);
}

void Heavy_polycule::cReceive_Qgl5KGCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MACiWWpo, HV_BINOP_MULTIPLY, 0, m, &cBinop_MACiWWpo_sendMessage);
}

void Heavy_polycule::cReceive_n1hRzgVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pn63Ncj1_sendMessage(_c, 0, m);
  cMsg_d5eWVaV2_sendMessage(_c, 0, m);
  cMsg_icYHSeEy_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_lHPC7HBi_sendMessage);
}

void Heavy_polycule::cReceive_mH83Twnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ACgj3xUI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_zUy81bzj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_WWN6yWNd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_FkUtYNI5_sendMessage);
}

void Heavy_polycule::cReceive_xXry9poh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tGsmIjqt, HV_BINOP_MULTIPLY, 0, m, &cBinop_tGsmIjqt_sendMessage);
}

void Heavy_polycule::cReceive_mqX08En5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_MRZOO6yP_sendMessage);
  cMsg_ePf1i2kD_sendMessage(_c, 0, m);
}

void Heavy_polycule::cReceive_Kat1M39k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LEG3jHU4, HV_BINOP_MULTIPLY, 0, m, &cBinop_LEG3jHU4_sendMessage);
}

void Heavy_polycule::cReceive_nTVwhylI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QtFJLpTQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_QtFJLpTQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kPgmCLGF, HV_BINOP_MULTIPLY, 1, m, &cBinop_kPgmCLGF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IzZJGVQd, HV_BINOP_DIVIDE, 1, m, &cBinop_IzZJGVQd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HjQdwr65, HV_BINOP_DIVIDE, 1, m, &cBinop_HjQdwr65_sendMessage);
}

void Heavy_polycule::cReceive_IIqd3GpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QtFJLpTQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_QtFJLpTQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kPgmCLGF, HV_BINOP_MULTIPLY, 0, m, &cBinop_kPgmCLGF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IzZJGVQd, HV_BINOP_DIVIDE, 0, m, &cBinop_IzZJGVQd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HjQdwr65, HV_BINOP_DIVIDE, 0, m, &cBinop_HjQdwr65_sendMessage);
}

void Heavy_polycule::cReceive_3QNuqrQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_tuumuoxd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_yyTXlP7j_sendMessage);
}

void Heavy_polycule::cReceive_C0bhJVHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KvZGPGWE, HV_BINOP_MULTIPLY, 0, m, &cBinop_KvZGPGWE_sendMessage);
}

void Heavy_polycule::cReceive_yJSwzRvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jI0sKwwO_sendMessage(_c, 0, m);
  cMsg_zSOSWBfv_sendMessage(_c, 0, m);
  cMsg_TQ9009B4_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_cMc0F9uF_sendMessage);
}

void Heavy_polycule::cReceive_p3CzG4Fj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_pyyD5enJ_sendMessage);
  cMsg_StYlJVoX_sendMessage(_c, 0, m);
}

void Heavy_polycule::cReceive_3C8nGPPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_PwdnFuTh_sendMessage);
  cMsg_pfBuVoXJ_sendMessage(_c, 0, m);
}

void Heavy_polycule::cReceive_IqXJgm8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_leBbH8Se, HV_BINOP_MULTIPLY, 0, m, &cBinop_leBbH8Se_sendMessage);
}

void Heavy_polycule::cReceive_vYHOlTRf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RhxdaEgZ_sendMessage(_c, 0, m);
  cMsg_uDyKE03O_sendMessage(_c, 0, m);
  cMsg_bqwyHudi_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_4TeKvnBE_sendMessage);
}

void Heavy_polycule::cReceive_B2ngd8XP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 36.0f, 0, m, &cBinop_05NYFyG8_sendMessage);
}

void Heavy_polycule::cReceive_Yg0UBiKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 1.0f, 0, m, &cBinop_xEsm8liV_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OKELXIQ2, m);
}

void Heavy_polycule::cReceive_NrKxKd7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PAsf272s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XxoR7ac2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SRY6HYXY_sendMessage);
}

void Heavy_polycule::cReceive_7SvxpBcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9Wo6VQF8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2jh2JvEL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2mNCzQ36_sendMessage);
}

void Heavy_polycule::cReceive_veL8rFxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_hliilloW_sendMessage);
}

void Heavy_polycule::cReceive_NnwMaz6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4fREovV8, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jEvqjtKG, m);
}

void Heavy_polycule::cReceive_oR02XZuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jKhyhJJy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WkPOe91C_sendMessage);
}

void Heavy_polycule::cReceive_Vhd0e2Fm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1400.0f, 0, m, &cBinop_5PUaP4ak_sendMessage);
}

void Heavy_polycule::cReceive_c3Udbkss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.05f, 0, m, &cBinop_GY38cGVC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.1f, 0, m, &cBinop_jY9aacAc_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_polycule::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7;

  // input and output vars
  hv_bufferf_t O0, O1;
  hv_bufferf_t I0, I1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    // load input buffers
    __hv_load_f(inputBuffers[0]+n, VOf(I0));
    __hv_load_f(inputBuffers[1]+n, VOf(I1));

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_zero_f(VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_line_f(&sLine_9e4xL0L3, VOf(Bf2));
    __hv_line_f(&sLine_nGqTF2lq, VOf(Bf3));
    __hv_line_f(&sLine_OswWEXrK, VOf(Bf4));
    __hv_line_f(&sLine_Tc1HbscM, VOf(Bf5));
    __hv_line_f(&sLine_KpI4HxA3, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_wKdo07VT, VIf(I0), VIf(Bf2), VIf(Bf3), VIf(Bf4), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_ollV2Kg6, VOf(Bf5));
    __hv_line_f(&sLine_h2rTC68R, VOf(Bf4));
    __hv_line_f(&sLine_4LxtWRrK, VOf(Bf3));
    __hv_line_f(&sLine_ULIdzvfl, VOf(Bf2));
    __hv_line_f(&sLine_5uipgrk8, VOf(Bf7));
    __hv_biquad_f(&sBiquad_s_rnFtbM4i, VIf(Bf6), VIf(Bf5), VIf(Bf4), VIf(Bf3), VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_EGJnCRU7, VOf(Bf2));
    __hv_line_f(&sLine_c35xVqS6, VOf(Bf3));
    __hv_line_f(&sLine_L6QI2sxz, VOf(Bf4));
    __hv_line_f(&sLine_2aqS4R4C, VOf(Bf5));
    __hv_line_f(&sLine_8CzXJsUm, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_SEeodoXi, VIf(Bf7), VIf(Bf2), VIf(Bf3), VIf(Bf4), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_wkTpzcvQ, VOf(Bf5));
    __hv_line_f(&sLine_V183eFbc, VOf(Bf4));
    __hv_line_f(&sLine_6nWJNpwK, VOf(Bf3));
    __hv_line_f(&sLine_aujPyI3o, VOf(Bf2));
    __hv_line_f(&sLine_hZX6p11G, VOf(Bf7));
    __hv_biquad_f(&sBiquad_s_5xrS1eni, VIf(Bf6), VIf(Bf5), VIf(Bf4), VIf(Bf3), VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_zV1pENor, VOf(Bf2));
    __hv_line_f(&sLine_dEacS5S5, VOf(Bf3));
    __hv_line_f(&sLine_ig1MqdXn, VOf(Bf4));
    __hv_line_f(&sLine_5sbSW92o, VOf(Bf5));
    __hv_line_f(&sLine_0ufmkMY6, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_cbMwCZen, VIf(Bf7), VIf(Bf2), VIf(Bf3), VIf(Bf4), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_9YgrJmHN, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf4));
    __hv_eq_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_exp_f(VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf2));
    __hv_lt_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_and_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_pow_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_exp_f(VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf7));
    __hv_gt_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_and_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_neg_f(VIf(Bf2), VOf(Bf2));
    __hv_pow_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_neg_f(VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf3));
    __hv_eq_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_exp_f(VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_and_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_pow_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_exp_f(VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf5));
    __hv_gt_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_and_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_neg_f(VIf(Bf1), VOf(Bf1));
    __hv_pow_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_sqtSypp4, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_W5h4cIYu, VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_TN6iClnE, VOf(Bf6));
    __hv_min_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_xerhqfUe, VOf(Bf3));
    __hv_max_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_OKELXIQ2, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_853HbX5T, VOf(Bf3));
    __hv_line_f(&sLine_tfawjeIt, VOf(Bf4));
    __hv_line_f(&sLine_mSP6osrT, VOf(Bf6));
    __hv_line_f(&sLine_UNC9iX7K, VOf(Bf0));
    __hv_line_f(&sLine_7fHdDRHo, VOf(Bf2));
    __hv_biquad_f(&sBiquad_s_P0cKR8Qx, VIf(Bf1), VIf(Bf3), VIf(Bf4), VIf(Bf6), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_CFcusdIv, VOf(Bf0));
    __hv_line_f(&sLine_ycUzQxqt, VOf(Bf6));
    __hv_line_f(&sLine_d2zk7NHW, VOf(Bf4));
    __hv_line_f(&sLine_hWxlgDVl, VOf(Bf3));
    __hv_line_f(&sLine_VCxDIKgm, VOf(Bf1));
    __hv_biquad_f(&sBiquad_s_2uDpJATX, VIf(Bf2), VIf(Bf0), VIf(Bf6), VIf(Bf4), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_jEvqjtKG, VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_gt_f(VIf(ZERO), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_and_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f);
    __hv_var_k_f(VOf(Bf4), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_fms_f(VIf(Bf6), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_gte_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_and_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_4fREovV8, VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_lte_f(VIf(ZERO), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_and_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_CEpoV4ys, VOf(Bf0));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_polycule::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s)
  float **const bIn = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bIn[0] = inputBuffers+(0*n4);
  bIn[1] = inputBuffers+(1*n4);

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_polycule::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s), uninterleave
  float *const bIn = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));
  #if HV_SIMD_SSE || HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 a = _mm_load_ps(inputBuffers+i);                // LRLR
    __m128 b = _mm_load_ps(inputBuffers+4+i);              // LRLR
    __m128 x = _mm_shuffle_ps(a, b, _MM_SHUFFLE(2,0,2,0)); // LLLL
    __m128 y = _mm_shuffle_ps(a, b, _MM_SHUFFLE(3,1,3,1)); // RRRR
    _mm_store_ps(bIn+j, x);
    _mm_store_ps(bIn+n4+j, y);
  }
  #elif HV_SIMD_NEON
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4x2_t a = vld2q_f32(inputBuffers+i); // load and uninterleave
    vst1q_f32(bIn+j, a.val[0]);
    vst1q_f32(bIn+n4+j, a.val[1]);
  }
  #else // HV_SIMD_NONE
  for (int j = 0; j < n4; ++j) {
    bIn[0*n4+j] = inputBuffers[0+2*j];
    bIn[1*n4+j] = inputBuffers[1+2*j];
  }
  #endif

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
