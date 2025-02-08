#include "app.h"

int main(void) {
    AppInit();

    while (1) {
        // LedOn(kBlue);
        // Delay(1000);
        // LedOff(kBlue);
        // Delay(1000);

        if (ReadPin(kUserButtonPort, kUserButtonPin)) {
            LedOn(kLedPort, kOrangeLedPin);
        } else {
            LedOff(kLedPort, kOrangeLedPin);
        }
    }
}
