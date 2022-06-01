// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
// http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf
// https://cadernodelaboratorio.com.br/en/the-avr-generated-hex-file/

#include <iostream>
#include <cstdio>
#include <bitset>

#include "../headers/instructions.h"

using namespace std;

int main()
{
    bool result = CALL(0b1001010000001110);
    cout << "Test ADC: " << result << endl;
    // std::bitset<16> y(0b1001010000001110 & 0b1110);
    // cout << y << endl;
    getchar();
    return 0;
}
