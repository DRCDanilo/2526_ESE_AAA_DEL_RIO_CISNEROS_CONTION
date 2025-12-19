/*
 * motor.h
 *
 *  Created on: Nov 11, 2025
 *      Author: nicolas
 */

#ifndef INC_MOTOR_CONTROL_MOTOR_H_
#define INC_MOTOR_CONTROL_MOTOR_H_

void motor_set_ccr(int duty_cycle);
void motor_init();
void motor_start();
void motor_stop();

#endif /* INC_MOTOR_CONTROL_MOTOR_H_ */
