/*
 * BME280.h
 *
 *  Created on: Feb 19, 2026
 *      Author: husey
 */

#ifndef BME280_H_
#define BME280_H_

#include "stm32f4xx_hal.h"

extern float powf(float num1 , float num2);
/*
 * REGISTER DECLARATIONS
 */

#define CSPIN   GPIO_PIN_3
#define CSPORT    GPIOE



/*
 * Will be working with SPI
 */
#define BME_RESET_VALUE			0xB6
#define BME_CHIP_ID_REG			0xD0
#define BME_RESET_REG			0xE0
#define BME_CALIB_00_25_BASE	0x88
#define BME_CALIB_26_41_BASE	0xE1
#define BME_CTRL_HUM_REG		0xF2
#define BME_STATUS_REG			0xF3
#define BME_CTRL_MEAS_REG		0xF4
#define BME_CNFG_REG			0xF5
#define BME_PRESS_MSB			0xF7
#define BME_PRESS_LSB			0xF8
#define BME_PRESS_XLSB			0xF9
#define BME_TMP_MSB				0xFA
#define BME_TMP_LSB				0xFB
#define BME_TMP_xLSB			0xFC
#define BME_HUM_MSB				0xFD
#define BME_HUM_LSB				0xFE



/*
 *
 * BME Status typedef declerations
 *
 */
typedef enum
{
  BME_SPI_ERROR   = HAL_ERROR,
  BME_SPI_OK      = HAL_OK,
  BME_CALIB_OK    = 0b1,
  BME_CALIB_ERROR = 0b0
}BMEStatus_Typedef_t;





/*
 * Will be written bit 7 , 6 , 5 [2:0] for temp
 * Will be written bit 4 , 3 , 2 [2:0] for press
 *Register = CTRL_MEAS(temp + press + Sensor mode)
 * Will be written bit 2 , 1 , 0 [2:0] for humidity
 * Register = CTRL_HUM(OSRS_HUM)
 */
typedef enum{
	OSR_1 	= 0b001,
	OSR_2 	= 0b010,
	OSR_4 	= 0b011,
	OSR_8 	= 0b100,
	OSR_16 	= 0b101
}BME_Osr;


/*
 * REGISTER = CONFIG
 * Bit 4 ,3 , 2 [2:0] IIR Coefficient
 */
typedef enum{
	OFF 	= 0b000,
	TWO 	= 0b001,
	FOUR 	= 0b010,
	EIGHT	= 0b011,
	SIXTEEN	= 0b100
}BME_IIR_Coefficient;




typedef struct
{
	float humidity;
	float temperature;
	float pressure;
}BME_Data_t;



typedef struct{
	SPI_HandleTypeDef *const spihandler;
	void (*BME_Delay)(uint32_t);
	BME_Osr 				press_osr;
	BME_Osr 				tmp_osr;
	BME_Osr					hum_osr;
	BME_IIR_Coefficient 	coefficient;
}BME_Init_Typedef_t;



BMEStatus_Typedef_t 	InitBME_SPI(BME_Init_Typedef_t* dev);
BMEStatus_Typedef_t 	BME_ReadCalibData(BME_Init_Typedef_t* dev);
BME_Data_t			      BME_DataRead(BME_Init_Typedef_t* dev);




static inline float          PressureToHeight(float pressure){

  const float P0 = 1013.25; // Deniz seviyesi basıncı (hPa)
  float height;

  height = 44330.0f * (1.0f - powf((pressure / P0), 0.1902949f));

  return height;

}










#endif /* BME280_H_ */
