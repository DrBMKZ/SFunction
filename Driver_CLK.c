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
#include "Driver_CLK.h"

/* CONSTANTS */

/* MODULE DATA */

/* ROUTINES */

/**********************************************************************/
/* CLK_Init                                                           */
/*                                                                    */
/* Initialize system clock module                                     */
/*                                                                    */
/**********************************************************************/
void CLK_Init(void)
{
//   uint16_t i;
//   uint8_t SFRPAGE_save = SFRPAGE;
//   SFRPAGE = CONFIG_PAGE;
//   
//   // Set internal osc. divider to 1
//   OSCICN = 0xC7U;
//   // Reset the Clock Multiplier
//   CLKMUL = 0x00U;
//   // Enable the Clock Multiplier
//   CLKMUL |= 0x80U;
//   // Need to delay (5 us) 120 clock cycles
//   for (i = 0; i < 120U; i++) {}          
//   // Initialize the Clock Multiplier
//   CLKMUL |= 0xC0U;
//   while ((CLKMUL & 0x20U) == 0U) {}
//   // Set new Flash read timing for higher clock speed (>25MHz)
//   FLSCL = 0x10U;
//   // Switch system clock to multiplier
//   CLKSEL = 0x02U;
// 
//   SFRPAGE = SFRPAGE_save;
}
