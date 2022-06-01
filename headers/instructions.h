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
#define ASR(x) ((x >> 9) == 0b1001010 and (x & 0b1111) == 0b0101); // 11001 010d dddd 0101

// Bit Clear in SREG
#define BCLR(x) ((x >> 7) == 0b100101001 and (x & 0b1111) == 0b1000); // 1001 0100 1sss 1000

#define BLD(x) ((x >> 9) == 0b1111100 and (x & 0b1000) == 0x00); // 1111 100d dddd 0bbb

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

