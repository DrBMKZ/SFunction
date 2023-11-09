/*********************************************************************/
/*                                                                   */
/* Copyright by:       Volz Servos GmbH & Co. KG                     */
/*                                                                   */
/* Project:                Thales MON CPU                            */
/*                                                                   */
/*********************************************************************/
/*                                                                   */
/*                     Module Specification                          */
/*                     ====================                          */
/*                                                                   */
/* Module overview                                                   */
/* --------------------                                              */
/*                                                                   */
/* Any implementation specific notes not affecting the functionality */
/* of the function.                                                  */
/* Also any affected global data shall be listed here.               */
/*                                                                   */
/*********************************************************************/

#ifndef DRV_TEMP_H
#define DRV_TEMP_H

/* IMPORTED MODULES FOR TYPES AND CONSTANTS */

#include "defines.h"

/* CONSTANTS */

#define ADC_CHANNEL_MASK   ((1UL << 6U) - 1U)

enum E_ADC_CHANNELS {  //lint !e8101
  ADC_P0_0,
  ADC_P0_1,
  ADC_P0_2,
  ADC_P0_3,
  ADC_P0_4,
  ADC_P0_5,
  ADC_P0_6,
  ADC_P0_7,
  ADC_P1_0,
  ADC_P1_1,
  ADC_P1_2,
  ADC_P1_3,
  ADC_P1_4,
  ADC_P1_5,
  ADC_P1_6,
  ADC_P1_7,
  ADC_P2_0,
  ADC_P2_1,
  ADC_P2_2,
  ADC_P2_3,
  ADC_P2_4,
  ADC_P2_5,
  ADC_P2_6,
  ADC_P2_7,
  ADC_P3_0,
  ADC_P3_1,
  ADC_P3_2,
  ADC_P3_3,
  ADC_P3_4,
  ADC_P3_5,
  ADC_P3_6,
  ADC_P3_7,
  ADC_TEMP = 0x30,
  ADC_VDD,
  ADC_GND
};

// REF0CN bits
#define REF0CN_ZTCEN  (1UL << 5U)
#define REF0CN_REFLV  (1UL << 4U)
#define REF0CN_REFSL  (1UL << 3U)
#define REF0CN_TEMPE  (1UL << 2U)
#define REF0CN_BIASE  (1UL << 1U)
#define REF0CN_REFBE  (1UL << 0U)

enum E_TEMP_CHANNELS {  //lint !e8101
  TEMP_CHANNEL_MOTOR,
  TEMP_CHANNEL_CPU,
  TEMP_CHANNEL_LAST
};

/* EXPORTED DATA TYPES */

/* EXPORTED ROUTINES */

uint8_t TEMP_CheckOvertemperature(void);
void TEMP_Init(void);

#endif
