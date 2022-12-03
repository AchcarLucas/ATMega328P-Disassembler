// 16 BITS - OPCODE

struct REGISTER_SINGLE_ADDRESS {
    unsigned short int opcode : 11;
    unsigned char Rd : 4;
};

struct REGISTER_DOUBLE_ADDRESS {
    unsigned char opcode : 6;
    unsigned char Rr : 4;
    unsigned char Rd : 4;
};

// 15 - 5 (OP + Rr/Rd) : 5 (A)
struct IO_DIRECT_ADDRESS_MEMORY {
    unsigned char opcode : 6;
    unsigned char Rr_Rd : 4;
    unsigned char A : 6;
};

struct DATA_INDIRECT_DISPLACEMENT {
    unsigned char opcode : 6;
    unsigned char Rr_Rd : 4;
    unsigned char A : 6;
};

// REGISTRO X, Y ou Z (SALVA O CONTE�DO INDIRETAMENTE NA MEMORIA)
struct DATA_INDIRECT_ADDRESS {
    unsigned short int opcode : 16;
};

// REGISTRO X, Y ou Z (DECREMENTA O CONTE�DO) - ANTES DA OPERA��O
struct DATA_INDIRECT_ADDRESS_PRE_DECREMENT {
    unsigned short int opcode : 16;
};

// REGISTRO X, Y ou Z (INCREMENTA O CONTE�DO) DEPOIS DA OPERA��O
struct DATA_INDIRECT_ADDRESS_POST_DECREMENT {
    unsigned short int opcode : 16;
};

struct PROGRAM_MEMORY_CONSTANT_ADDRESS {
    unsigned short int z_register : 15;
    bool byte_operate;
};

struct PROGRAM_MEMORY_ADDRESS_POST_INCREMENT {
    unsigned short int z_register : 15;
    bool byte_operate;
};

struct RELATIVE_PROGRAM_MEMORY_ADDRESS {
    unsigned char opcode : 4;
    unsigned short int k : 12;
};

// 32 BITS - OPCODE

struct DATA_DIRECT_ADDRESS {
    unsigned short int opcode : 11;
    unsigned char Rr_Rd : 4;
    unsigned short int data_address : 16;
};

struct PROGRAM_INDIRECT_MEMOYR_ADDRESS {
    unsigned short int z_register : 16;
    unsigned char MSB : 6;
    unsigned short int LSB : 16;
};

struct PROGRAM_DIRECT_MEMORY_ADDRESS {
    unsigned short int z_register : 16;
    unsigned char PC : 16;
};

#define PC unsigned short

/*
 ** Status Register (SREG)
    - SREG      Status Register
    - C         Carry Flag
    - Z         Zero Flag
    - N         Negative Flag
    - V         Two�s complement overflow indicator
    - S         N XOR V, for signed tests
    - H         Half Carry Flag
    - T         Transfer bit used by BLD and BST instructions
    - I         Global Interrupt Enable/Disable Flag
 ** Registers and Operands
    - Rd        Destination (and source) register in the Register File
    - Rr        Source register in the Register File
    - R         Result after instruction is executed
    - K         Constant data
    - k         Constant address
    - b         Bit in the Register File or I/O Register (3-bit)
    - s         Bit in the Status Register (3-bit)
    - X,Y,Z     Indirect Address Register (X=R27:R26, Y=R29:R28, and Z=R31:R30)
    - A         I/O location address
    - q         Displacement for direct addressing (6-bit)
*/


#define ADC_MASK "0001 11rd dddd rrrr"
#define ADC(x) ((x >> 10) == 0b000111); // 0001 11rd dddd rrrr

#define ADD_MASK "0000 11rd dddd rrrr"
#define ADD(x) ((x >> 10) == 0b000011); // 0000 11rd dddd rrrr

#define ADIW_MASK "1001 0110 KKdd KKKK"
#define ADIW(x) ((x >> 8) == 0b10010110); // 1001 0110 KKdd KKKK

#define AND_MASK "0010 00rd dddd rrrr"
#define AND(x) ((x >> 10) == 0b001000); // 0010 00rd dddd rrrr

#define ANDI_MASK "0111 KKKK dddd KKKK"
#define ANDI(x) ((x >> 12) == 0b0111); // 0111 KKKK dddd KKKK

#define ASR_MASK "1001 010d dddd 0101"
#define ASR(x) ((x >> 9) == 0b1001010 and (x & std::bitset<16>(0b1111)) == 0b0101); // 1001 010d dddd 0101

// Bit Clear in SREG
#define BCLR_MASK "1001 0100 1sss 1000"
#define BCLR(x) ((x >> 7) == 0b100101001 and (x & std::bitset<16>(0b1111)) == 0b1000); // 1001 0100 1sss 1000

#define BLD_MASK "1111 100d dddd 0bbb"
#define BLD(x) ((x >> 9) == 0b1111100 and (x & std::bitset<16>(0b1000)) == 0x00); // 1111 100d dddd 0bbb

// Branch if Bit in SREG is Cleared
#define BRBC_MASK "1111 01kk kkkk ksss"
#define BRBC(x) ((x >> 10) == 0b111101); // 1111 01kk kkkk ksss

// Branch if Bit in SREG is Set
#define BRBS_MASK "1111 01kk kkkk k000"
#define BRBS(x) ((x >> 10) == 0b111101 and (x & std::bitset<16>(0b0111)) == 0b000); // 1111 01kk kkkk k000

// Branch if Carry Cleared
#define BRCC_MASK "1111 00kk kkkk ksss"
#define BRCC(x) ((x >> 10) == 0b111100); // 1111 00kk kkkk ksss

// Branch if Carry Set
#define BRCS_MASK "1111 00kk kkkk k000"
#define BRCS(x) ((x >> 10) == 0b111100 and (x & std::bitset<16>(0b0111)) == 0b000); // 1111 00kk kkkk k000

#define BREAK_MASK "1001 0101 1001 1000"
#define BREAK(x) (x == 0b1001010110011000); // 1001 0101 1001 1000

#define BREQ_MASK "1111 00kk kkkk k001"
#define BREQ(x) ((x >> 10) == 0b111100 and (x & std::bitset<16>(0b0111)) == 0b001); // 1111 00kk kkkk k001

// Bit Set in SREG
#define BSET_MASK "1001 0100 0sss 1000"
#define BSET(x) ((x >> 7) == 0b100101000 and (x & std::bitset<16>(0b1111)) == 0b1000); // 1001 0100 0sss 1000

#define BST_MASK "1111 101d dddd 0bbb"
#define BST(x) ((x >> 9) == 0b1111101 and (x & std::bitset<16>(0b1000)) == 0x00); // 1111 101d dddd 0bbb

#define CALL_MASK "1001 010k kkkk 111k kkkk kkkk kkkk kkkk"
#define CALL(x) ((x >> 25) == 0b1001010 and ((x >> 16) & std::bitset<32>(0b1110)) == 0b1110); // 1001 010k kkkk 111k kkkk kkkk kkkk kkkk

// Clear Bit in I/O Register
#define CBI_MASK "1001 1000 AAAA Abbb"
#define CBI(x) ((x >> 8) == 0b10011000); // 1001 1000 AAAA Abbb

// Clear Carry Flag
#define CLC_MASK "1001 0100 1000 1000"
#define CLC(x) (x == 0b1001010010001000); // 1001 0100 1000 1000

// Clear Half Carry Flag
#define CLH_MASK "1001 0100 1101 1000"
#define CLH(x) (x == 0b1001010011011000); // 1001 0100 1101 1000

// Clear Half Carry Flag
#define CLI_MASK "1001 0100 1111 1000"
#define CLI(x) (x == 0b1001010011111000); // 1001 0100 1111 1000

// Clear Negative Flag
#define CLN_MASK "1001 0100 1010 1000"
#define CLN(x) (x == 0b1001010010101000); // 1001 0100 1010 1000

// Clear Register
#define CLR_MASK "1001 01dd dddd dddd"
#define CLR(x) ((x >> 10) == 0b100101); // 1001 01dd dddd dddd

// Clear Signed Flag
#define CLS_MASK "1001 0100 1100 1000"
#define CLS(x) (x == 0b1001010011001000); // 1001 0100 1100 1000

// Clear T Flag
#define CLT_MASK "1001 0100 1110 1000"
#define CLT(x) (x == 0b1001010011101000); // 1001 0100 1110 1000

// Clear Overflow Flag
#define CLV_MASK "1001 0100 1011 1000"
#define CLV(x) (x == 0b1001010010111000); // 1001 0100 1011 1000

// Clear Zero Flag
#define CLZ_MASK "1001 0100 1001 1000"
#define CLZ(x) (x == 0b1001010010011000); // 1001 0100 1001 1000

#define COM_MASK "1001 010d dddd 0000"
#define COM(x) ((x >> 9) == 0b1001010 and (x & std::bitset<16>(0b1111)) == 0x00); // 1001 010d dddd 0000

#define CP_MASK     "0001 01rd dddd rrrr"
#define CPC_MASK    "0000 01rd dddd rrrr"
#define CPI_MASK    "0011 KKKK dddd KKKK"
#define CPSE_MASK   "0001 00rd dddd rrrr"
#define DEC_MASK    "1001 010d dddd 1010"
#define DES_MASK    "1001 0100 KKKK 1011"

#define CP(x) ((x >> 10) == 0b000101); // 0001 01rd dddd rrrr
#define CPC(x) ((x >> 10) == 0b000001); // 0000 01rd dddd rrrr
#define CPI(x) ((x >> 12) == 0b0011); // 0011 KKKK dddd KKKK
#define CPSE(x) ((x >> 10) == 0b000100); // 0001 00rd dddd rrrr
#define DEC(x) ((x >> 9) == 0b1001010 and (x & std::bitset<16>(0b1111)) == 0b1010); // 1001 010d dddd 1010
#define DES(x) ((x >> 8) == 0b10010100 and (x & std::bitset<16>(0b1111)) == 0b1011); // 1001 0100 KKKK 1011

#define EICALL_MASK "1001 0101 0001 1001"
#define EICALL(x) (x == 0b1001010100011001); // 1001 0101 0001 1001

#define EIJMP_MASK "1001 0100 0001 1001"
#define EIJMP(x) (x == 0b1001010000011001); // 1001 0100 0001 1001

#define ELPM_I_MASK     "1001 0101 1101 1000"
#define ELPM_II_MASK    "1001 000d dddd 0110"
#define ELPM_III_MASK   "1001 000d dddd 0111"

#define ELPM_I(x) (x == 0b1001010111011000); // 1001 0101 1101 1000
#define ELPM_II(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b0110); // 1001 000d dddd 0110
#define ELPM_III(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b0111); // 1001 000d dddd 0111

#define EOR_MASK "0010 01rd dddd rrrr"
#define EOR(x) ((x >> 10) == 0b001001); // 0010 01rd dddd rrrr

#define FMUL_MASK       "0000 0011 0ddd 1rrr"
#define FMULS_MASK      "0000 0011 1ddd 0rrr"
#define FMULSU_MASK     "0000 0011 1ddd 1rrr"

#define FMUL(x) ((x >> 7) == 0b000000110 and ((x >> 3) & std::bitset<16>(0x01)) == 0x01); // 0000 0011 0ddd 1rrr
#define FMULS(x) ((x >> 7) == 0b000000111 and ((x >> 3) & std::bitset<16>(0x01)) == 0x00); // 0000 0011 1ddd 0rrr
#define FMULSU(x) ((x >> 7) == 0b000000111 and ((x >> 3) & std::bitset<16>(0x01)) == 0x01); // 0000 0011 1ddd 1rrr

#define ICALL_MASK "1001 0101 0000 1001"
#define ICALL(x) (x == 0b1001010100001001); // 1001 0101 0000 1001

#define IJMP_MASK "1001 0100 0000 1001"
#define IJMP(x) (x == 0b1001010000001001); // 1001 0100 0000 1001

#define IN_MASK "1011 0AAd dddd AAAA"
#define IN(x) ((x >> 11) == 0b10110); // 1011 0AAd dddd AAAA

#define INC_MASK "1001 010d dddd 0011"
#define INC(x) ((x >> 9) == 0b1001010 and (x & std::bitset<16>(0b1111)) == 0b0011); // 1001 010d dddd 0011

#define JMP_MASK "1001 010k kkkk 110k kkkk kkkk kkkk kkkk"
#define JMP(x) ((x >> 25) == 0b1001010 and ((x >> 17) & std::bitset<32>(0b111)) == 0b110); // 1001 010k kkkk 110k kkkk kkkk kkkk kkkk

#define LAC_MASK     "1001 001r rrrr 0110"
#define LAS_MASK    "1001 001r rrrr 0101"
#define LAT_MASK   "1001 001r rrrr 0111"

#define LAC(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b0110); // 1001 001r rrrr 0110
#define LAS(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b0101); // 1001 001r rrrr 0101
#define LAT(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b0111); // 1001 001r rrrr 0111

#define LD_X_I_MASK     "1001 000d dddd 1100"
#define LD_X_II_MASK    "1001 000d dddd 1101"
#define LD_X_III_MASK   "1001 000d dddd 1110"

// LD � Load Indirect from Data Space to Register using Index X
#define LD_X_I(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b1100); // 1001 000d dddd 1100
#define LD_X_II(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b1101); // 1001 000d dddd 1101
#define LD_X_III(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b1110); // 1001 000d dddd 1110

#define LD_Y_I_MASK     "1000 000d dddd 1000"
#define LD_Y_II_MASK    "1001 000d dddd 1001"
#define LD_Y_III_MASK   "1001 000d dddd 1010"
#define LD_Y_IV_MASK    "10q0 qq0d dddd 1qqq"

// LD (LDD) � Load Indirect from Data Space to Register using Index Y
#define LD_Y_I(x) ((x >> 9) == 0b1000000 and (x & std::bitset<16>(0b1111)) == 0b1000); // 1000 000d dddd 1000
#define LD_Y_II(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b1001); // 1001 000d dddd 1001
#define LD_Y_III(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b1010); // 1001 000d dddd 1010
#define LD_Y_IV(x) ((x >> 14) == 0b10 and ((x >> 9) & std::bitset<16>(0x01)) == 0x00 and \
                    ((x >> 3) & std::bitset<16>(0x01)) == 0x01); // 10q0 qq0d dddd 1qqq

#define LD_Z_I_MASK     "1000 000d dddd 0000"
#define LD_Z_II_MASK    "1001 000d dddd 0001"
#define LD_Z_III_MASK   "1001 000d dddd 0010"
#define LD_Z_IV_MASK    "10q0 qq0d dddd 0qqq"

// LD (LDD) � Load Indirect From Data Space to Register using Index Z
#define LD_Z_I(x) ((x >> 9) == 0b1000000 and (x & std::bitset<16>(0b1111)) == 0b0000); // 1000 000d dddd 0000
#define LD_Z_II(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b0001); // 1001 000d dddd 0001
#define LD_Z_III(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b0010); // 1001 000d dddd 0010
#define LD_Z_IV(x) ((x >> 14) == 0b10 and ((x >> 9) & std::bitset<16>(0x01)) == 0x00 and \
                    ((x >> 3) & std::bitset<16>(0x01)) == 0x00); // 10q0 qq0d dddd 0qqq

#define LDI_MASK "1110 KKKK dddd KKKK"
#define LDI(x) ((x >> 12) == 0b1110); // 1110 KKKK dddd KKKK

#define LDS_32_MASK "1001 000d dddd 0000 kkkk kkkk kkkk kkkk"
#define LDS_16_MASK "1010 0kkk dddd kkkk"

#define LDS_32(x) ((x >> 25) == 0b1001000 and ((x >> 16) & std::bitset<32>(0b1111)) == 0x0); // 1001 000d dddd 0000 kkkk kkkk kkkk kkkk
#define LDS_16(x) ((x >> 11) == 0b10100); // 1010 0kkk dddd kkkk

#define LPM_I_MASK "1001 0101 1100 1000"
#define LPM_II_MASK "1001 000d dddd 0100"
#define LPM_III_MASK "1001 000d dddd 0101"

#define LPM_I(x) (x == 0b1001010111001000); // 1001 0101 1100 1000
#define LPM_II(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b0100); // 1001 000d dddd 0100
#define LPM_III(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b0101); // 1001 000d dddd 0101

#define LSL_MASK "0000 11dd dddd dddd"
#define LSL(x) ((x >> 10) == 0b000011); // 0000 11dd dddd dddd

#define LSR_MASK "1001 010d dddd 0110"
#define LSR(x) ((x >> 9) == 0b1001010 and (x & std::bitset<16>(0b1111)) == 0b0110); // 1001 010d dddd 0110

#define MOV_MASK "0010 11rd dddd rrrr"
#define MOV(x) ((x >> 10) == 0b001011); // 0010 11rd dddd rrrr

#define MOVW_MASK "0000 0001 dddd rrrr"
#define MOVW(x) ((x >> 8) == 0b00000001); // 0000 0001 dddd rrrr

#define MUL_MASK "1001 11rd dddd rrrr"
#define MUL(x) ((x >> 10) == 0b100111); // 1001 11rd dddd rrrr

#define MULS_MASK "0000 0010 dddd rrrr"
#define MULS(x) ((x >> 8) == 0b00000010); // 0000 0010 dddd rrrr

#define MULSU_MASK "0000 0011 0ddd 0rrr"
#define MULSU(x) ((x >> 7) == 0b000000110 and ((x >> 4) & std::bitset<16>(0b1000)) == 0x0 and ((x >> 3) & std::bitset<16>(0x01)) == 0x0); // 0000 0011 0ddd 0rrr

#define NEG_MASK "1001 010d dddd 0001"
#define NEG(x) ((x >> 9) == 0b1001010 and (x & std::bitset<16>(0b1111)) == 0b0001); // 1001 010d dddd 0001

#define NOP_MASK "0000 0000 0000 0000"
#define NOP(x) (x == 0x00); // 0000 0000 0000 0000

#define OR_MASK "0010 10rd dddd rrrr"
#define OR(x) ((x >> 10) == 0b001010); // 0010 10rd dddd rrrr

#define ORI_MASK "0110 KKKK dddd KKKK"
#define ORI(x) ((x >> 12) == 0b0110); // 0110 KKKK dddd KKKK

#define OUT_MASK "1011 1AAr rrrr AAAA"
#define OUT(x) ((x >> 11) == 0b10111); // 1011 1AAr rrrr AAAA

#define POP_MASK "1001 000d dddd 1111"
#define POP(x) ((x >> 9) == 0b1001000 and (x & std::bitset<16>(0b1111)) == 0b1111); // 1001 000d dddd 1111

#define PUSH_MASK "1001 001d dddd 1111"
#define PUSH(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b1111); // 1001 001d dddd 1111

#define RCALL_MASK "1101 kkkk kkkk kkkk"
#define RCALL(x) ((x >> 12) == 0b1101); // 1101 kkkk kkkk kkkk

#define RET_MASK "1001 0101 0000 1000"
#define RET(x) (x == 0b1001010100001000); // 1001 0101 0000 1000

#define RETI_MASK "1001 0101 0001 1000"
#define RETI(x) (x == 0b1001010100011000); // 1001 0101 0001 1000

#define RJMP_MASK "1100 kkkk kkkk kkkk"
#define RJMP(x) ((x >> 12) == 0b1100); // 1100 kkkk kkkk kkkk

#define ROL_MASK "0001 11dd dddd dddd"
#define ROL(x) ((x >> 10) == 0b000111); // 0001 11dd dddd dddd

#define ROR_MASK "1001 010d dddd 0111"
#define ROR(x) ((x >> 9) == 0b1001010 and (x & std::bitset<16>(0b1111)) == 0b0111); // 1001 010d dddd 0111

#define SBC_MASK    "0000 10rd dddd rrrr"
#define SBCI_MASK   "0100 KKKK dddd KKKK"
#define SBI_MASK    "1001 1010 AAAA Abbb"
#define SBIC_MASK   "1001 1001 AAAA Abbb"
#define SBIS_MASK   "1001 1011 AAAA Abbb"
#define SBIW_MASK   "1001 0111 KKdd KKKK"
#define SBR_MASK    "0110 KKKK dddd KKKK"
#define SBRC_MASK   "1111 110r rrrr 0bbb"
#define SBRS_MASK   "1111 111r rrrr 0bbb"

#define SBC(x) ((x >> 10) == 0b000010); // 0000 10rd dddd rrrr
#define SBCI(x) ((x >> 12) == 0b0100); // 0100 KKKK dddd KKKK
#define SBI(x) ((x >> 8) == 0b10011010); // 1001 1010 AAAA Abbb
#define SBIC(x) ((x >> 8) == 0b10011001); // 1001 1001 AAAA Abbb
#define SBIS(x) ((x >> 8) == 0b10011011); // 1001 1011 AAAA Abbb
#define SBIW(x) ((x >> 8) == 0b10010111); // 1001 0111 KKdd KKKK
#define SBR(x) ((x >> 12) == 0b0110); // 0110 KKKK dddd KKKK
#define SBRC(x) ((x >> 9) == 0b1111110); // 1111 110r rrrr 0bbb
#define SBRS(x) ((x >> 9) == 0b1111111 and (x & std::bitset<16>(0b1000)) == 0b0000);; // 1111 111r rrrr 0bbb

#define SEC_MASK "1001 0100 0000 1000"
#define SEH_MASK "1001 0100 0101 1000"
#define SEI_MASK "1001 0100 0111 1000"
#define SEN_MASK "1001 0100 0010 1000"

#define SEC(x) (x == 0b1001010000001000); // 1001 0100 0000 1000
#define SEH(x) (x == 0b1001010001011000); // 1001 0100 0101 1000
#define SEI(x) (x == 0b1001010001111000); // 1001 0100 0111 1000
#define SEN(x) (x == 0b1001010000101000); // 1001 0100 0010 1000

#define SER_MASK "1110 1111 dddd 1111"
#define SER(x) ((x >> 8) == 0b11101111 \
                and (x & std::bitset<16>(0b1111)) == 0b1111); // 1110 1111 dddd 1111

#define SES_MASK "1001 0100 0100 1000"
#define SES(x) (x == 0b1001010001001000); // 1001 0100 0100 1000

#define SET_MASK "1001 0100 0110 1000"
#define SET(x) (x == 0b1001010001101000); // 1001 0100 0110 1000

#define SEV_MASK "1001 0100 0011 1000"
#define SEV(x) (x == 0b1001010000111000); // 1001 0100 0011 1000

#define SEZ_MASK "1001 0100 0001 1000"
#define SEZ(x) (x == 0b1001010000011000); // 1001 0100 0001 1000

#define SLEEP_MASK "1001 0101 1000 1000"
#define SLEEP(x) (x == 0b1001010110001000); // 1001 0101 1000 1000

#define SPM_MASK            "1001 0101 1110 1000"
#define SPM_I_II_III_MASK   "1001 0101 1110 1000"
#define SPM_IV_V_VI_MASK    "1001 0101 1111 1000"

#define SPM(x) (x == 0b1001010111101000); // 1001 0101 1110 1000
#define SPM_I_II_III(x) (x == 0b1001010111101000); // 1001 0101 1110 1000
#define SPM_IV_V_VI(x) (x == 0b1001010111111000); // 1001 0101 1111 1000

#define ST_X_I_MASK    "1001 001r rrrr 1100"
#define ST_X_II_MASK   "1001 001r rrrr 1101"
#define ST_X_III_MASK  "1001 001r rrrr 1110"

// ST � Store Indirect From Register to Data Space using Index X
#define ST_X_I(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b1100); // 1001 001r rrrr 1100
#define ST_X_II(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b1101); // 1001 001r rrrr 1101
#define ST_X_III(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b1110); // 1001 001r rrrr 1110

#define STD_Y_I_MASK    "1000 001r rrrr 1000"
#define STD_Y_II_MASK   "1001 001r rrrr 1001"
#define STD_Y_III_MASK  "1001 001r rrrr 1010"
#define STD_Y_IV_MASK   "10q0 qq1r rrrr 1qqq"

// ST (STD) � Store Indirect From Register to Data Space using Index Y
#define STD_Y_I(x) ((x >> 9) == 0b1000001 and (x & std::bitset<16>(0b1111)) == 0b1000); // 1000 001r rrrr 1000
#define STD_Y_II(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b1001); // 1001 001r rrrr 1001
#define STD_Y_III(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b1010); // 1001 001r rrrr 1010
#define STD_Y_IV(x) ((x >> 14) == 0b10 and \
                     ((x >> 12) & std::bitset<16>(0x01)) == 0x0 \
                      and ((x >> 9) & std::bitset<16>(0x01)) == 0x01 \
                     and ((x >> 3) & std::bitset<16>(0x01)) == 0x01); // 10q0 qq1r rrrr 1qqq

#define STD_Z_I_MASK    "1000 001r rrrr 0000"
#define STD_Z_II_MASK   "1001 001r rrrr 0001"
#define STD_Z_III_MASK  "1001 001r rrrr 0010"
#define STD_Z_IV_MASK   "10q0 qq1r rrrr 0qqq"

// ST (STD) � Store Indirect From Register to Data Space using Index Z
#define STD_Z_I(x) ((x >> 9) == 0b1000001 and (x & std::bitset<16>(0b1111)) == 0b0000); // 1000 001r rrrr 0000
#define STD_Z_II(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b0001); // 1001 001r rrrr 0001
#define STD_Z_III(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b0010); // 1001 001r rrrr 0010
#define STD_Z_IV(x) ((x >> 14) == 0b10 and ((x >> 12) & std::bitset<16>(0x01)) == 0x00 \
                     and ((x >> 9) & std::bitset<16>(0x01)) == 0x01 \
                     and ((x >> 3) & std::bitset<16>(0x01)) == 0x00); // 10q0 qq1r rrrr 0qqq

#define STS_32_MASK "1001 001d dddd 0000 kkkk kkkk kkkk kkkk"
#define STS_32(x) ((x >> 25) == 0b1001001 and ((x >> 16) & std::bitset<32>(0b1111)) == 0x00); // 1001 001d dddd 0000 kkkk kkkk kkkk kkkk

#define STS_16_MASK "1010 1kkk dddd kkkk"
#define STS_16(x) ((x >> 11) == 0b10101); // 1010 1kkk dddd kkkk

#define SUB_MASK "0001 10rd dddd rrrr"
#define SUB(x) ((x >> 10) == 0b000110); // 0001 10rd dddd rrrr

#define SUBI_MASK "0101 KKKK dddd KKKK"
#define SUBI(x) ((x >> 12) == 0b0101); // 0101 KKKK dddd KKKK

#define SWAP_MASK "1001 010d dddd 0010"
#define SWAP(x) ((x >> 9) == 0b1001010 and (x & std::bitset<16>(0b1111)) == 0b0010); // 1001 010d dddd 0010

#define TST_MASK "0010 00dd dddd dddd"
#define TST(x) ((x >> 10) == 0b001000); // 0010 00dd dddd dddd

#define WDR_MASK "1001 0101 1010 1000"
#define WDR(x) (x == 0b1001010110101000); // 1001 0101 1010 1000

#define XCH_MASK "1001 001r rrrr 0100"
#define XCH(x) ((x >> 9) == 0b1001001 and (x & std::bitset<16>(0b1111)) == 0b0100); // 1001 001r rrrr 0100
