bool randomBool() {
    return (rand() % 100) & 0x01;
}

std::bitset<16> set_16_bits(std::bitset<16> bits, std::string mask_bits) {
    for(short int i = 0; i < 16; ++i) {
        bool bit = randomBool();
        if(mask_bits[15 - i] == 'x')
            bits[i] = bit;
    }
    return bits;
}

std::bitset<32> set_32_bits(std::bitset<32> bits, std::string mask_bits) {
    for(short int i = 0; i < 16; i++) {
        bool bit = randomBool();
        if(mask_bits[32 - i] == 'x')
            bits[i] = bit;
    }
    return bits;
}

void test_if(bool b_test, std::string f_test, std::bitset<16> y_16) {
    std::cout << "Test " << f_test << "\t (" << y_16 << ") - \t";

    if(b_test) {
        std::cout << f_test << "\tpassed in the test" << std::endl;
    } else {
        std::cout << f_test << "\tfailed in the test" << std::endl;
    }

    std::cout << "------------------------------------------------------------------" << std::endl;
}

void test_if(bool b_test, std::string f_test, std::bitset<32> y_32) {
    std::cout << "Test " << f_test << "\t (" << y_32 << ") - \t";

    if(b_test) {
        std::cout << f_test << "\tpassed in the test" << std::endl;
    } else {
        std::cout << f_test << "\tfailed in the test" << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
}

void test_instructions() {
    bool b_test = false;
    std::string f_test = "___";
    std::bitset<16> y_16 = 0x00;
    std::bitset<32> y_32 = 0x00;

    // ######################################################

    f_test = "ADC";
    y_16 = set_16_bits(0b0001110000000000, "000111xxxxxxxxxx");
    b_test = ADC(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ADD";
    y_16 = set_16_bits(0b0000110000000000, "000011xxxxxxxxxx");
    b_test = ADD(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ADIW";
    y_16 = set_16_bits(0b1001011000000000, "10010110xxxxxxxx");
    b_test = ADIW(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "AND";
    y_16 = set_16_bits(0b0010000000000000, "001000xxxxxxxxxx");
    b_test = AND(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ANDI";
    y_16 = set_16_bits(0b0111000000000000, "0111xxxxxxxxxxxx");
    b_test = ANDI(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ASR";
    y_16 = set_16_bits(0b1001010000000101, "1001010xxxxx0101");
    b_test = ASR(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "BCLR";
    y_16 = set_16_bits(0b1001010010001000, "100101001xxx1000");
    b_test = BCLR(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "BLD";
    y_16 = set_16_bits(0b1111100000000000, "1111100xxxxx0xxx");
    b_test = BLD(y_16)
    test_if(b_test, f_test, y_16);
}

