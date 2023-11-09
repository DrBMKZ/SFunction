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

#ifndef DEFINES_H
#define DEFINES_H

/* IMPORTED MODULES FOR TYPES AND CONSTANTS */

#include "platform.h"
#include "types.h"

/* CONSTANTS */

// Position of the integrity CRC in ROM
#define APP_CRC_ADDRESS        0x6E00
#define APP_LENGTH					   0x2000
#define APP_START              0x0000

// Maintenance mode ID
#define HPP_ID_MAINT           0xFFU

/* Halls maximal value */
#define HALL_VALUE_LAST        8

// Signature bytes for communication with Protocol CPU
#define SIGN_READY_TO_RECEIVE  0xA5U
#define SIGN_RESEND_MSG        0x5AU

// BLDC commutation state
enum E_BLDC_STATE {   //lint !e8101
  BLDC_STATE_OFF,
  BLDC_STATE_ALBH,
  BLDC_STATE_ALCH,
  BLDC_STATE_BLAH,
  BLDC_STATE_BLCH,
  BLDC_STATE_CLAH,
  BLDC_STATE_CLBH,
  BLDC_STATE_LAST
};

// Motor direction
enum E_MOTOR_DIR {    //lint !e8101
  MOTOR_DIR_CW,
  MOTOR_DIR_CCW
};

#define COM_BIT_POS_CALIBR_CRC_FAULT    (1UL << 0U)
#define COM_BIT_SW_CRC_FAULT            (1UL << 1U)
#define COM_BIT_CPU_OVERTEMP_FAULT      (1UL << 2U)
#define COM_BIT_MOTOR_OVERTEMP_FAULT    (1UL << 3U)
#define COM_BIT_HALL_SENSORS_FAULT      (1UL << 4U)
#define COM_BIT_POS_FRESHNESS_FAULT     (1UL << 5U)
#define COM_BIT_MAGNETIC_FIELD_FAULT    (1UL << 6U)
#define COM_BIT_PROT_LINK_FAULT         (1UL << 7U)

/* EXPORTED DATA TYPES */

typedef struct T_InPID {    //lint !e9058
  int16_t real_pos;
  int16_t target_pos;
} T_InPID;

typedef struct T_OutPID {   //lint !e9058
  uint8_t power;
  uint8_t dir;
} T_OutPID;

typedef struct T_ProtMsg {  //lint !e9058
  uint16_t Pos_Cmd;
  uint8_t  Prot_BIT;
  uint8_t  Spare;
  uint8_t  Actuator_ID;
  uint8_t  CRC;
} T_ProtMsg;

typedef struct T_ComMsg {   //lint !e9058
  uint8_t  Prot_BIT;
  uint8_t  Spare1;
  uint8_t  Actuator_ID;
  uint8_t  COM_BIT;
  uint8_t  Spare2;
  uint8_t  Torque;
  uint8_t  Spare_Lifecycle1;
  uint8_t  Spare_Lifecycle2;
  uint8_t  CRC;
} T_ComMsg;

/* EXPORTED ROUTINES */

#endif
