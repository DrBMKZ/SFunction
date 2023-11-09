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
/* It needs to take into account that UART0 has a 3-byte deep FIFO   */
/* buffer that cannot be controlled                                  */
/*                                                                   */
/*********************************************************************/

/* IMPORTED MODULES */

#include "Driver_Serial.h"

/* CONSTANTS */
extern uint8_t SERIAL_register_Rx;
extern uint8_t SERIAL_register_Tx;
// #define SERIAL_BAUDRATE       115200U
// #define SERIAL_TIMER_VALUE    (0x100U - (CPU_CLOCK / (SERIAL_BAUDRATE * 2U)))

/* MODULE DATA */

/* ROUTINES */

/**********************************************************************/
/* SERIAL_SendByte                                                    */
/*                                                                    */
/* Send one byte to UART                                              */
/*                                                                    */
/* [in] value Byte to send                                            */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
void SERIAL_SendByte(uint8_t value)
{
SERIAL_register_Tx = value;
}

/**********************************************************************/
/* SERIAL_ReadByte                                                    */
/*                                                                    */
/* Read one byte from UART                                             */
/*                                                                    */
/* [in] value Pointer to byte to read in                              */
/* Returns True if received, False otherwise                          */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
bool SERIAL_ReadByte(uint8_t *value)
{
*value = SERIAL_register_Rx ;

 if (Temp_DataByte_SERIAL == SERIAL_register_Rx ) {
     
     return false;
           
    }

else{

    Temp_DataByte_SERIAL = SERIAL_register_Rx ;
    return true;}
}

/**********************************************************************/
/* SERIAL_SendMonByte                                                 */
/*                                                                    */
/* Send one byte to MON UART                                          */
/*                                                                    */
/* [in] value Byte to send                                            */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
void SERIAL_SendMonByte(uint8_t value)
{

}

/**********************************************************************/
/* SERIAL_ReadMonByte                                                 */
/*                                                                    */
/* Read one byte from MON UART                                        */
/*                                                                    */
/* [in] value Pointer to byte to read in                              */
/* Returns True if received, False otherwise                          */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
bool SERIAL_ReadMonByte(uint8_t *value)
{

}
  
/**********************************************************************/
/* SERIAL_Init                                                        */
/*                                                                    */
/* Initialize serial communication module                             */
/*                                                                    */
/* {"Trace:SDD_VCA_0705-831; SDD_VCA_0705-677"}                       */
/*                                                                    */
/**********************************************************************/
void SERIAL_Init(void)
{

}
