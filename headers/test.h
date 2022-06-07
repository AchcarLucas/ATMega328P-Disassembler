bool randomBool() {
    return (rand() % 100) & 0x01;
}

std::bitset<16> set_16_bits(std::string mask_bits) {
    std::bitset<16> bits;
    for(short int i = 0; i < 16; ++i) {
        bool bit = randomBool();
        if(mask_bits[15 - i] != '1' && mask_bits[15 - i] != '0')
            bits[i] = bit;
        else
            bits[i] = mask_bits[15 - i] == '1' ? 0x01 : 0x00;
    }
    return bits;
}

std::bitset<32> set_32_bits(std::string mask_bits) {
    std::bitset<32> bits;
    for(short int i = 0; i < 32; i++) {
        bool bit = randomBool();
        if(mask_bits[31 - i] != '1' && mask_bits[31 - i] != '0')
            bits[i] = bit;
        else
            bits[i] = mask_bits[31 - i] == '1' ? 0x01 : 0x00;
    }
    return bits;
}

void test_if(bool b_test, std::string f_test, std::bitset<16> y_16) {
    std::cout << "Test |" << std::setw (10) << f_test << "\t (" << y_16 << ") - \t";

    if(!b_test)
        std::cout << "FAILED in the test" << std::endl;
    else
        std::cout << "passed in the test" << std::endl;

    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
}

void test_if(bool b_test, std::string f_test, std::bitset<32> y_32) {
    std::cout << "Test |" << std::setw (10) << f_test << "\t (" << y_32 << ") - \t";

    if(b_test)
        std::cout << "FAILED in the test" << std::endl;
    else
        std::cout << "passed in the test" << std::endl;

    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
}

void test_instructions(packet_instructions *p_inst) {
    s_instructions *p = p_inst->s;

    std::cout << "Testing ..." << std::endl;

    for(short int i = 0; i < p_inst->len; ++i) {
            p[i].mask.erase(std::remove(p[i].mask.begin(), p[i].mask.end(), ' '), p[i].mask.end());
            if(p[i].mask.length() == 16) {
                std::bitset<16> y_16 = set_16_bits(p[i].mask);
                test_if(p[i].f_16(y_16), p[i].func_name, y_16);
            } else {
                std::bitset<32> y_32 = set_32_bits(p[i].mask);
                test_if(p[i].f_32(y_32), p[i].func_name, y_32);
            }
    }
}

