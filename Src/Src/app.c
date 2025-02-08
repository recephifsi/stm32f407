/**
 * @file app.c
 * @brief Application initialization and error handling implementation
 */

#include "app.h"
#include "gpio.h"
#include "clock.h"
#include "timer.h"

void AppInit(void) {
    HAL_Init();
    ClockInit();
    GpioInit();
    Tim1Init();
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
