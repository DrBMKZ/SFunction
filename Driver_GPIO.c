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
/* Any implementation specific notes not affecting the functionality */
/* of the function.                                                  */
/* Also any affected global data shall be listed here.               */
/*                                                                   */
/*********************************************************************/

/* IMPORTED MODULES */

#include "Driver_GPIO.h"

/* CONSTANTS */

/* MODULE DATA */

/* ROUTINES */

/**********************************************************************/
/* GPIO_ReadHalls                                                     */
/*                                                                    */
/* Read Hall pins value                                               */
/*                                                                    */
/* Returns Hall pins value                                            */
/*                                                                    */
/**********************************************************************/ 
uint8_t GPIO_ReadHalls(void)
{
//   uint8_t result = 0;
//   
//   if (P_IN(HA_PORT, HA_PIN) == 0U)
//   {
//     result += 1U;
//   }
//   if (P_IN(HB_PORT, HB_PIN) == 0U)
//   {
//     result += 2U;
//   }
//   if (P_IN(HC_PORT, HC_PIN) == 0U)
//   {
//     result += 4U;
//   }
// 
//   return result;
}

/**********************************************************************/
/* GPIO_Init                                                          */
/*                                                                    */
/* Initialize hardware pins                                           */
/*                                                                    */
/**********************************************************************/ 
void GPIO_Init(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = CONFIG_PAGE;
// 
//   // UART0.TX, UART0.RX (P0.4, P0.5)
//   P0SKIP = 0xCEU;
//   // SPI0.SCK, SPI0.MISO, SPI0.MOSI (P1.0, P1.1, P1.2)
//   #ifdef DEF_AS5045
//   P1SKIP = 0xFFU;
//   #else
//   P1SKIP = 0xF8U;
//   #endif
//   // UART1.TX, UART1.RX (P2.3, P2.4)
//   P2SKIP = 0xE7U;
//   // Activate Hall pins as digital pins (inputs)
//   P_DIG_IO(HA_PORT, HA_PIN);
//   P_DIG_IO(HB_PORT, HB_PIN);
//   P_DIG_IO(HC_PORT, HC_PIN);
// 
//   // Skip driver fault pin on the crossbar, P3.0
//   P3SKIP = 0x01U;
// 
//   // Configure tick pin
// 	P4MDOUT |= (1UL << TICK_PIN);
// 	P_CLEAR(TICK_PORT, TICK_PIN);
// 
//   // Enable crossbar and weak pull-ups
//   XBR2 = 0x40U;
// 
//   SFRPAGE = SFRPAGE_save;
}
