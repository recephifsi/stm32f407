/**
 * @file app.h
 * @brief Application initialization header
 */

#ifndef INC_APP_H_
#define INC_APP_H_

#include "gpio.h"
#include "stm32f4xx_hal.h"

/**
 * @brief Initializes core application components
 * @details Performs HAL, Clock and GPIO initialization sequence
 * @note Must be called at startup before any other operations
 */
void AppInit(void);

#endif /* INC_APP_H_ */
