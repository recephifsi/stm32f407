/**
 * @file gpio_config.h
 * @brief GPIO configuration and LED control functions
 * @details Contains GPIO initialization and LED control functionalities for STM32F4
 * @author Your Name
 * @date 2025
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f4xx_hal.h"

#define kLedPort GPIOD         /**< LED port */
#define kRedLedPin GPIO_PIN_14    /**< Red LED pin */
#define kBlueLedPin GPIO_PIN_15   /**< Blue LED pin */
#define kGreenLedPin GPIO_PIN_12  /**< Green LED pin */
#define kOrangeLedPin GPIO_PIN_13 /**< Orange LED pin */

#define kUserButtonPort GPIOA     /**< User button port */
#define kUserButtonPin GPIO_PIN_0 /**< User button pin */

/**
 * @brief Initializes GPIO configuration
 */
void GpioInit(void);

/**
 * @brief Non-blocking delay function
 * @param delay Delay duration in milliseconds
 */
void Delay(uint32_t delay);

/**
 * @brief Turn on specified LED
 * @param port GPIO port
 * @param pin LED pin number
 */
void LedOn(GPIO_TypeDef* port, uint16_t pin);

/**
 * @brief Turn off specified LED
 * @param port GPIO port
 * @param pin LED pin number
 */
void LedOff(GPIO_TypeDef* port, uint16_t pin);

/**
 * @brief Read GPIO pin state with debounce
 * @param port GPIO port
 * @param pin GPIO pin number
 * @return GPIO_PinState Current pin state after debounce
 * @note Uses 50ms debounce interval
 */
GPIO_PinState ReadPin(GPIO_TypeDef* port, uint16_t pin);

#endif /* INC_GPIO_H_ */
