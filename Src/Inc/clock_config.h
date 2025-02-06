/**
 * @file clock_config.h
 * @brief System clock configuration header
 */

#ifndef CLOCK_CONFIG_H
#define CLOCK_CONFIG_H

#include "stm32f4xx_hal.h"

/**
 * @brief Initializes system clock configuration
 * @return None
 * @note Configures voltage scaling, oscillators and clock tree
 */
void ClockConfig(void);

#endif /* CLOCK_CONFIG_H */
