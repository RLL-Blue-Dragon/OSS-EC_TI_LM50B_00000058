// License       : License.txt
// Specifications: Spec-LM50B.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM50B.cpp
// Reason for change: 01.00.00 : 01/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "LM50B.h"

#if     iLM50B_ma == iSMA                               // Simple moving average filter
static float32 LM50B_sma_buf[iLM50B_SMA_num];
static sma_f32_t LM50B_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iLM50B_SMA_num ,                                // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &LM50B_sma_buf[0]                               // buffer
};

#elif   iLM50B_ma == iEMA                               // Exponential moving average filter
static ema_f32_t LM50B_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iLM50B_EMA_K                                    // Exponential smoothing factor
};

#elif   iLM50B_ma == iWMA                               // Weighted moving average filter
static float32 LM50B_wma_buf[iLM50B_WMA_num];
static wma_f32_t LM50B_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iLM50B_WMA_num ,                                // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iLM50B_WMA_num * (iLM50B_WMA_num + 1)/2 ,       // kn sum
        &LM50B_wma_buf[0]                               // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_LM50B =
{
        iLM50B                  ,
        iLM50B_pin              ,
        iLM50B_xoff             ,
        iLM50B_yoff             ,
        iLM50B_gain             ,
        iLM50B_max              ,
        iLM50B_min              ,
        iLM50B_ma               ,
        
#if     iLM50B_ma == iSMA                               // Simple moving average filter
        &LM50B_Phy_SMA          ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iLM50B_ma == iEMA                               // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &LM50B_Phy_EMA          ,
        (wma_f32_t*)iDummy_adr
#elif   iLM50B_ma == iWMA                               // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &LM50B_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
