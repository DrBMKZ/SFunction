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

#include "defines.h"
#include "Sw_APP.h"
#include "drivers.h"

/* CONSTANTS */

/* MODULE DATA */

/* ROUTINES */

/**********************************************************************/
/* main                                                               */
/*                                                                    */
/* Main application loop                                              */
/*                                                                    */
/* {"Trace:SDD_VCA_0705-700;"}                                        */
/*                                                                    */
/**********************************************************************/
void main(void)
{
  // Disable global interrupts
  EA = 0;
  // Disable watchdog
  WDT_Disable();

  // Initialise HW modules
  CLK_Init();
  GPIO_Init();
  BLDC_Init();
  SERIAL_Init();
  TIMER_Init();
  TEMP_Init();
  #ifndef VAL_BOARD
  SPI_Init(); // Disable for Validation Board using AS5045 Sensor
  #endif
  POSITION_Init();
  WDT_Init();

  SFRPAGE = ACTIVE_PAGE;  
  Run_SW_App();
}
