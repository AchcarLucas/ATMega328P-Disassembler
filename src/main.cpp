// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
// http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf
// https://cadernodelaboratorio.com.br/en/the-avr-generated-hex-file/

// install boost 1.79.0

#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <bitset>
#include <cstdio>
#include <string>
#include <algorithm>
#include <stdlib.h>

#include "../headers/instructions.h"
#include "../headers/init.h"
#include "../headers/test.h"

int main() {
    srand (time(NULL));

    packet_instructions *p_inst = init_instructions();

    test_instructions(p_inst);

    getchar();
    return 0;
}
