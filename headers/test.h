void print_test_info(bool b_test);

void separator()
{
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
}

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
    for(short int i = 0; i < 32; ++i) {
        bool bit = randomBool();
        if(mask_bits[31 - i] != '1' && mask_bits[31 - i] != '0')
            bits[i] = bit;
        else
            bits[i] = mask_bits[31 - i] == '1' ? 0x01 : 0x00;
    }
    return bits;
}

void test_if(bool b_test, std::string f_test, std::bitset<16> y_16) {
    std::cout << "Test |" << std::setw (20) << f_test << "\t (" << y_16 << ") - \t";
    print_test_info(b_test);
}

void test_if(bool b_test, std::string f_test, std::bitset<32> y_32) {
    std::cout << "Test |" << std::setw (20) << f_test << "\t (" << y_32 << ") - \t";
    print_test_info(b_test);
}

void print_test_info(bool b_test) {
    if(!b_test)
        #if defined(_WIN32) || defined(_WIN64)
            std::cout << "FAILED in the test" << std::endl;
        #else
            std::cout << "\x1B[31m" << "FAILED in the test" << "\033[0m" << std::endl;
        #endif

    else
        #if defined(_WIN32) || defined(_WIN64)
            std::cout << "passed in the test" << std::endl;
        #else
            std::cout << "\x1B[32mPASSED in the test\033[0m" << std::endl;
        #endif
    separator();
}

void test_instructions(packet_instructions *p_inst) {
    s_instructions *p = p_inst->s;

    std::cout << "Testing ..." << std::endl;

    unsigned short c_failed = 0;

    for(short int i = 0; i < p_inst->len; ++i) {
            p[i].mask.erase(std::remove(p[i].mask.begin(), p[i].mask.end(), ' '), p[i].mask.end());
            bool test = false;
            if(p[i].mask.length() == 16) {
                std::bitset<16> y_16 = set_16_bits(p[i].mask);
                test = p[i].c_16(y_16);
                test_if(test, p[i].func_name, y_16);
            } else {
                std::bitset<32> y_32 = set_32_bits(p[i].mask);
                test = p[i].c_32(y_32);
                test_if(test, p[i].func_name, y_32);
            }
            c_failed = test ? c_failed : ++c_failed;
    }
    std::cout << "result test: " << c_failed << " failed" << std::endl;
    separator();
}

