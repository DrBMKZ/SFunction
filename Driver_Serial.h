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

#ifndef DRV_SERIAL_H
#define DRV_SERIAL_H

/* IMPORTED MODULES FOR TYPES AND CONSTANTS */

#include "defines.h"

/* CONSTANTS */

/* EXPORTED DATA TYPES */

/* EXPORTED ROUTINES */

void SERIAL_SendByte(uint8_t value);
bool SERIAL_ReadByte(uint8_t *value);
void SERIAL_SendMonByte(uint8_t value);
bool SERIAL_ReadMonByte(uint8_t *value);
void SERIAL_Init(void);

#endif
