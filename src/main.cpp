// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
// http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf
// https://cadernodelaboratorio.com.br/en/the-avr-generated-hex-file/

#include <iostream>
#include <random>
#include <time.h>
#include <bitset>
#include <cstdio>
#include <string>
#include <stdlib.h>

#include "../headers/instructions.h"
#include "../headers/test.h"

int main()
{
    srand (time(NULL));

    test_instructions();

    getchar();
    return 0;
}
