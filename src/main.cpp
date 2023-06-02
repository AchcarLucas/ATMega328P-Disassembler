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

#define DEBUG true
#define IF_DEBUG if(DEBUG)

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
        //bin = readHexFile("test_file/blink/build/blink.hex");
        bin = readHexFile("test_file/empty/build/empty.hex");
    } catch(FileException e) {
        std::cout << "[Caught Exception] " << e.what() << std::endl;
        return 1;
    }

    IF_DEBUG debugHexFile(bin);

    std::string instruction_assembler = std::string();

    std::cout << std::endl;
    for(PC pc = 0; pc < bin->size() - 3;) {
        std::bitset<16> bitcode_16 = bin->at(pc) << 8 | bin->at(pc) >> 8;
        std::bitset<32> bitcode_32 = (bin->at(pc) << 8 | bin->at(pc) >> 8) << 16 | bin->at(pc + 1);

        inst *i = search_instruction(p_inst, pc, bitcode_16, bitcode_32);
        pc += i->pc;
        instruction_assembler = i->mnemonic_assembly;

        std::cout << instruction_assembler << std::endl;

        delete i;
    }

    delete bin;
    delete p_inst;

    return 0;
}
