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

#ifndef DRV_GPIO_H
#define DRV_GPIO_H

/* IMPORTED MODULES FOR TYPES AND CONSTANTS */

#include "defines.h"

/* CONSTANTS */

// Hall inputs
#define HA_PORT         P2
#define HB_PORT         P2
#define HC_PORT         P2
#define HA_PIN          5U
#define HB_PIN          6U
#define HC_PIN          7U

// SPI pins: CS, MISO, MOSI, SCLK
#define SPI_CS_PORT     P1
#define SPI_SCLK_PORT   P1
#define SPI_MISO_PORT   P1
#define SPI_MOSI_PORT   P1
#define SPI_CS_PIN      3U
#define SPI_SCLK_PIN    0U
#define SPI_MISO_PIN    1U
#define SPI_MOSI_PIN    2U

// Driver fault pin
#define DRV_FAULT_PORT  P3
#define DRV_FAULT_PIN   0U

// TICK pin
#define TICK_PORT       P4
#define TICK_PIN        0U

// ADC pins
#define ADC_TEMP_PIN    0U

// BLDC pins
#define BLDC_PORT       P3
#define BLDC_SKIP       P3SKIP

/* EXPORTED DATA TYPES */

/* EXPORTED ROUTINES */

uint8_t GPIO_ReadHalls(void);
void GPIO_Init(void);

#endif
