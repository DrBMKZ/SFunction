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
/* Any implementation specific notes not affecting the functionality */
/* of the function.                                                  */
/* Also any affected global data shall be listed here.               */
/*                                                                   */
/*********************************************************************/

#ifndef DRV_WDT_H
#define DRV_WDT_H

/* IMPORTED MODULES FOR TYPES AND CONSTANTS */

#include "defines.h"

/* CONSTANTS */

/* EXPORTED DATA TYPES */

/* EXPORTED ROUTINES */

void WDT_Init(void);
void WDT_Disable(void);
void WDT_Reset(void);
  
#endif
