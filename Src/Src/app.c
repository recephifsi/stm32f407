/**
 * @file app.c
 * @brief Application initialization and error handling implementation
 */

#include "clock.h"
#include "gpio.h"
#include "app.h"

void AppInit(void) {
    HAL_Init();
    ClockInit();
    GpioInit();
}

/**
 * @brief System error handler
 * @details Disables interrupts and enters infinite loop
 * @note Called by various functions when critical error occurs
 */
void Error_Handlers(void) {
    __disable_irq();
    while (1) {
    }
}
