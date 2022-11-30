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
#include "../headers/readhex.h"

int main() {
    srand (time(NULL));

    packet_instructions *p_inst = init_instructions();

    test_instructions(p_inst);

    std::vector<unsigned short> *bin;

    try {
        bin = readHexFile("test_file/blink/build/blink.hex");
    } catch(FileException e) {
        std::cout << "[Caught Exception] " << e.what() << std::endl;
    }

    std::cout << std::endl;
    for (std::vector<unsigned short>::iterator it = bin->begin(); it != bin->end(); ++it) {
        std::cout << std::setw(4) << std::setfill('0') << std::hex << (unsigned short)*it << ":";
    }

    return 0;
}
