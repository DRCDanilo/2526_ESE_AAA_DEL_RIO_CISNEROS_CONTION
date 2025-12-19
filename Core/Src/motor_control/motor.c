/*
 * motor.c
 *
 *  Created on: Nov 11, 2025
 *      Author: nicolas
 */

#include "motor_control/motor.h"
#include "tim.h"

#define PERCENTAGE_DIVIDER 100
#define CCR_SPEED_ZERO 50

static int CCR1;
static int CCR2;


void motor_init()
{
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
}

void motor_set_ccr(int duty_cycle)
{
	CCR1 = (htim1.Init.Period * duty_cycle)/PERCENTAGE_DIVIDER;
	CCR2 = htim1.Init.Period - CCR1;

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, CCR1);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, CCR2);
}


void motor_start()
{

	CCR1 = (htim1.Init.Period * CCR_SPEED_ZERO)/PERCENTAGE_DIVIDER;
	CCR2 = htim1.Init.Period - CCR1;

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, CCR1);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, CCR2);
}

void motor_stop()
{
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2);
}
