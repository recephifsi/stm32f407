/**
 * @file gpio_config.h
 * @brief GPIO configuration and LED control functions
 * @details Contains GPIO initialization and LED control functionalities for STM32F4
 * @author Your Name
 * @date 2025
 */

#ifndef INC_GPIO_CONFIG_H_
#define INC_GPIO_CONFIG_H_

#include "stm32f4xx_hal.h"

/**
 * @brief Creates sequential LED pattern
 * @return None
 */
void BlinkLeds(void);

/**
 * @brief Initializes GPIO configuration
 */
void GpioConfig(void);

#endif /* INC_GPIO_CONFIG_H_ */
