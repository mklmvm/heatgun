/*
 * iron.h
 *
 *  Created on: Sep 14, 2017
 *      Author: jose
 */

#ifndef GUN_H_
#define GUN_H_

#include "stm32f1xx_hal.h"

typedef void (*setTemperatureReachedCallback)(uint16_t);

typedef enum iron_mode_t {mode_standby, mode_cooling, mode_sleep, mode_set} gun_mode_t;
typedef void (*currentModeChanged)(gun_mode_t);

typedef struct calData {
	uint16_t calADC_At_200;
	uint16_t calADC_At_300;
	uint16_t calADC_At_400;
} calData;

typedef struct gunCoolDown_t {
	uint16_t maxTime;
	uint16_t fanSpeed;
	uint16_t coolDownTemperature;
} gunCoolDown_t;

typedef struct gunSleep_t {
	uint8_t fanSpeed;
	uint16_t temperature;
	uint8_t maxTime;
} gunSleep_t;

gunCoolDown_t currentCoolDownSettings;
gunSleep_t currentSleepSettings;
void setCurrentMode(gun_mode_t mode);
void setSetTemperature(uint16_t temperature);
void setCurrentTemperature(uint16_t temperature);
gun_mode_t getCurrentMode();
uint16_t getSystemSetTemperature();
uint16_t getUserSetTemperature();
uint16_t getCurrentTemperature();
uint16_t getSetTemperature();
uint8_t getCurrentPower();
void setCurrentUserSetFanSpeed(uint8_t speed);
uint8_t getCurrentUserSetFanSpeed();
uint8_t getCurrentFanSpeed();
void addSetTemperatureReachedCallback(setTemperatureReachedCallback callback);
void addModeChangedCallback(currentModeChanged callback);
void handleGun(uint8_t activity);
void gunInit(TIM_HandleTypeDef *fanTim, GPIO_TypeDef *heater_port, uint16_t heater_pin, uint16_t temp, uint8_t fan);

#endif /* GUN_H_ */
