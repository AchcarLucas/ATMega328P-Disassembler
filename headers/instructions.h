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
#define BCLR(x) ((x >> 7) == b100101001 and (x & 0b1111) == 0b1000); // 1001 0100 1sss 1000

#define BCLR(x) ((x >> 9) == 0b1111100 and ((x >> 3) & 1) == 0); // 1111 100d dddd 0bbb

// Branch if Bit in SREG is Cleared
#define BRBC(x) ((x >> 10) == 0b111101); // 1111 01kk kkkk ksss

// Branch if Bit in SREG is Set
#define BRBS(x) ((x >> 10) == 0b111100); // 1111 00kk kkkk ksss

#define BREAK(x) (x == 0b1001010110011000); // 1001 0101 1001 1000

// Bit Set in SREG
#define BSET(x) ((x >> 7) == 0b100101000 and (x & 0b1111) == 1000); // 1001 0100 0sss 1000




