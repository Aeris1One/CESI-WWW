#include <avr/io.h>
#include "debug.h"

#define DEBUG 1

/*Proto functions*/
void lightUp();

void lightDown();

int main() {
    DDRB = _BV(DDB4);

    while (1) {
        if (DEBUG) {
            debugQuickly();
        }
        lightUp();
        lightDown();
    }
}