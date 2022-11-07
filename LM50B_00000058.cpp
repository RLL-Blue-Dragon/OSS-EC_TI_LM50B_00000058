// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM50B_00000058.cpp
// BSL              : 00000058
// Model number     : Texas Instruments LM50B
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 01/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "LM50B.h"

AnalogIn LM50B_adc( iLM50B_pin , iVref );       // AnalogIn object

// Main Function
pp2ap_adc_t LM50B_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( LM50B_adc , tbl_LM50B );
        return( res );
}
