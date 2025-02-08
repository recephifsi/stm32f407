#include "timer.h"
#include "gpio.h"

TIM_HandleTypeDef htim1;

/**
 * @brief Enable Timer1 clock and configure its interrupt
 * @retval None
 */
static void Tim1EnableClockAndInterrupt(void) {
    __HAL_RCC_TIM1_CLK_ENABLE();
    HAL_NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
}

/**
 * @brief Configure Timer1 base parameters
 * @param htim: Timer handle pointer
 * @retval HAL_StatusTypeDef
 */
static HAL_StatusTypeDef Tim1BaseConfig(TIM_HandleTypeDef *htim) {
    htim->Instance = TIM1;
    htim->Init.Prescaler = 7;
    htim->Init.CounterMode = TIM_COUNTERMODE_UP;
    htim->Init.Period = 999;
    htim->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim->Init.RepetitionCounter = 0;
    htim->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    return HAL_TIM_Base_Init(htim);
}

/**
 * @brief Configure Timer1 clock source
 * @param htim: Timer handle pointer
 * @retval HAL_StatusTypeDef
 */
static HAL_StatusTypeDef Tim1ClockSourceConfig(TIM_HandleTypeDef *htim) {
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};

    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    return HAL_TIM_ConfigClockSource(htim, &sClockSourceConfig);
}

/**
 * @brief Configure Timer1 master mode settings
 * @param htim: Timer handle pointer
 * @retval HAL_StatusTypeDef
 */
static HAL_StatusTypeDef Tim1MasterConfig(TIM_HandleTypeDef *htim) {
    TIM_MasterConfigTypeDef sMasterConfig = {0};

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    return HAL_TIMEx_MasterConfigSynchronization(htim, &sMasterConfig);
}

/**
 * @brief Restart Timer1
 * @retval HAL_StatusTypeDef
 */
static HAL_StatusTypeDef Tim1Start(void) { return HAL_TIM_Base_Start_IT(&htim1); }

/**
 * @brief Stop Timer1
 * @retval HAL_StatusTypeDef
 */
static HAL_StatusTypeDef Tim1Stop(void) { return HAL_TIM_Base_Stop_IT(&htim1); }

/**
 * @brief Get current Timer1 counter value
 * @retval uint32_t Current counter value
 */
uint32_t Tim1GetCounter(void) { return __HAL_TIM_GET_COUNTER(&htim1); }

void Tim1Init(void) {
    Tim1EnableClockAndInterrupt();

    if (Tim1BaseConfig(&htim1) != HAL_OK) {
        // Error_Handler();
    }

    if (Tim1ClockSourceConfig(&htim1) != HAL_OK) {
        // Error_Handler();
    }

    if (Tim1MasterConfig(&htim1) != HAL_OK) {
        // Error_Handler();
    }

    Tim1Start();
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM1) {
        static uint32_t tickCount = 0;

        if (++tickCount >= 1000) {
            HAL_GPIO_TogglePin(kLedPort, kOrangeLedPin);
            tickCount = 0;
        }
    }
}
