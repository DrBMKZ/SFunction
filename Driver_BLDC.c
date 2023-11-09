/*********************************************************************/
/*                                                                   */
/* Copyright by:       Volz Servos GmbH & Co. KG                     */
/*                                                                   */
/* Project:                Thales COM CPU                            */
/*                                                                   */
/*********************************************************************/
/*                                                                   */
/*                     Module Implementation                         */
/*                     =====================                         */
/*                                                                   */
/* Implementation notes                                              */
/* --------------------                                              */
/*                                                                   */
/* P3.6 - INA (PWM)                                                  */
/* P3.5 - ENA                                                         */
/* P3.4 - INB (PWM)                                                  */
/* P3.3 - ENB                                                        */
/* P3.2 - INC (PWM)                                                  */
/* P3.1 - ENC                                                        */
/*                                                                   */
/*********************************************************************/

/* IMPORTED MODULES */

#include "Driver_BLDC.h"
#include "Driver_GPIO.h"

/* CONSTANTS */

/* MODULE DATA */

/* ROUTINES */

/**********************************************************************/
/* BLDC_SetCLBH                                                       */
/*                                                                    */
/* Set commutation state C:low, B:PWM                                 */
/*                                                                    */
/**********************************************************************/ 
static void BLDC_SetCLBH(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = CONFIG_PAGE;
//   BLDC_SKIP = 0x0F;
//   BLDC_PORT = (1UL << 1U) | (1UL << 3U);
//   SFRPAGE = SFRPAGE_save;    
}

/**********************************************************************/
/* BLDC_SetCLAH                                                       */
/*                                                                    */
/* Set commutation state C:low, A:PWM                                 */
/*                                                                    */
/**********************************************************************/ 
static void BLDC_SetCLAH(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = CONFIG_PAGE;
//   BLDC_SKIP = 0x3F;
//   BLDC_PORT = (1UL << 1U) | (1UL << 5U);
//   SFRPAGE = SFRPAGE_save;    
}

/**********************************************************************/
/* BLDC_SetBLAH                                                       */
/*                                                                    */
/* Set commutation state B:low, A:PWM                                 */
/*                                                                    */
/**********************************************************************/ 
static void BLDC_SetBLAH(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = CONFIG_PAGE;
//   BLDC_SKIP = 0x3F;
//   BLDC_PORT = (1UL << 3U) | (1UL << 5U);
//   SFRPAGE = SFRPAGE_save;    
}

/**********************************************************************/
/* BLDC_SetBLCH                                                       */
/*                                                                    */
/* Set commutation state B:low, C:PWM                                 */
/*                                                                    */
/**********************************************************************/ 
static void BLDC_SetBLCH(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = CONFIG_PAGE;
//   BLDC_SKIP = 0x03;
//   BLDC_PORT = (1UL << 1U) | (1UL << 3U);
//   SFRPAGE = SFRPAGE_save;    
}

/**********************************************************************/
/* BLDC_SetALBH                                                       */
/*                                                                    */
/* Set commutation state A:low, B:PWM                                 */
/*                                                                    */
/**********************************************************************/ 
static void BLDC_SetALBH(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = CONFIG_PAGE;
//   BLDC_SKIP = 0x0F;
//   BLDC_PORT = (1UL << 3U) | (1UL << 5U);
//   SFRPAGE = SFRPAGE_save;    
}

/**********************************************************************/
/* BLDC_SetALCH                                                       */
/*                                                                    */
/* Set commutation state A:low, C:PWM                                 */
/*                                                                    */
/**********************************************************************/ 
static void BLDC_SetALCH(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = CONFIG_PAGE;
//   BLDC_SKIP = 0x03;
//   BLDC_PORT = (1UL << 1U) | (1UL << 5U);
//   SFRPAGE = SFRPAGE_save;    
}

/**********************************************************************/
/* BLDC_SetOFF                                                        */
/*                                                                    */
/* Set commutation state all:off                                      */
/*                                                                    */
/**********************************************************************/ 
static void BLDC_SetOFF(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = CONFIG_PAGE;
//   BLDC_SKIP = 0xFF;
//   BLDC_PORT = 0;
//   SFRPAGE = SFRPAGE_save;    
}

/**********************************************************************/
/* BLDC_SetPWM                                                        */
/*                                                                    */
/* Set new PWM value                                                  */
/*                                                                    */
/* [in] value New PWM value to set                                    */
/*                                                                    */
/**********************************************************************/ 
void BLDC_SetPWM(uint8_t value)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = ACTIVE2_PAGE;
//   
//   PCA1CPH6 = 255U - value;
// 
//   SFRPAGE = SFRPAGE_save;  
}

/**********************************************************************/
/* BLDC_SetCommutation                                                */
/*                                                                    */
/* Set BLDC motor commutation combination                             */
/*                                                                    */
/* [in] commutation Commutation combination to set                    */
/*                                                                    */
/* {"Trace:SDD_VCA_0705-445;"}                                        */
/*                                                                    */
/**********************************************************************/ 
void BLDC_SetCommutation(uint8_t commutation)
{
//   switch (commutation)
//   {
//     case BLDC_STATE_OFF:
//       BLDC_SetOFF();
//       break;
//     case BLDC_STATE_ALBH:
//       BLDC_SetALBH();
//       break;
//     case BLDC_STATE_ALCH:
//       BLDC_SetALCH();
//       break;
//     case BLDC_STATE_BLAH:
//       BLDC_SetBLAH();
//       break;
//     case BLDC_STATE_BLCH:
//       BLDC_SetBLCH();
//       break;
//     case BLDC_STATE_CLAH:
//       BLDC_SetCLAH();
//       break;
//     case BLDC_STATE_CLBH:
//       BLDC_SetCLBH();
//       break;
//     case BLDC_STATE_LAST:
//     default:
//       // unknown combination, ignore
//       break;
//   }
}

/**********************************************************************/
/* GPIO_GetDriverFault                                                */
/*                                                                    */
/* Read driver fault value                                            */
/*                                                                    */
/* Returns driver fault value                                         */
/*                                                                    */
/**********************************************************************/
bool BLDC_GetDriverFault(void)
{
//   return (P_IN(DRV_FAULT_PORT, DRV_FAULT_PIN) > 0U);
}

/**********************************************************************/
/* BLDC_Init                                                          */
/*                                                                    */
/* Initialize BLDC module (pins, PWM)                                 */
/*                                                                    */
/**********************************************************************/ 
void BLDC_Init(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = CONFIG_PAGE;
// 
//   // Set all BLDC pins to push-pull
//   P3MDOUT = 0xFE;
//   // Set driver fault pin as digital input
//   P_DIG_IO(DRV_FAULT_PORT, DRV_FAULT_PIN);
//   // Enable CEX6 on crossbar
//   XBR3 = (1UL << 0U);
//   // Reset all pins: all BLDC outputs are HiZ
//   BLDC_PORT = 0;
//   
//   SFRPAGE = ACTIVE2_PAGE; //lint !e838
// 
//   // Configure PCA time base
//   // Stop counter; clear all flags
//   PCA1CN = 0x00;
//   // Use SYSCLK/12 as time base, no prescaler available
//   //PCA1MD = (0 << 1);
//   // Use SYSCLK/4 as time base, no prescaler available
//   PCA1MD = (1UL << 1U);
//   // Module 0 = 8-bit PWM mode, duty cycle = 0%
//   PCA1CPH6 = 255;
//   PCA1CPM6 = 0x42;
// 
//   // Start PCA counter
//   CR1 = 1;
//     
//   SFRPAGE = SFRPAGE_save;  
}
