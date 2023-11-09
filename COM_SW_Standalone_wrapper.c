
/*
 * Include Files
 *
 */
#include "simstruc.h"



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
//#include "Protocol_SW_Sim_DRIVERS.h"
#include "defines.h"
#include <stdbool.h>
#include "Driver_AS5045.h"
#include "Driver_BLDC.h"
#include "Driver_CLK.h"
#include "Driver_GPIO.h"
#include "Driver_Position.h"
#include "Driver_Serial.h"
#include "Driver_SPI.h"
#include "Driver_Temp.h"
#include "Sw_APP.h"
#include "Driver_WDT.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
// Voltage Variable
uint8_t voltage;
// Temperature Variable
uint8_t Temp_ext;
uint8_t Temp_DataByte =0 ;
uint8_t Temp_DataByte_SERIAL =0 ;
// HALL values
bool HALL1;
bool HALL2;
bool HALL3;
// Register variables
bool Read_Prot_to_COM;
bool Read_SERIAL_register_Rx;
uint8_t RS485_register;
uint8_t SERIAL_register_Rx; // inuse
uint8_t SERIAL_register_Tx; //inuse
uint8_t COM_msg_Byte;
// counter internal use
uint32_t i=0;
// CRC MSG
// bool FCC_Msg_Received;
uint8_t CRC_msg;
// Register Prot to Com
uint8_t rx_index;


/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void COM_SW_Standalone_Start_wrapper(SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */  
  // Run_SW_APP();
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void COM_SW_Standalone_Outputs_wrapper(const boolean_T *HALL_1,
			const boolean_T *HALL_2,
			const boolean_T *HALL_3,
			const uint8_T *Output_Shaft_Sensor,
			const uint8_T *Power_Supply,
			const uint8_T *MON_to_COM,
			const uint8_T *Prot_to_COM_input,
			uint8_T *COM_to_MON,
			boolean_T *COM_to_Prot,
			boolean_T *Output_IN_1,
			boolean_T *Output_IN_2,
			boolean_T *Output_IN_3,
			boolean_T *Output_EN_1,
			boolean_T *Output_EN_2,
			boolean_T *Output_EN_3,
			uint8_T *DBG_POST_CMD,
			uint8_T *DBG_POST_ERROR,
			uint8_T *DBG_CRC,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// GPIO
    HALL1= *HALL_1;
    HALL2= *HALL_2;
    HALL3= *HALL_3;
    
// CMP
voltage = *Power_Supply;


// SERIAL
    SERIAL_register_Rx = *Prot_to_COM_input; // DONE
     Read_SERIAL_register_Rx = *Read_Prot_to_COM ; // DONE

    //RS485
  // RS485_register = *RS485_Input;
    // Read_RS485_register = *Read_RS485_Input;
    
// TEMP
   // Temp_ext = *TEMP_Sensor;
   // *DBG_TEMP_Output = (boolean_T)TEMP_IsOver();
// MAIN
    if (i==0){
    
        i=i+1;}
else {
  // Run_SW_APP();
i=i+1;} 
Run_PBIT();
   
    //SERIAL_register_Tx = *Prot_to_COM;
    *COM_to_Prot = SERIAL_register_Tx; 
    // *Motor_Enabler = (Activate_Motor || CMP_IsSet());
   // *DBG_frame =i;
   *DBG_CRC = CRC_msg;

/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


