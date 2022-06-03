/*
 ** Status Register (SREG)
    - SREG      Status Register
    - C         Carry Flag
    - Z         Zero Flag
    - N         Negative Flag
    - V         Two’s complement overflow indicator
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

#define ADC(x) ((x >> 10) == 0b000111); // 0001 11rd dddd rrrr
#define ADD(x) ((x >> 10) == 0b000011); // 0000 11rd dddd rrrr
#define ADIW(x) ((x >> 8) == 0b10010110); // 1001 0110 KKdd KKKK
#define AND(x) ((x >> 10) == 0b001000); // 0010 00rd dddd rrrr
#define ANDI(x) ((x >> 12) == 0b0111); // 0111 KKKK dddd KKKK
#define ASR(x) ((x >> 9) == 0b1001010 && (x & std::bitset<16>(0b1111)) == 0b0101); // 1001 010d dddd 0101

// Bit Clear in SREG
#define BCLR(x) ((x >> 7) == 0b100101001 and (x & std::bitset<16>(0b1111)) == 0b1000); // 1001 0100 1sss 1000

#define BLD(x) ((x >> 9) == 0b1111100 and (x & std::bitset<16>(0b1000)) == 0x00); // 1111 100d dddd 0bbb

// Branch if Bit in SREG is Cleared
#define BRBC(x) ((x >> 10) == 0b111101); // 1111 01kk kkkk ksss

// Branch if Bit in SREG is Set
#define BRBS(x) ((x >> 10) == 0b111100); // 1111 00kk kkkk ksss

#define BREAK(x) (x == 0b1001010110011000); // 1001 0101 1001 1000

// Bit Set in SREG
#define BSET(x) ((x >> 7) == 0b100101000 and (x & 0b1111) == 0b1000); // 1001 0100 0sss 1000

#define BST(x) ((x >> 9) == 0b1111101 and (x & 0b1000) == 0x00); // 1111 101d dddd 0bbb
#define CALL(x) ((x >> 9) == 0b1001010 and (x & 0b1110) == 0b1110); // 1001 010k kkkk 111k kkkk kkkk kkkk kkkk


// Clear Bit in I/O Register
#define CBI(x) ((x >> 8) == 0b10011000); // 1001 1000 AAAA Abbb (0 ≤ A ≤ 31, 0 ≤ b ≤ 7)

#define COM(x) ((x >> 9) == 0b1001010 and (x & 0b1111) == 0x00); // 1001 010d dddd 0000

#define CP(x) ((x >> 10) == 0b000101); // 0001 01rd dddd rrrr
#define CPC(x) ((x >> 10) == 0b000001); // 0000 01rd dddd rrrr
#define CPI(x) ((x >> 12) == 0b0011); // 0011 KKKK dddd KKKK
#define CPSE(x) ((x >> 10) == 0b000100); // 0001 00rd dddd rrrr
#define DEC(x) ((x >> 9) == 0b1001010 and (x & 0b1111) == 0b1010); // 1001 010d dddd 1010
#define DES(x) ((x >> 8) == 0b10010100 and (x & 0b1111) == 0b1011); // 1001 0100 KKKK 1011

#define EICALL(x) (x == 0b1001010100011001); // 1001 0101 0001 1001
#define EIJMP(x) (x == 0b1001010000011001); // 1001 0100 0001 1001
#define ELPM(x) (x == 0b1001010000011001); // 1001 0100 0001 1001

#define ELPM_I(x) (x == 0b1001010111011000); // 1001 0101 1101 1000
#define ELPM_II(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b0110); // 1001 000d dddd 0110
#define ELPM_III(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b0111); // 1001 000d dddd 0111

#define EOR(x) ((x >> 10) == 0b001001); // 0010 01rd dddd rrrr

#define FMUL(x) ((x >> 8) == 0b000000110 and ((x >> 4) & 0b1000) == 0x00 and (x & 0b1000) == 0x01); // 0000 0011 0ddd 1rrr
#define FMULS(x) ((x >> 8) == 0b00000011 and ((x >> 4) & 0b1000) == 0x01 and (x & 0b1000) == 0x00); // 0000 0011 1ddd 0rrr
#define FMULSU(x) ((x >> 8) == 0b00000011 and ((x >> 4) & 0b1000) == 0x01 and (x & 0b1000) == 0x01); // 0000 0011 1ddd 1rrr

#define ICALL(x) (x == 0b1001010100001001); // 1001 0101 0000 1001

#define IJMP(x) (x == 0b1001010000001001); // 1001 0100 0000 1001

#define IN(x) ((x >> 11) == 0b10110); // 1011 0AAd dddd AAAA


#define INC(x) ((x >> 9) == 0b1001010 and (x & 0b1111) == 0b0011); // 1001 010d dddd 0011

#define JMP(x) ((x >> 25) == 0b1001010 and ((x >> 17) & 0b111) == 0b110); // 1001 010k kkkk 110k kkkk kkkk kkkk kkkk

#define LAC(x) ((x >> 9) == 0b1001001 and (x & 0b1111) == 0b0110); // 1001 001r rrrr 0110
#define LAS(x) ((x >> 9) == 0b1001001 and (x & 0b1111) == 0b0101); // 1001 001r rrrr 0101
#define LAS(x) ((x >> 9) == 0b1001001 and (x & 0b1111) == 0b0111); // 1001 001r rrrr 0111

// LD – Load Indirect from Data Space to Register using Index X
#define LD_X_I(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b0111); // 1001 000d dddd 1100
#define LD_X_II(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b1101); // 1001 000d dddd 1101
#define LD_X_III(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b1110); // 1001 000d dddd 1110

// LD (LDD) – Load Indirect from Data Space to Register using Index Y
#define LD_Y_I(x) ((x >> 9) == 0b1000000 and (x & 0b1111) == 0b1000); // 1000 000d dddd 1000
#define LD_Y_II(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b1001); // 1001 000d dddd 1001
#define LD_Y_III(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b1010); // 1001 000d dddd 1010
#define LD_Y_IV(x) ((x >> 14) == 0b10 and ((x >> 9) & 0x01) == 0x00 and ((x >> 3) & 0x01) == 0x01); //10q0 qq0d dddd 1qqq


// LD (LDD) – Load Indirect From Data Space to Register using Index Z
#define LD_Z_I(x) ((x >> 9) == 0b1000000 and (x & 0b1111) == 0b0000); // 1000 000d dddd 0000
#define LD_Z_II(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b0001); // 1001 000d dddd 0001
#define LD_Z_III(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b0010); // 1001 000d dddd 0010
#define LD_Z_IV(x) ((x >> 14) == 0b10 and ((x >> 9) & 0x01) == 0x00 and ((x >> 3) & 0x01) == 0x00); //10q0 qq0d dddd 0qqq

#define LDI(x) ((x >> 12) == 0b1110); // 1110 KKKK dddd KKKK

#define LDS_32(x) ((x >> 25) == 0b1001000 and ((x >> 16) & 0b1111) == 0x0); // 1001 000d dddd 0000 kkkk kkkk kkkk kkkk
#define LDS_16(x) ((x >> 11) == 0b10100); // 1010 0kkk dddd kkkk

#define LPM_I(x) (x == 0b1001010111001000); // 1001 0101 1100 1000
#define LPM_II(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b0100); // 1001 000d dddd 0100
#define LPM_III(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b0101); // 1001 000d dddd 0101

#define LSL(x) ((x >> 10) == 0b000011); // 0000 11dd dddd dddd
#define LSR(x) ((x >> 9) == 0b1001010 and (x & 0b1111) == 0b0110); // 1001 010d dddd 0110

#define MOV(x) ((x >> 10) == 0b001011); // 0010 11rd dddd rrrr

#define MOVW(x) ((x >> 8) == 0b00000001); // 0000 0001 dddd rrrr

#define MUL(x) ((x >> 10) == 0b100111); // 1001 11rd dddd rrrr

#define MULS(x) ((x >> 8) == 0b00000010); // 0000 0010 dddd rrrr

#define MULSU(x) ((x >> 7) == 0b000000110 and ((x >> 7) & 0b1111) == 0x0 and ((x >> 3) & 0x01) == 0x0); // 0000 0011 0ddd 0rrr

#define NEG(x) ((x >> 9) == 0b1001010 and (x & 0b1111) == 0b0001); // 1001 010d dddd 0001

#define NOP(x) (x == 0x00); // 0000000000000000

#define OR(x) ((x >> 10) == 0b001010); // 0010 10rd dddd rrrr

#define ORI(x) ((x >> 12) == 0b0110); // 0110 KKKK dddd KKKK

#define OUT(x) ((x >> 11) == 0b10111); // 1011 1AAr rrrr AAAA

#define POP(x) ((x >> 9) == 0b1001000 and (x & 0b1111) == 0b1111); // 1001 000d dddd 1111

#define PUSH(x) ((x >> 9) == 0b1001001 and (x & 0b1111) == 0b1111); // 1001 001d dddd 1111

#define RCALL(x) ((x >> 12) == 0b1101); // 1101 kkkk kkkk kkkk

#define RET(x) (x == 0b1001010100001000); // 1001 0101 0000 1000

#define RETI(x) (x == 0b1001010100011000); // 1001 0101 0001 1000

#define RJMP(x) ((x >> 12) == 0b1100); // 1100 kkkk kkkk kkkk

#define ROL(x) ((x >> 10) == 0b000111); // 0001 11dd dddd dddd
#define ROR(x) ((x >> 9) == 0b1001010 and (x & 0b1111) == 0b0111); // 1001 010d dddd 0111

#define SBC(x) ((x >> 10) == 0b000010); // 0000 10rd dddd rrrr
#define SBCI(x) ((x >> 12) == 0b0100); // 0100 KKKK dddd KKKK
#define SBCI(x) ((x >> 8) == 0b10011010); // 1001 1010 AAAA Abbb
#define SBIC(x) ((x >> 8) == 0b10011001); // 1001 1001 AAAA Abbb
#define SBIS(x) ((x >> 8) == 0b10011011); // 1001 1011 AAAA Abbb
#define SBIW(x) ((x >> 8) == 0b10010111); // 1001 0111 KKdd KKKK
#define SBR(x) ((x >> 12) == 0b0110); // 0110 KKKK dddd KKKK
#define SBRC(x) ((x >> 9) == 0b1111110); // 1111 110r rrrr 0bbb

#define SBRS(x) ((x >> 9) == 0b1111111 and (x & 0b1000) == 0b1000);; // 1111 111r rrrr 0bbb

#define SEC(x) (x == 0b1001010000001000); // 1001 0100 0000 1000
#define SEH(x) (x == 0b1001010001011000); // 1001 0100 0101 1000
#define SEI(x) (x == 0b1001010001111000); // 1001 0100 0111 1000
#define SEN(x) (x == 0b1001010000101000); // 1001 0100 0010 1000

#define SER(x) ((x >> 8) == 0b11101111 and (x & 0b1111) == 0b1111); // 1110 1111 dddd 1111

#define SES(x) (x == 0b1001010001001000); // 1001 0100 0100 1000

#define SET(x) (x == 0b1001010001101000); // 1001 0100 0110 1000
#define SEV(x) (x == 0b1001010000111000); // 1001 0100 0011 1000

#define SEZ(x) (x == 0b1001010000011000); // 1001 0100 0001 1000

#define SLEEP(x) (x == 0b1001010110001000); // 1001 0101 1000 1000

#define SPM(x) (x == 0b1001010111101000); // 1001 0101 1110 1000
#define SPM_I_II_III(x) (x == 0b1001010111101000); // 1001 0101 1110 1000
#define SPM_IV_V_VI(x) (x == 0b1001010111111000); // 1001 0101 1111 1000

#define ST_I(x) ((x >> 9) == 0b1001001 and (x & 0b1111) == 0b1100); // 1001 001r rrrr 1100
#define ST_II(x) ((x >> 9) == 0b1001001 and (x & 0b1111) == 0b1101); // 1001 001r rrrr 1101
#define ST_III(x) ((x >> 9) == 0b1001001 and (x & 0b1111) == 0b1110); // 1001 001r rrrr 1110

#define STD_I(x) ((x >> 9) == 0b1000001 and (x & 0b1111) == 0b1000); // 1000 001r rrrr 1000
#define STD_II(x) ((x >> 9) == 0b1000001 and (x & 0b1111) == 0b1001); // 1001 001r rrrr 1001
#define STD_III(x) ((x >> 9) == 0b1000001 and (x & 0b1111) == 0b1010); // 1001 001r rrrr 1010
#define STD_IV(x) ((x >> 14) == 0b10 and ((x >> 12) & 0x01) == 0x0 and ((x >> 9) & 0x01) == 0x1 and ((x >> 3) & 0x01) == 0x1); // 10q0 qq1r rrrr 1qqq
