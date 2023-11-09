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
/* Watchdog works with PCA0 timer and uses Timer4 as clock source    */
/* to allow higher period (50ms) because of long CRC calculation     */
/*                                                                   */
/*********************************************************************/

/* IMPORTED MODULES */

#include "Driver_WDT.h"

/* CONSTANTS */

#define WDT_PERIOD_MS						50U
#define WDT_TIMER_RELOAD_VALUE	(0x10000U - ((CPU_CLOCK * WDT_PERIOD_MS / 1000U) / 0x10000U))

/* MODULE DATA */

/* ROUTINES */

/**********************************************************************/
/* WDT_Disable                                                        */
/*                                                                    */
/* Disable Watchdog timer                                             */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
void WDT_Disable(void)
{
  PCA0MD &= ~0x40U;
}

/**********************************************************************/
/* WDT_Reset                                                          */
/*                                                                    */
/* Reset Watchdog timer                                               */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
void WDT_Reset(void)
{
  // Write an initial value to the PCA0CPH5 register 
  // to reset the watchdog timer timeout
  PCA0CPH5 = 0xFFU;
}

/**********************************************************************/
/* WDT_Init                                                           */
/*                                                                    */
/* Initialize Watchdog timer                                          */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
void WDT_Init(void)
{
  uint8_t SFRPAGE_save = SFRPAGE;
  SFRPAGE = ACTIVE_PAGE;
  
  // Offset calculated in PCA clocks
  // Offset = ( 256 x PCA0CPL5 ) + 256 - PCA0L
  //        = ( 256 x 255(0xFF)) + 256 - 0
  // Time   = Offset * (12/SYSCLK)
  //        = 16 ms ( PCA uses SYSCLK/12 as its clock source)

  // PCA0 counter enable
  //PCA0CN = 0x40;                 
  // Disable watchdog timer
  PCA0MD &= ~0x40U;
  // Timebase selected - Timer4, not System clock / 12!
  PCA0MD = (6UL << 1U);   //lint !e838
  // Set lower byte of PCA counter to 0
  PCA0L = 0x00U;
  // Set higher byte of PCA counter to 0
  PCA0H = 0x00U;
  // Write offset for the WDT
  PCA0CPH5 = 0xFFU;
  PCA0CPL5 = 0xFFU;
  // watchdog locked
  PCA0MD |= 0x20U;        //lint !e838
  // Enable the WDT
  PCA0MD |= 0x40U;        //lint !e838
  // Enable missing clock detector
  //RSTSRC = 0x04U;
	
  SFRPAGE = ACTIVE2_PAGE; //lint !e838
	// Stop Timer4; Clear TF4, Auto-Reload mode
  TMR4CN  = 0x00U;
  // Timer4 clocked with SYSCLK, timer counts up
  TMR4CF = (1UL << 3U) | (1UL << 0U);
  // Set reload value
  TMR4CAP = WDT_TIMER_RELOAD_VALUE;
  // Reset timer value
  TMR4 = WDT_TIMER_RELOAD_VALUE;
  // Start Timer4
  TMR4CN |= (1UL << 2U);
  
  SFRPAGE = SFRPAGE_save;
}
