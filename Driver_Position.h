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

#ifndef DRV_POSITION_H
#define DRV_POSITION_H

/* IMPORTED MODULES FOR TYPES AND CONSTANTS */

#include "defines.h"

/* CONSTANTS */

#define AS5047_DATA_LENGTH    16U
#define AS5047_POS_LENGTH     14U

#define AS5047_PARITY_BIT     (1UL << 15U)
#define AS5047_ERROR_BIT      (1UL << 14U)

#define AS5047_CMD_READ_BIT   (1UL << 14U)

#define AS5047_POS_MASK       ((1UL << AS5047_POS_LENGTH) - 1U)

#define AS5047_READ_POS_CMD     0xFFFFU
#define AS5047_READ_ERRFL_CMD   0x4001U

#define POSITION_RESOLUTION     16384

/* EXPORTED DATA TYPES */

/* EXPORTED ROUTINES */

bool POSITION_Read(int16_t *pos);
void POSITION_Init(void);

#endif
