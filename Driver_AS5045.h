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

#ifndef DRV_AS5045_H
#define DRV_AS5045_H

/* IMPORTED MODULES FOR TYPES AND CONSTANTS */

#include "defines.h"

/* CONSTANTS */

#define AS5045_DATA_LENGTH    12U
#define AS5045_STATUS_LENGTH  6U

#define AS5045_STS_OCF        (1UL << 5U)
#define AS5045_STS_COF        (1UL << 4U)
#define AS5045_STS_LIN        (1UL << 3U)
#define AS5045_STS_INC        (1UL << 2U)
#define AS5045_STS_DEC        (1UL << 1U)
#define AS5045_STS_PAR        (1UL << 0U)

#define AS5045_ERR_MASK       (AS5045_STS_OCF | AS5045_STS_COF | AS5045_STS_LIN)
#define AS5045_VALUE_OK       (AS5045_STS_OCF)

#define POSITION_RESOLUTION   4096

/* EXPORTED DATA TYPES */

/* EXPORTED ROUTINES */

bool POSITION_Read(int16_t *pos);   //lint !e2467
void POSITION_Init(void);           //lint !e2467

#endif
