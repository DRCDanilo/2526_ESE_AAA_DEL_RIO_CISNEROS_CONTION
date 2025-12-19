/*
 * motor.c
 *
 *  Created on: Nov 11, 2025
 *      Author: nicolas
 */

#include "motor_control/motor.h"
#include "tim.h"

#define CCR_SPEED_ZERO 50
#define CCRR1


void motor_init(int duty_cycle)
{
	int CCR1 = (htim1.Init.Period * duty_cycle)/100;
	int CCR2 = htim1.Init.Period - CCR1;

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, CCR1);//1020
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, CCR2);//680
}

void start()
{

	int CCR1 = (htim1.Init.Period * CCR_SPEED_ZERO)/100;
	int CCR2 = htim1.Init.Period - CCR1;

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, CCR1);//1020
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, CCR2);//680
}

void stop()
{
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2);
}
