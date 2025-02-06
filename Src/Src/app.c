/**
 * @file app.c
 * @brief Application initialization and error handling implementation
 */

#include "app.h"
#include "clock_config.h"
#include "gpio_config.h"

void AppInit(void) {
    HAL_Init();
    ClockConfig();
    GpioConfig();
}

/**
 * @brief System error handler
 * @details Disables interrupts and enters infinite loop
 * @note Called by various functions when critical error occurs
 */
void Error_Handler(void) {
    __disable_irq();
    while (1) {
    }
}
