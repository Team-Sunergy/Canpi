#ifndef interpret_CAN_H
#define interpret_CAN_H

#include <stdint.h>


// Function Declarations
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
void interpretMessage(uint8_t canId, uint8_t messageBuf[], int bufferSize, char** retStr, int* retValues, char** retType, int* numRetValues);
void retreiveTwo32BitNums(uint8_t messageBuf[], int *num1, int *num2);
void convertAndScaleIntToFloat(int *originalInt, float scale);
int isValidMessageLength(uint8_t canId, uint32_t expectedLength, uint32_t actualLength);
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// CAN Message ID Constants
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
#define CAN_ID_BPS_FRAME0 0xA
#define CAN_ID_BPS_FRAME1 0xB
#define CAN_ID_BPS_FRAME2 0xC
#define CAN_ID_BPS_FRAME3 0xD
#define CAN_ID_MOTOR_CONTROLLER_BASE 0xE0 //Temporary, real base address is not known
#define CAN_ID_MOTOR_CONTROLLER_FRAME0 CAN_ID_MOTOR_CONTROLLER_BASE+0x0 
#define CAN_ID_MOTOR_CONTROLLER_FRAME1 CAN_ID_MOTOR_CONTROLLER_BASE+0x1 
#define CAN_ID_MOTOR_CONTROLLER_FRAME2 CAN_ID_MOTOR_CONTROLLER_BASE+0x2 
#define CAN_ID_MOTOR_CONTROLLER_FRAME3 CAN_ID_MOTOR_CONTROLLER_BASE+0x3 
#define CAN_ID_MOTOR_CONTROLLER_FRAME4 CAN_ID_MOTOR_CONTROLLER_BASE+0x4 
#define CAN_ID_MOTOR_CONTROLLER_FRAME5 CAN_ID_MOTOR_CONTROLLER_BASE+0x5 
#define CAN_ID_MOTOR_CONTROLLER_FRAME6 CAN_ID_MOTOR_CONTROLLER_BASE+0x6 
#define CAN_ID_MOTOR_CONTROLLER_FRAME7 CAN_ID_MOTOR_CONTROLLER_BASE+0x7 
#define CAN_ID_MOTOR_CONTROLLER_FRAME8 CAN_ID_MOTOR_CONTROLLER_BASE+0x8 
#define CAN_ID_MOTOR_CONTROLLER_FRAME9 CAN_ID_MOTOR_CONTROLLER_BASE+0x9 
#define CAN_ID_MOTOR_CONTROLLER_FRAME10 CAN_ID_MOTOR_CONTROLLER_BASE+0xA 
#define CAN_ID_MOTOR_CONTROLLER_FRAME11 CAN_ID_MOTOR_CONTROLLER_BASE+0xB 
#define CAN_ID_MOTOR_CONTROLLER_FRAME12 CAN_ID_MOTOR_CONTROLLER_BASE+0xC 
#define CAN_ID_MOTOR_CONTROLLER_FRAME13 CAN_ID_MOTOR_CONTROLLER_BASE+0xD 
#define CAN_ID_MOTOR_CONTROLLER_FRAME14 CAN_ID_MOTOR_CONTROLLER_BASE+0xE  
#define CAN_ID_MOTOR_CONTROLLER_FRAME15 CAN_ID_MOTOR_CONTROLLER_BASE+0x17
#define CAN_ID_THERMISTOR_FRAME0 0x80
#define CAN_ID_THERMISTOR_FRAME1 0x81
#define CAN_ID_THERMISTOR_FRAME2 0x82
#define CAN_ID_MPPT_FRAME0 0xC0
#define CAN_ID_MPPT_FRAME1 0xC1
#define CAN_ID_MPPT_FRAME2 0xC2
#define CAN_ID_MPPT_FRAME3 0xC3

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// CAN Message Data Length
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
#define CAN_ID_BPS_FRAME0_LEN 7
#define CAN_ID_BPS_FRAME1_LEN 8
#define CAN_ID_BPS_FRAME2_LEN 7
#define CAN_ID_BPS_FRAME3_LEN 7
#define CAN_ID_MOTOR_CONTROLLER_FRAME0_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME1_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME2_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME3_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME4_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME5_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME6_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME7_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME8_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME9_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME10_LEN 0
#define CAN_ID_MOTOR_CONTROLLER_FRAME11_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME12_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME13_LEN 0
#define CAN_ID_MOTOR_CONTROLLER_FRAME14_LEN 8
#define CAN_ID_MOTOR_CONTROLLER_FRAME15_LEN 8
#define CAN_ID_THERMISTOR_FRAME0_LEN 4
#define CAN_ID_THERMISTOR_FRAME1_LEN 4
#define CAN_ID_THERMISTOR_FRAME2_LEN 8
#define CAN_ID_MPPT_FRAME_LEN 8
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//BPS Definitions
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
#define BPS_HIGH_CELL_VOLTAGE_HIGH_BYTE 0
#define BPS_HIGH_CELL_VOLTAGE_LOW_BYTE  1
#define BPS_LOW_CELL_VOLTAGE_HIGH_BYTE 	2
#define BPS_LOW_CELL_VOLTAGE_LOW_BYTE   3
#define BPS_PACK_AMPHOURS_HIGH_BYTE 0
#define BPS_PACK_AMPHOURS_LOW_BYTE  1
#define BPS_PACK_HEALTH_BYTE 3
#define BPS_TOTAL_PACK_CYCLES_HIGH_BYTE 4
#define BPS_TOTAL_PACK_CYCLES_LOW_BYTE  5
#define BPS_HIGHEST_CELL_TEMPERATURE_BYTE 0
#define BPS_LOWEST_CELL_TEMPERATURE_BYTE  2
#define BPS_AVERAGE_CELL_TEMPERATURE_BYTE 4
#define BPS_INTERNAL_BPS_TEMPERATURE_BYTE 5
#define BPS_PACK_CURRENT_HIGH_BYTE 0
#define BPS_PACK_CURRENT_LOW_BYTE  1
#define BPS_PACK_INSTANTANEOUS_VOLTAGE_HIGH_BYTE 2
#define BPS_PACK_INSTANTANEOUS_VOLTAGE_LOW_BYTE  3
#define BPS_PACK_SUMMED_VOLTAGE_HIGH_BYTE 4
#define BPS_PACK_SUMMED_VOLTAGE_LOW_BYTE  5
#define BPS_HIGH_CELL_VOLTAGE_SCALE 0.0001f
#define BPS_LOW_CELL_VOLTAGE_SCALE 0.0001f
#define BPS_PACK_AMPHOURS_SCALE 0.1f
#define BPS_PACK_CURRENT_SCALE 0.1f
#define BPS_PACK_INSTANTANEOUS_VOLTAGE_SCALE 0.1f
#define BPS_PACK_SUMMED_VOLTAGE_SCALE 0.01f
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//Motor Controller Definitions
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
#define MOTOR_CONTROLLER_RECEIVE_ERROR_COUNT_BYTE 0
#define MOTOR_CONTROLLER_TRANSMIT_ERROR_COUNT_BYTE 1
#define MOTOR_CONTROLLER_ACTIVE_MOTOR_HIGH_BYTE 2
#define MOTOR_CONTROLLER_ACTIVE_MOTOR_LOW_BYTE  3
#define MOTOR_CONTROLLER_ERROR_FLAGS_HIGH_BYTE 4
#define MOTOR_CONTROLLER_ERROR_FLAGS_LOW_BYTE  5
#define MOTOR_CONTROLLER_LIMIT_FLAGS_HIGH_BYTE 6
#define MOTOR_CONTROLLER_LIMIT_FLAGS_LOW_BYTE  7
#define MOTOR_CONTROLLER_ERROR_MOTOR_OVER_SPEED_BIT 7
#define MOTOR_CONTROLLER_ERROR_DESATURATION_FAULT_BIT 6
#define MOTOR_CONTROLLER_ERROR_UVLO_BIT 5 //15V rail under voltage lock out
#define MOTOR_CONTROLLER_ERROR_CONFIG_READ_ERROR_BIT 4
#define MOTOR_CONTROLLER_ERROR_WATCHDOG_CAUSED_LAST_RESET_BIT 3
#define MOTOR_CONTROLLER_ERROR_BAD_MOTOR_POSITION_BIT 2
#define MOTOR_CONTROLLER_ERROR_DC_BUS_OVER_VOLTAGE_BIT 1
#define MOTOR_CONTROLLER_ERROR_SOFTWARE_OVER_CURRENT_BIT 0
#define MOTOR_CONTROLLER_LIMIT_TEMPERATURE_BIT 6
#define MOTOR_CONTROLLER_LIMIT_BUS_VOLTAGE_LOWER_LIMIT_BIT 5
#define MOTOR_CONTROLLER_LIMIT_BUS_VOLTAGE_UPPER_LIMIT_BIT 4
#define MOTOR_CONTROLLER_LIMIT_CURRENT_BIT 3
#define MOTOR_CONTROLLER_LIMIT_VELOCITY_BIT 2
#define MOTOR_CONTROLLER_LIMIT_MOTOR_CURRENT_BIT 1
#define MOTOR_CONTROLLER_LIMIT_OUTPUT_VOLTAGE_PWM_BIT 0
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//MPPT Definitions
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
#define MPPT_ARRAY_VOLTAGE_HIGH_BYTE 1
#define MPPT_ARRAY_VOLTAGE_LOW_BYTE  0
#define MPPT_ARRAY_CURRENT_HIGH_BYTE 3
#define MPPT_ARRAY_CURRENT_LOW_BYTE  2
#define MPPT_BATTERY_VOLTAGE_HIGH_BYTE 5
#define MPPT_BATTERY_VOLTAGE_LOW_BYTE  4
#define MPPT_UNIT_TEMPERATURE_HIGH_BYTE 7
#define MPPT_UNIT_TEMPERATURE_LOW_BYTE  6
#define MPPT_ARRAY_VOLTAGE_SCALE 0.01f
#define MPPT_ARRAY_CURRENT_SCALE 0.001f
#define MPPT_BATTERY_VOLTAGE_SCALE 0.01f
#define MPPT_UNIT_TEMPERATURE_SCALE 0.01f
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//MISC Definitions
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
#define NUM_BITS_IN_BYTE 8
#define FOUR_BYTES 4
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


#endif
