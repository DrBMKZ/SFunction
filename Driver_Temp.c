/*********************************************************************/
/*                                                                   */
/* Copyright by:       Volz Servos GmbH & Co. KG                     */
/*                                                                   */
/* Project:                Thales COM CPU                            */
/*                                                                   */
/*********************************************************************/
/*                                                                   */
/*                     Module Specification                          */
/*                     ====================                          */
/*                                                                   */
/* Module overview                                                   */
/* --------------------                                              */
/*                                                                   */
/* It uses ADC and does permanent conversions tacted with Timer2.    */
/* Two channels are converted, one of them is the internal           */
/* temperature sensor. After each TEMP_IsOver execution next channel */
/* is selected.                                                      */
/*                                                                   */
/*********************************************************************/

/* IMPORTED MODULES */

#include "Driver_Temp.h"
#include "Driver_GPIO.h"

/* CONSTANTS */

/* Maximal temperature value in °C */
#define TEMP_CPU_MAX_VALUE          100U
#define TEMP_MOTOR_MAX_VALUE        110U

/* ADC parameters */
#define ADC_RESOLUTION              4096U
#define ADC_REFERENCE_MV            2200U    // 2.2V

/* Clock value for ADC module in Hz */
#define ADC_CLOCK                   2000000U

/* ADC timer settings */
#define TEMP_TIMER_FREQ             (10000UL)
#define TEMP_TIMER_RELOAD_VALUE     (0x10000U - ((CPU_CLOCK / 12U) / TEMP_TIMER_FREQ))

/* Offset/slope parameters for CPU sensor */
/* Offset value for 0°C temperature, mV */
#define TEMP_OFFSET_MV              856UL
#define TEMP_OFFSET_UNITS           (TEMP_OFFSET_MV * ADC_RESOLUTION / ADC_REFERENCE_MV)
/* Slope value, uV */
#define TEMP_SLOPE_UV               3330UL
#define TEMP_SLOPE_UNITS            ((TEMP_SLOPE_UV * ADC_RESOLUTION * 10U / ADC_REFERENCE_MV) / 1000U)

#define TEMP_CPU_MAX_VALUE_UNITS    ((TEMP_CPU_MAX_VALUE * TEMP_SLOPE_UNITS / 10U) + TEMP_OFFSET_UNITS)

/* Offset/slope parameters for external temperature sensor (MCP9700) */
/* Offset value for 0°C temperature, mV */
#define MCP9700_OFFSET_MV           500UL
#define MCP9700_OFFSET_UNITS        (MCP9700_OFFSET_MV * ADC_RESOLUTION / ADC_REFERENCE_MV)
/* Slope value, uV */
#define MCP9700_SLOPE_UV            10000UL
#define MCP9700_SLOPE_UNITS         ((MCP9700_SLOPE_UV * ADC_RESOLUTION * 10U / ADC_REFERENCE_MV) / 1000U)

#define TEMP_MOTOR_MAX_VALUE_UNITS  ((TEMP_MOTOR_MAX_VALUE * MCP9700_SLOPE_UNITS / 10U) + MCP9700_OFFSET_UNITS)

#define TEMPERATURE_COUNTER_LIMIT   3U

/* MODULE DATA */

static uint16_t temp_values[(int)TEMP_CHANNEL_LAST];
static uint8_t  index;

/* ROUTINES */

/**********************************************************************/
/* TEMP_SetChannel                                                    */
/*                                                                    */
/* Set temperature channel                                            */
/*                                                                    */
/* [in] channel Number of temperature channel                         */
/*                                                                    */
/**********************************************************************/
static void TEMP_SetChannel(uint8_t channel)
{
//   // Set selected ADC channel
//   ADC0MX = channel & ADC_CHANNEL_MASK;
}

/**********************************************************************/
/* TEMP_CheckOvertemperature                                          */
/*                                                                    */
/* Check temperature overflow for MCU and motor sensors               */
/*                                                                    */
/* Returns corresponding bits are set if overflow is occurred         */
/*                                                                    */
/* {"Trace:SDD_VCA_0705-432; SDD_VCA_0705-685; SDD_VCA_0705-691;"}    */
/*                                                                    */
/**********************************************************************/
uint8_t TEMP_CheckOvertemperature(void)
{
//   static uint8_t res = 0;
//   static uint8_t temp_cpu_counter = 0;
//   static uint8_t temp_mot_counter = 0;
//   
//   if (index >= (uint8_t)TEMP_CHANNEL_LAST)
//   {
//     //index = (uint8_t)TEMP_CHANNEL_MOTOR;
//     index = (uint8_t)TEMP_CHANNEL_CPU;
//   }
//   // Read converted value from ADC
//   temp_values[index] = ADC0;
//   // Set next ADC channel
//   switch (index)
//   {
//     case TEMP_CHANNEL_MOTOR:
//       TEMP_SetChannel(ADC_TEMP);
//       break;
//     case TEMP_CHANNEL_CPU:
//       //TEMP_SetChannel(ADC_P2_0);
//       break;
//     default:
//       //index = TEMP_CHANNEL_MOTOR;
//       index = TEMP_CHANNEL_CPU;
//       break;
//   }
//   // Increment channel
//   //index++;
//   // Set static flags
//   if (temp_values[TEMP_CHANNEL_MOTOR] > (uint16_t)TEMP_MOTOR_MAX_VALUE_UNITS)
//   {
//     if (temp_mot_counter >= TEMPERATURE_COUNTER_LIMIT)
//     {
//       res |= COM_BIT_MOTOR_OVERTEMP_FAULT;
//     } else
//     {
//       temp_mot_counter++;
//     }
//   } else
//   {
//     temp_mot_counter = 0;
//     res &= ~COM_BIT_MOTOR_OVERTEMP_FAULT;
//   }
//   if (temp_values[TEMP_CHANNEL_CPU] > (uint16_t)TEMP_CPU_MAX_VALUE_UNITS)
//   {
//     if (temp_cpu_counter >= TEMPERATURE_COUNTER_LIMIT)
//     {
//       res |= COM_BIT_CPU_OVERTEMP_FAULT;
//     } else
//     {
//       temp_cpu_counter++;
//     }
//   } else
//   {
//     temp_cpu_counter = 0;
//     res &= ~COM_BIT_CPU_OVERTEMP_FAULT;
//   }
//   
//   return res;
}

/**********************************************************************/
/* TEMP_Init                                                          */
/*                                                                    */
/* Initialize temperature measurements                                 */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
void TEMP_Init(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   
//   SFRPAGE = CONFIG_PAGE;  
//   // Skip P0.0 (VREF)
//   P0SKIP  |= (1UL << 0U);
//   // Set VREF to analog
//   P0MDIN  &= ~(1UL << 0U);
//   // Set analog inputs
//   P2MDIN &= ~(1UL << ADC_TEMP_PIN);
// 
//   SFRPAGE = ACTIVE_PAGE;    //lint !e838
//   
//   // ADC0 disabled, normal tracking, conversion triggered on Timer2
//   // Output is right-justified, no gain settings
//   ADC0CN = (0x03UL << 0U);
//   // Enable on-chip VREF and buffer, set voltage reference to 2.2V
//   // Internal temperature sensor: On
//   REF0CN = (REF0CN_REFLV | REF0CN_TEMPE | REF0CN_BIASE | REF0CN_REFBE);
//   // Set SAR clock 
//   ADC0CF = ((CPU_CLOCK / ADC_CLOCK) - 1U) << 3;
//   // Enable ADC0
//   AD0EN = 1;
//   
//   // Stop Timer2; Clear TF2, use SYSCLK/12 as timebase
//   TMR2CN  = 0x00U;
//   // Timer2 clocked based on T2XCLK;
//   CKCON  &= ~0x30U;
//   // Set reload value
//   TMR2RL = TEMP_TIMER_RELOAD_VALUE;
//   // Reset timer value
//   TMR2 = TEMP_TIMER_RELOAD_VALUE;
//   // Start Timer2
//   TMR2CN |= (1UL << 2U);
//   
//   //index = TEMP_CHANNEL_MOTOR;
//   //TEMP_SetChannel(ADC_P2_0);
//   index = TEMP_CHANNEL_CPU;
//   TEMP_SetChannel(ADC_TEMP);
//   
//   SFRPAGE = SFRPAGE_save;
}
