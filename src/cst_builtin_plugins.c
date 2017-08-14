/*
 * cst_builtin_plugins.c
 * 
 * Copyright 2017 Sergio Oller <sergioller@gmail.com>
 * All rights reserved.
 */
/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the  nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
 /* This links all the builtin languages and voices, when they are
  * not used as cst_plugins */

#include "mimic.h"

#include "usenglish.h"
#include "cmu_indic_lang.h"
#include "cmu_grapheme_lang.h"
#include "cmu_us_slt.h"
#include "cmu_time_awb.h"
#include "cmu_us_kal.h"
#include "cmu_us_kal16.h"
#include "cmu_us_awb.h"
#include "cmu_us_rms.h"
#include "cmu_us_slt_hts.h"

#include "vid_gb_ap.h"

#if defined(MIMIC_SPANISH)
  #include "es_lang.h"
#endif

#if defined(MIMIC_CSTR_UPC_UPM_SPANISH_HTS)
  #include "cstr_upc_upm_spanish_hts.h"
#endif

int mimic_builtin_plugins_init()
{
  usenglish_plugin_init();
  indic_plugin_init();
  grapheme_plugin_init();
  #if defined(MIMIC_SPANISH)
  es_plugin_init();
  #endif
  voice_cmu_us_slt_plugin_init();
  voice_cmu_time_awb_plugin_init();
  voice_cmu_us_kal_plugin_init();
  voice_cmu_us_kal16_plugin_init();
  #if defined(MIMIC_CSTR_UPC_UPM_SPANISH_HTS)
  voice_cstr_upc_upm_spanish_hts_plugin_init();
  #endif
  voice_cmu_us_awb_plugin_init();
  voice_cmu_us_rms_plugin_init();
  voice_cmu_us_slt_hts_plugin_init();
  voice_vid_gb_ap_plugin_init();
  return 0;
}

void mimic_builtin_plugins_exit()
{
  voice_cmu_us_awb_plugin_exit();
  voice_cmu_us_rms_plugin_exit();
  voice_cmu_us_slt_hts_plugin_exit();
  voice_vid_gb_ap_plugin_exit();
  #if defined(MIMIC_CSTR_UPC_UPM_SPANISH_HTS)
  voice_cstr_upc_upm_spanish_hts_plugin_exit();
  #endif
  voice_cmu_us_kal16_plugin_exit();
  voice_cmu_us_kal_plugin_exit();
  voice_cmu_time_awb_plugin_exit();
  voice_cmu_us_slt_plugin_exit();
  #if defined(MIMIC_SPANISH)
  es_plugin_exit();
  #endif
  grapheme_plugin_exit();
  indic_plugin_exit();
  usenglish_plugin_exit();
  return;
}

int mimic_init()
{
    mimic_audio_init();
    mimic_builtin_plugins_init();
    return 0;
}

int mimic_exit()
{
    mimic_builtin_plugins_exit();
    mimic_audio_exit();
    return 0;
}

