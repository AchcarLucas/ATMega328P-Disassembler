bool randomBool() {
    return (rand() % 100) & 0x01;
}

std::bitset<16> set_16_bits(std::bitset<16> bits, std::string mask_bits) {
    std::remove(mask_bits.begin(), mask_bits.end(), ' ');
    for(short int i = 0; i < 16; ++i) {
        bool bit = randomBool();
        if(mask_bits[15 - i] == 'x')
            bits[i] = bit;
    }
    return bits;
}

std::bitset<32> set_32_bits(std::bitset<32> bits, std::string mask_bits) {
    std::remove(mask_bits.begin(), mask_bits.end(), ' ');
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

    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
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
    y_16 = set_16_bits(0b0001110000000000, "0001 11xxx xxxx xxx");
    b_test = ADC(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ADD";
    y_16 = set_16_bits(0b0000110000000000, "000 011xx xxxx xxxx");
    b_test = ADD(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ADIW";
    y_16 = set_16_bits(0b1001011000000000, "1001 0110 xxxx xxxx");
    b_test = ADIW(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "AND";
    y_16 = set_16_bits(0b0010000000000000, "0010 00xx xxxx xxxx");
    b_test = AND(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ANDI";
    y_16 = set_16_bits(0b0111000000000000, "0111 xxxx xxxx xxxx");
    b_test = ANDI(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ASR";
    y_16 = set_16_bits(0b1001010000000101, "100 1010 xxxxx 0101");
    b_test = ASR(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "BCLR";
    y_16 = set_16_bits(0b1001010010001000, "1001 01001 xxx1 000");
    b_test = BCLR(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "BLD";
    y_16 = set_16_bits(0b1111100000000000, "1111 100x xxxx 0xxx");
    b_test = BLD(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "BLD";
    y_16 = set_16_bits(0b1111100000000000, "1111 100x xxxx 0xxx");
    b_test = BLD(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "BRBC";
    y_16 = set_16_bits(0b1111010000000000, "1111 01xx xxxx xxxx");
    b_test = BRBC(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "BRBS";
    y_16 = set_16_bits(0b1111000000000000, "1111 00xx xxxx xxxx");
    b_test = BRBS(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "BREAK";
    y_16 = set_16_bits(0b1001010110011000, "1001 0101 1001 1000");
    b_test = BREAK(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "BSET";
    y_16 = set_16_bits(0b1001010000001000, "1001 0100 0xxx 1000");
    b_test = BSET(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "BST";
    y_16 = set_16_bits(0b1111101000000000, "1111 101x xxxx 0xxx");
    b_test = BST(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "CALL";
    y_32 = set_32_bits(0b10010100000011100000000000000000, "1001 010x xxxx 111x xxxx xxxx xxxx xxxx");
    b_test = CALL(y_32)
    test_if(b_test, f_test, y_32);

    // ######################################################

    f_test = "CBI";
    y_16 = set_16_bits(0b1001100000000000, "1001 1000 xxxx xxxx");
    b_test = CBI(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "COM";
    y_16 = set_16_bits(0b1001010000000000, "1001 010x xxxx 0000");
    b_test = COM(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "CP ";
    y_16 = set_16_bits(0b0001010000000000, "0001 01xx xxxx xxxx");
    b_test = CP(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "CPC";
    y_16 = set_16_bits(0b0000010000000000, "0000 01xx xxxx xxxx");
    b_test = CPC(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "CPI";
    y_16 = set_16_bits(0b0011000000000000, "0011 xxxx xxxx xxxx");
    b_test = CPI(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "CPSE";
    y_16 = set_16_bits(0b0001000000000000, "0001 00xx xxxx xxxx");
    b_test = CPSE(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "DEC";
    y_16 = set_16_bits(0b1001010000001010, "1001 010x xxxx 1010");
    b_test = DEC(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "DES";
    y_16 = set_16_bits(0b1001010000001011, "1001 0100 KKKK 1011");
    b_test = DES(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "EICALL";
    y_16 = set_16_bits(0b1001010100011001, "1001 0101 0001 1001");
    b_test = EICALL(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "EIJMP";
    y_16 = set_16_bits(0b1001010000011001, "1001 0100 0001 1001");
    b_test = EIJMP(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ELPM_1";
    y_16 = set_16_bits(0b1001010111011000, "1001 0101 1101 1000");
    b_test = ELPM_I(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ELPM_2";
    y_16 = set_16_bits(0b1001000000000110, "1001 000x xxxx 0110");
    b_test = ELPM_II(y_16)
    test_if(b_test, f_test, y_16);

    // ######################################################

    f_test = "ELPM_3";
    y_16 = set_16_bits(0b1001000000000111, "1001 000x xxxx 0111");
    b_test = ELPM_III(y_16)
    test_if(b_test, f_test, y_16);
}

