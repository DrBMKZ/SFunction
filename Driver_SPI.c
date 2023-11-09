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
/* SPI is a low-level driver to send/receive data via SPI bus,       */
/* software SPI was too slow                                         */
/*                                                                   */
/*********************************************************************/

/* IMPORTED MODULES */

#include "Driver_GPIO.h"
#include "Driver_SPI.h"

/* CONSTANTS */

#define SPI_BITRATE           4000000U
#define SPI_CKR_VALUE         ((CPU_CLOCK / (SPI_BITRATE * 2U)) - 1U)

/* MODULE DATA */

/* ROUTINES */

/**********************************************************************/
/* SPI_ExchangeData                                                   */
/*                                                                    */
/* Send/receive data byte via SPI bus                                 */
/*                                                                    */
/* [in] tx_data Byte to transmit to SPI bus                           */
/* Returns 1 byte read from SPI bus                                   */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
uint8_t SPI_ExchangeData(uint8_t tx_data)
{
//   SPI0DAT = tx_data;
//   while (!SPIF) {}
//   SPIF = 0;
//   return SPI0DAT;
}

/**********************************************************************/
/* SPI_Init                                                           */
/*                                                                    */
/* Initialize SPI hardware module                                     */
/*                                                                    */
/* {"Trace:SDD_Req_1;"}                                               */
/*                                                                    */
/**********************************************************************/
void SPI_Init(void)
{
//   uint8_t SFRPAGE_save = SFRPAGE;
// 
//   SFRPAGE = CONFIG_PAGE;
//   // Enable SPI pins as outputs (SCLK, MOSI, CS)
//   //P1MDOUT |= (1UL << SPI_SCLK_PIN) | (1UL << SPI_MOSI_PIN) |
//   //           (1UL << SPI_CS_PIN);
//   P_DIR_OUT(SPI_SCLK_PORT, SPI_SCLK_PIN);
//   P_DIR_OUT(SPI_MOSI_PORT, SPI_MOSI_PIN);
//   P_DIR_OUT(SPI_CS_PORT, SPI_CS_PIN);
//   // Enable pins as digital IOs (SCLK, MOSI, MISO, CS)
//   //P1MDIN |= (1UL << SPI_SCLK_PIN) | (1UL << SPI_MOSI_PIN) |
//   //          (1UL << SPI_CS_PIN) | (1UL << SPI_MISO_PIN);
//   P_DIG_IO(SPI_SCLK_PORT, SPI_SCLK_PIN);
//   P_DIG_IO(SPI_MOSI_PORT, SPI_MOSI_PIN);
//   P_DIG_IO(SPI_CS_PORT, SPI_CS_PIN);
//   P_DIG_IO(SPI_MISO_PORT, SPI_MISO_PIN);
//   // disable SPI CS pin
//   //P1 |= (1UL << SPI_CS_PIN);
//   P_SET(SPI_CS_PORT, SPI_CS_PIN);
// 
//   // Initialize hardware SPI
//   SFRPAGE = ACTIVE_PAGE;  //lint !e838
//   // Enable the SPI as a Master, CKPHA = '1', CKPOL = '0'
//   SPI0CFG = (1UL << 6U) | (1UL << 5U);
//   // 3-wire Single Master, SPI enabled
//   SPI0CN = (1UL << 0U);
//   // SPI clock frequency
//   SPI0CKR = SPI_CKR_VALUE;
// 
//   // Enable the SPI on the XBAR
//   SFRPAGE = CONFIG_PAGE;  //lint !e838
//   XBR0 |= (1UL << 2U);
// 
//   SFRPAGE = SFRPAGE_save;
}
