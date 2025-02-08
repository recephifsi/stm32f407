/**
 * @file clock_config.c
 * @brief System clock configuration implementation
 * @details Configures system clocks using HSI with PLL for STM32F4
 */

#include "clock.h"

void Error_Handler(void);

/**
 * @brief Configures voltage scaling for maximum frequency
 * @return HAL status
 * @note Sets voltage scaling to Scale1 mode
 */
static HAL_StatusTypeDef ConfigureVoltageScale(void) {
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    return HAL_OK;
}

/**
 * @brief Configures HSI and PLL
 * @return HAL status
 * @note Uses HSI as clock source with PLL
 */
static HAL_StatusTypeDef ConfigureOscillator(void) {
    const RCC_OscInitTypeDef kOscConfig = {.OscillatorType = RCC_OSCILLATORTYPE_HSI, .HSIState = RCC_HSI_ON, .HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT, .PLL = {.PLLState = RCC_PLL_ON, .PLLSource = RCC_PLLSOURCE_HSI, .PLLM = 8, .PLLN = 64, .PLLP = RCC_PLLP_DIV2, .PLLQ = 4}};

    return HAL_RCC_OscConfig((RCC_OscInitTypeDef*)&kOscConfig);
}

/**
 * @brief Configures system clock tree
 * @return HAL status
 * @note Sets up AHB, APB1, APB2 prescalers
 */
static HAL_StatusTypeDef ConfigureClock(void) {
    RCC_ClkInitTypeDef clockConfig = {.ClockType = (RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2), .SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK, .AHBCLKDivider = RCC_SYSCLK_DIV8, .APB1CLKDivider = RCC_HCLK_DIV2, .APB2CLKDivider = RCC_HCLK_DIV1};

    return HAL_RCC_ClockConfig(&clockConfig, FLASH_LATENCY_0);
}

void ClockInit(void) {
    if (ConfigureVoltageScale() != HAL_OK) {
        Error_Handler();
    }

    if (ConfigureOscillator() != HAL_OK) {
        Error_Handler();
    }

    if (ConfigureClock() != HAL_OK) {
        Error_Handler();
    }
}

void Error_Handler(void) {
    __disable_irq();
    while (1) {
    }
}
