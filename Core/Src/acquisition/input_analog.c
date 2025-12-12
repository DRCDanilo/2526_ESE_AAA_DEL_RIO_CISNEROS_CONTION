/*
 * analog_input.c
 *
 *  Created on: Nov 11, 2025
 *      Author: nicolas
 */

#include "acquisition/input_analog.h"


extern ADC_HandleTypeDef hadc1;


uint32_t data_adc;

uint32_t start_adc()
{
	HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
	HAL_ADC_Start(&hadc1);


	//data_adc = HAL_ADC_GetValue(&hadc1);
	return HAL_ADC_GetValue(&hadc1);

}
