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
/* Timer3 is used as counter with auto-reload functionality          */
/*                                                                   */
/*********************************************************************/

/* IMPORTED MODULES */

#include "defines.h"
#include "Driver_Timer.h"

/* CONSTANTS */

#define TIMER_PERIOD_US     800UL
#define TIMER_FREQ          (1000000UL / TIMER_PERIOD_US)
#define TIMER_RELOAD_VALUE  (0x10000U - ((CPU_CLOCK / 12U) / TIMER_FREQ))

/* MODULE DATA */

/* ROUTINES */

/**********************************************************************/
/* TIMER_Start                                                        */
/*                                                                    */
/* Start timer                                                        */
/*                                                                    */
/**********************************************************************/
void TIMER_Start(void)
{
//   // Set initial counter value
//   TMR3 = TIMER_RELOAD_VALUE;
//   // Start Timer3
//   TMR3CN |= (1UL << 2U);
}

/**********************************************************************/
/* TIMER_IsTicked                                                     */
/*                                                                    */
/* Check if timer is ticked (expired)                                 */
/*                                                                    */
/* Returns True if timer is ticked                                    */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
static bool TIMER_IsTicked(void)
{
//   if ((TMR3CN & (1UL << 7U)) > 0U)
//   {
//     TMR3CN &= ~(1UL << 7U);
//     return true;
//   }
//   return false;
}

/**********************************************************************/
/* TIMER_WaitForExpire                                                */
/*                                                                    */
/* Wait for timer expiration                                          */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
void TIMER_WaitForExpire(void)
{
//   while (!TIMER_IsTicked()) {}
}

/**********************************************************************/
/* TIMER_Init                                                         */
/*                                                                    */
/* Initialize timer module                                            */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
void TIMER_Init(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = ACTIVE_PAGE;
// 
//   // Stop Timer3; Clear TF3, use SYSCLK/12 as timebase
//   TMR3CN  = 0x00U;
//   // Timer3 clocked based on T3XCLK;
//   CKCON  &= ~0xC0U;
//   // Set reload value
//   TMR3RL = TIMER_RELOAD_VALUE;
// 
//   SFRPAGE = SFRPAGE_save;
}
