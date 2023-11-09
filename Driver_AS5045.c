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
/* Position sensor: AS5045                                           */
/*                                                                   */
/*********************************************************************/
#ifdef DEF_AS5045
/* IMPORTED MODULES */

#include "drivers.h"

/* CONSTANTS */

/* Short delay for position sensor readout */
#define POSITION_DELAY  { _nop_ (); _nop_ (); _nop_ (); _nop_ (); \
                          _nop_ (); _nop_ (); _nop_ (); _nop_ (); \
                          _nop_ (); _nop_ (); _nop_ (); _nop_ (); \
                          _nop_ (); _nop_ (); _nop_ (); _nop_ (); \
                          _nop_ (); _nop_ (); _nop_ (); _nop_ (); }

/* MODULE DATA */

/* ROUTINES */

/**********************************************************************/
/* POSITION_ReceiveData                                               */
/*                                                                    */
/* Receive serial data from magnet sensor                             */
/*                                                                    */
/* [in] bits Number of bits to receive                                */
/* Returns Received value                                             */
/*                                                                    */
/**********************************************************************/
static uint16_t POSITION_ReceiveData(uint8_t bits)
{
//   uint16_t dout = 0U;
// 
//   while (bits > 0U)
//   {
//     P_CLEAR(SPI_SCLK_PORT, SPI_SCLK_PIN);
//     bits--;
//     dout <<= 1U;
//     //AS5045_DELAY_LONG;
//     P_SET(SPI_SCLK_PORT, SPI_SCLK_PIN);
//     POSITION_DELAY;
//     if (P_IN(SPI_MISO_PORT, SPI_MISO_PIN) > 0U)
//     {
//       dout++;
//     }
//   }
// 
//   return dout;
}

/**********************************************************************/
/* POSITION_GetParity                                                 */
/*                                                                    */
/* Check parity of received data, must be even                        */
/*                                                                    */
/* [in] value Data value to check                                     */
/* Returns Number of "1"                                              */
/*                                                                    */
/**********************************************************************/
static uint8_t POSITION_GetParity(uint16_t value)
{
//   uint8_t result = 0;
//   while (value > 0U)
//   {
//     value &= (value - 1U);
//     result = 1U - result;
//   }
//   return result;
}

/**********************************************************************/
/* POSITION_Read                                                      */
/*                                                                    */
/* Read data from position sensor via SPI                             */
/*                                                                    */
/* Returns Raw value from position sensor                             */
/*                                                                    */
/* {"Trace:SDD_VCA_0705-433;"}                                        */
/*                                                                    */
/**********************************************************************/ 
bool POSITION_Read(int16_t *pos)  //lint !e2467
{
//   uint16_t value;
//   uint8_t status_bits;
//   uint8_t parity;
// 
//   P_CLEAR(SPI_CS_PORT, SPI_CS_PIN);
//   POSITION_DELAY;
//   value = POSITION_ReceiveData(AS5045_DATA_LENGTH);
//   status_bits = (uint8_t)POSITION_ReceiveData(AS5045_STATUS_LENGTH);
//   P_SET(SPI_CS_PORT, SPI_CS_PIN);
// 
//   parity = POSITION_GetParity(value);
//   parity += POSITION_GetParity(status_bits);
// 
//   if ((parity % 2U) != 0U)
//   {
//     return false;
//   }
// 
//   if ((status_bits & AS5045_ERR_MASK) != AS5045_VALUE_OK)
//   {
//     /**< (OCF != 1) || (COF != 0) || (LIN != 0) */
//     return false;
//   }
// 
//   // Invert value because of the rotation direction, bugfix
//   value = value ^ 0xFFFU;
//   // Convert position to normalized signed format
//   *pos = (int16_t)value - 0x800;
// 
//   return true;
}

/**********************************************************************/
/* POSITION_Init                                                      */
/*                                                                    */
/* Initialize position sensor module                                  */
/*                                                                    */
/**********************************************************************/
void POSITION_Init(void)    //lint !e2467
{
//   uint8_t SFRPAGE_save = SFRPAGE;
// 
//   SFRPAGE = CONFIG_PAGE;
//   // Enable SPI pins as outputs (SCLK, MOSI, CS)
//   P_DIR_OUT(SPI_SCLK_PORT, SPI_SCLK_PIN);
//   P_DIR_OUT(SPI_MOSI_PORT, SPI_MOSI_PIN);
//   P_DIR_OUT(SPI_CS_PORT, SPI_CS_PIN);
//   // Enable pins as digital IOs (SCLK, MOSI, MISO, CS)
//   P_DIG_IO(SPI_SCLK_PORT, SPI_SCLK_PIN);
//   P_DIG_IO(SPI_MOSI_PORT, SPI_MOSI_PIN);
//   P_DIG_IO(SPI_CS_PORT, SPI_CS_PIN);
//   P_DIG_IO(SPI_MISO_PORT, SPI_MISO_PIN);
//   // disable SPI CS pin
//   P_SET(SPI_CS_PORT, SPI_CS_PIN);
// 
//   SFRPAGE = SFRPAGE_save;
}
#endif
