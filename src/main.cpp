// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
// http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf
// https://cadernodelaboratorio.com.br/en/the-avr-generated-hex-file/

#include <iostream>
#include <cstdio>

#include "../headers/instructions.h"

using namespace std;

int main()
{
    bool result = ADC(0b0001110000111000);
    cout << "Test ADC: " << result << endl;
    getchar();
    return 0;
}
