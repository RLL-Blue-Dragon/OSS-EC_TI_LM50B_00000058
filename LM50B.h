// License       : License.txt
// Specifications: Spec-LM50B.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM50B.h
// Reason for change: 01.00.00 : 01/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __LM50B_H__
#define __LM50B_H__

#include "user_define.h"

// Components number
#define iLM50B                  130U                    // Texas Instruments LM50B

// LM50B System Parts definitions
#define iLM50B_xoff             0.5F                    // X offset [V]
#define iLM50B_yoff             0.0F                    // Y offset [degree celsius]
#define iLM50B_gain             0.01F                   // Gain [V/degree celsius]
#define iLM50B_max              100.0F                  // Temperature Max [degree celsius]
#define iLM50B_min              -25.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_LM50B;

#endif /*__LM50B_H__*/
