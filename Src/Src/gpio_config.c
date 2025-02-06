/**
 * @file gpio_config.h
 * @brief GPIO configuration header
 */

#include "gpio_config.h"

/**
 * @brief LED pin definitions
 * @note Maps each LED color to its corresponding GPIO pin
 */
typedef enum {
    kOrange = GPIO_PIN_13,
    kRed = GPIO_PIN_14,
    kBlue = GPIO_PIN_15,
    kGreen = GPIO_PIN_12,
} led_t;

/**
 * @brief Enables required GPIO port clocks
 * @note Private function for internal use
 */
static void EnableGpioClocks(void) {
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
}

/**
 * @brief Configures LED GPIO pins
 * @return None
 */
static void ConfigureLedPins(void) {
    GPIO_TypeDef* kLedPort = GPIOD;
    const uint16_t kLedPins = (GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);

    GPIO_InitTypeDef GPIO_InitStruct = {.Pin = kLedPins, .Mode = GPIO_MODE_OUTPUT_PP, .Pull = GPIO_NOPULL, .Speed = GPIO_SPEED_FREQ_LOW};

    HAL_GPIO_WritePin(kLedPort, kLedPins, GPIO_PIN_RESET);
    HAL_GPIO_Init(kLedPort, &GPIO_InitStruct);
}

void GpioConfig(void) {
    EnableGpioClocks();
    ConfigureLedPins();
}

void BlinkLeds(void) {
    HAL_GPIO_WritePin(GPIOD, kOrange, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kRed, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kBlue, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kGreen, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kGreen, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kBlue, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kRed, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, kOrange, GPIO_PIN_RESET);
    HAL_Delay(100);
}
