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

// REGISTRO X, Y ou Z (SALVA O CONTE?DO INDIRETAMENTE NA MEMORIA)
struct DATA_INDIRECT_ADDRESS {
    unsigned short int opcode : 16;
};

// REGISTRO X, Y ou Z (DECREMENTA O CONTE?DO) - ANTES DA OPERA??O
struct DATA_INDIRECT_ADDRESS_PRE_DECREMENT {
    unsigned short int opcode : 16;
};

// REGISTRO X, Y ou Z (INCREMENTA O CONTE?DO) DEPOIS DA OPERA??O
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
    unsigned char opcode : 4
    unsigned short int k : 12
};

// 32 BITS - OPCODE

struct DATA_DIRECT_ADDRESS {
    unsigned short int opcode : 11
    unsigned char Rr_Rd : 4
    unsigned short int data_address : 16
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
