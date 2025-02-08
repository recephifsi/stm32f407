/**
 * @file gpio_config.h
 * @brief GPIO configuration header
 */

#include "gpio.h"

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
static void ConfigurePins(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = (kRedLedPin | kBlueLedPin | kGreenLedPin | kOrangeLedPin);
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_WritePin(kLedPort, (kRedLedPin | kBlueLedPin | kGreenLedPin | kOrangeLedPin), GPIO_PIN_RESET);
    HAL_GPIO_Init(kLedPort, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = kUserButtonPin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(kUserButtonPort, &GPIO_InitStruct);
}

void GpioInit(void) {
    EnableGpioClocks();
    ConfigurePins();
}

void LedOn(GPIO_TypeDef* port, uint16_t pin) { HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET); }

void LedOff(GPIO_TypeDef* port, uint16_t pin) { HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET); }

void Delay(uint32_t delay) { HAL_Delay(delay); }

GPIO_PinState ReadPin(GPIO_TypeDef* port, uint16_t pin) {
    static uint32_t lastDebounceTime = 0;
    static GPIO_PinState lastState = GPIO_PIN_RESET;
    const uint32_t kDebounceInterval = 50;

    GPIO_PinState currentState = HAL_GPIO_ReadPin(port, pin);

    if (currentState != lastState) {
        if ((HAL_GetTick() - lastDebounceTime) >= kDebounceInterval) {
            lastState = currentState;
            lastDebounceTime = HAL_GetTick();
        }
    }

    return lastState;
}
