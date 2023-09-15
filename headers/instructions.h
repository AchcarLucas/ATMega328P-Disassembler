#include <sstream>

#include "opcode.h"

#define WORD 2

#define STR_NONE ".WORD"
#define STR_NOP "NOP"

#define R_REGISTER "r"


struct inst {
    std::string mnemonic_assembly;
    PC pc;
};

struct s_instructions {
    std::string mnemonic;
    std::string func_name;
    std::string mask;

    bool (*c_16)(std::bitset<16>);
    bool (*c_32)(std::bitset<32>);

    inst *(*e_16)(inst *, s_instructions, std::bitset<16>);
    inst *(*e_32)(inst *, s_instructions, std::bitset<32>);
};

struct packet_instructions {
    s_instructions *s;
    short int len;
};

/*
* Funções de verificação dos opcodes
*/

bool Check_ADC(std::bitset<16> x) { return ADC(x) }
bool Check_ADD(std::bitset<16> x) { return ADD(x) }
bool Check_AND(std::bitset<16> x) { return AND(x) }
bool Check_ANDI(std::bitset<16> x) { return ANDI(x) }
bool Check_ASR(std::bitset<16> x) { return ASR(x) }
bool Check_BCLR(std::bitset<16> x) { return BCLR(x) }
bool Check_BLD(std::bitset<16> x) { return BLD(x) }
bool Check_BRBC(std::bitset<16> x) { return BRBC(x) }
bool Check_BRBS(std::bitset<16> x) { return BRBS(x) }
bool Check_BRCC(std::bitset<16> x) { return BRCC(x) }
bool Check_BRCS(std::bitset<16> x) { return BRCS(x) }
bool Check_BREAK(std::bitset<16> x) { return BREAK(x) }
bool Check_BREQ(std::bitset<16> x) {return BREQ(x) }
bool Check_BSET(std::bitset<16> x) { return BSET(x) }
bool Check_BST(std::bitset<16> x) { return BST(x) }
bool Check_CALL(std::bitset<32> x) { return CALL(x) }
bool Check_CBI(std::bitset<16> x) { return CBI(x) }
bool Check_CLC(std::bitset<16> x) { return CLC(x) }
bool Check_CLH(std::bitset<16> x) { return CLH(x) }
bool Check_CLI(std::bitset<16> x) { return CLI(x) }
bool Check_CLN(std::bitset<16> x) { return CLN(x) }
bool Check_CLR(std::bitset<16> x) { return CLR(x) }
bool Check_CLS(std::bitset<16> x) { return CLS(x) }
bool Check_CLT(std::bitset<16> x) { return CLT(x) }
bool Check_CLV(std::bitset<16> x) { return CLV(x) }
bool Check_CLZ(std::bitset<16> x) { return CLZ(x) }
bool Check_COM(std::bitset<16> x) { return COM(x) }
bool Check_CP(std::bitset<16> x) { return CP(x) }
bool Check_CPC(std::bitset<16> x) { return CPC(x) }
bool Check_CPI(std::bitset<16> x) { return CPI(x) }
bool Check_CPSE(std::bitset<16> x) { return CPSE(x) }
bool Check_DEC(std::bitset<16> x) { return DEC(x) }
bool Check_DES(std::bitset<16> x) { return DES(x) }
bool Check_EICALL(std::bitset<16> x) { return EICALL(x) }
bool Check_EIJMP(std::bitset<16> x) { return EIJMP(x) }
bool Check_ELPM_I(std::bitset<16> x) { return ELPM_I(x) }
bool Check_ELPM_II(std::bitset<16> x) { return ELPM_II(x) }
bool Check_ELPM_III(std::bitset<16> x) { return ELPM_III(x) }
bool Check_EOR(std::bitset<16> x) { return EOR(x) }
bool Check_FMUL(std::bitset<16> x) { return FMUL(x) }
bool Check_FMULS(std::bitset<16> x) { return FMULS(x) }
bool Check_FMULSU(std::bitset<16> x) { return FMULSU(x) }
bool Check_ICALL(std::bitset<16> x) { return ICALL(x) }
bool Check_IJMP(std::bitset<16> x) { return IJMP(x) }
bool Check_IN(std::bitset<16> x) { return IN(x) }
bool Check_INC(std::bitset<16> x) { return INC(x) }
bool Check_JMP(std::bitset<32> x) { return JMP(x) }
bool Check_LAC(std::bitset<16> x) { return LAC(x) }
bool Check_LAS(std::bitset<16> x) { return LAS(x) }
bool Check_LAT(std::bitset<16> x) { return LAT(x) }
bool Check_LD_X_I(std::bitset<16> x) { return LD_X_I(x) }
bool Check_LD_X_II(std::bitset<16> x) { return LD_X_II(x) }
bool Check_LD_X_III(std::bitset<16> x) { return LD_X_III(x) }
bool Check_LD_Y_I(std::bitset<16> x) { return LD_Y_I(x) }
bool Check_LD_Y_II(std::bitset<16> x) { return LD_Y_II(x) }
bool Check_LD_Y_III(std::bitset<16> x) { return LD_Y_III(x) }
bool Check_LD_Y_IV(std::bitset<16> x) { return LD_Y_IV(x) }
bool Check_LD_Z_I(std::bitset<16> x) { return LD_Z_I(x) }
bool Check_LD_Z_II(std::bitset<16> x) { return LD_Z_II(x) }
bool Check_LD_Z_III(std::bitset<16> x) { return LD_Z_III(x) }
bool Check_LD_Z_IV(std::bitset<16> x) { return LD_Z_IV(x) }
bool Check_LDI(std::bitset<16> x) { return LDI(x) }
bool Check_LDS_32(std::bitset<32> x) { return LDS_32(x) }
bool Check_LDS_16(std::bitset<16> x) { return LDS_16(x) }
bool Check_LPM_I(std::bitset<16> x) { return LPM_I(x) }
bool Check_LPM_II(std::bitset<16> x) { return LPM_II(x) }
bool Check_LPM_III(std::bitset<16> x) { return LPM_III(x) }
bool Check_LSL(std::bitset<16> x) { return LSL(x) }
bool Check_LSR(std::bitset<16> x) { return LSR(x) }
bool Check_MOV(std::bitset<16> x) { return MOV(x) }
bool Check_MOVW(std::bitset<16> x) { return MOVW(x) }
bool Check_MUL(std::bitset<16> x) { return MUL(x) }
bool Check_MULS(std::bitset<16> x) { return MULS(x) }
bool Check_MULSU(std::bitset<16> x) { return MULSU(x) }
bool Check_NEG(std::bitset<16> x) { return NEG(x) }
bool Check_NOP(std::bitset<16> x) { return NOP(x) }
bool Check_OR(std::bitset<16> x) { return OR(x) }
bool Check_ORI(std::bitset<16> x) { return ORI(x) }
bool Check_OUT(std::bitset<16> x) { return OUT(x) }
bool Check_POP(std::bitset<16> x) { return POP(x) }
bool Check_PUSH(std::bitset<16> x) { return PUSH(x) }
bool Check_RCALL(std::bitset<16> x) { return RCALL(x) }
bool Check_RET(std::bitset<16> x) { return RET(x) }
bool Check_RETI(std::bitset<16> x) { return RETI(x) }
bool Check_RJMP(std::bitset<16> x) { return RJMP(x) }
bool Check_ROL(std::bitset<16> x) { return ROL(x) }
bool Check_ROR(std::bitset<16> x) { return ROR(x) }
bool Check_SBC(std::bitset<16> x) { return SBC(x) }
bool Check_SBCI(std::bitset<16> x) { return SBCI(x) }
bool Check_SBI(std::bitset<16> x) { return SBI(x) }
bool Check_SBIC(std::bitset<16> x) { return SBIC(x) }
bool Check_SBIS(std::bitset<16> x) { return SBIS(x) }
bool Check_SBIW(std::bitset<16> x) { return SBIW(x) }
bool Check_SBR(std::bitset<16> x) { return SBR(x) }
bool Check_SBRC(std::bitset<16> x) { return SBRC(x) }
bool Check_SBRS(std::bitset<16> x) { return SBRS(x) }
bool Check_SEC(std::bitset<16> x) { return SEC(x) }
bool Check_SEH(std::bitset<16> x) { return SEH(x) }
bool Check_SEI(std::bitset<16> x) { return SEI(x) }
bool Check_SEN(std::bitset<16> x) { return SEN(x) }
bool Check_SER(std::bitset<16> x) { return SER(x) }
bool Check_SES(std::bitset<16> x) { return SES(x) }
bool Check_SET(std::bitset<16> x) { return SET(x) }
bool Check_SEV(std::bitset<16> x) { return SEV(x) }
bool Check_SEZ(std::bitset<16> x) { return SEZ(x) }
bool Check_SLEEP(std::bitset<16> x) { return SLEEP(x) }
bool Check_SPM(std::bitset<16> x) { return SPM(x) }
bool Check_SPM_I_II_III(std::bitset<16> x) { return SPM_I_II_III(x) }
bool Check_SPM_IV_V_VI(std::bitset<16> x) { return SPM_IV_V_VI(x) }
bool Check_ST_X_I(std::bitset<16> x) { return ST_X_I(x) }
bool Check_ST_X_II(std::bitset<16> x) { return ST_X_II(x) }
bool Check_ST_X_III(std::bitset<16> x) { return ST_X_III(x) }
bool Check_STD_Y_I(std::bitset<16> x) { return STD_Y_I(x) }
bool Check_STD_Y_II(std::bitset<16> x) { return STD_Y_II(x) }
bool Check_STD_Y_III(std::bitset<16> x) { return STD_Y_III(x) }
bool Check_STD_Y_IV(std::bitset<16> x) { return STD_Y_IV(x) }
bool Check_STD_Z_I(std::bitset<16> x) { return STD_Z_I(x) }
bool Check_STD_Z_II(std::bitset<16> x) { return STD_Z_II(x) }
bool Check_STD_Z_III(std::bitset<16> x) { return STD_Z_III(x) }
bool Check_STD_Z_IV(std::bitset<16> x) { return STD_Z_IV(x) }
bool Check_STS_32(std::bitset<32> x) { return STS_32(x) }
bool Check_STS_16(std::bitset<16> x) { return STS_16(x) }
bool Check_SUB(std::bitset<16> x) { return SUB(x) }
bool Check_SUBI(std::bitset<16> x) { return SUBI(x) }
bool Check_SWAP(std::bitset<16> x) { return SWAP(x) }
bool Check_TST(std::bitset<16> x) { return TST(x) }
bool Check_WDR(std::bitset<16> x) { return WDR(x) }
bool Check_XCH(std::bitset<16> x) { return XCH(x) }

bool CheckNull(std::bitset<32> x) { return true; }
bool CheckNull(std::bitset<16> x) { return true; }

std::string hex_format(int value, bool initial_zero = true)
{
    std::stringstream stream;
    stream << ((initial_zero) ? "0x" : "") << std::hex << value;
    return stream.str();
}

/*
* Funções de execução dos opcodes
*/

inst *E_JMP(inst *i, s_instructions s, std::bitset<32> x) {

    int k = 0;

    // 5 bytes range [24 - 20]
    for (int b = 24; b >= 20; --b) {
        k <<= 1;
        k |= x[b];
    }

    // 16 bytes range [15 - 0]
    for (int b = 15; b >= 0; --b) {
        k <<= 1;
        k |= x[b];
    }

    std::stringstream stream;

    stream << i->mnemonic_assembly << " " << hex_format(k * WORD);
    i->mnemonic_assembly = stream.str();

    return i;
}

inst *E_ADC(inst *i, s_instructions s, std::bitset<16> x) {
    return i;
}

inst *E_ADD(inst *i, s_instructions s, std::bitset<16> x) {
    return i;
}

/*
 * Página 79 (AVR Instruction Set Manual)
 */
inst *E_CPC(inst *i, s_instructions s, std::bitset<16> x) {
    unsigned short Rd = (x.to_ulong() >> 4) & 0b11111;
    unsigned short Rr = (((x.to_ulong() >> 5) & 0b10000) | (x.to_ulong() & 0b1111)) & 0b11111;

    std::stringstream stream;

    stream << i->mnemonic_assembly << " " << R_REGISTER << Rd << ", " << R_REGISTER <<  Rr;
    i->mnemonic_assembly = stream.str();

    return i;
}

/*
 * Página 126 (AVR Instruction Set Manual)
 */
inst *E_MULS(inst *i, s_instructions s, std::bitset<16> x) {
    unsigned short Rd = ((x.to_ulong() >> 4) & 0b1111) + 0x10;
    unsigned short Rr = (x.to_ulong() & 0b1111) + 0x10;

    std::stringstream stream;

    stream << i->mnemonic_assembly << " " << R_REGISTER << Rd << ", " << R_REGISTER <<  Rr;
    i->mnemonic_assembly = stream.str();

    return i;
}

/*
 * Página 127 (AVR Instruction Set Manual)
 */
inst *E_MULSU(inst *i, s_instructions s, std::bitset<16> x) {
    unsigned short Rd = ((x.to_ulong() >> 3) & 0b111) + 0x10;
    unsigned short Rr = (x.to_ulong() & 0b111) + 0x10;

    std::stringstream stream;

    stream << i->mnemonic_assembly << " " << R_REGISTER << Rd << ", " << R_REGISTER <<  Rr;
    i->mnemonic_assembly = stream.str();

    return i;
}

inst *E_NONE_16(inst *i, s_instructions s, std::bitset<16> x) {
    /*
     * verificamos se a função  diferente de NOP, se for vamos exibir um .word com o hex
     * de 16 bits (0xFFFF) indicando um opcode inválido
     */
    if(s.func_name != std::string(STR_NOP)) {
        std::stringstream stream;
        stream << std::string(STR_NONE) << " 0x" << std::setw(4) << std::setfill('0') << std::hex << x.to_ulong();
        i->mnemonic_assembly = stream.str();
    }
    return i;
}

inst *E_NONE_32(inst *i, s_instructions s, std::bitset<32> x) {
    /*
     * verificamos se a função  diferente de NOP, se for vamos exibir um .word com o hex
     * de 32 bits (0xFFFFFFFF) indicando um opcode inválido
     */
    if(s.func_name != std::string(STR_NOP)) {
        std::stringstream stream;
        stream << std::string(STR_NONE) << " 0x" << std::setw(8) << std::setfill('0') << std::hex << x.to_ulong();
        i->mnemonic_assembly = stream.str();
    }
    return i;
}

/*
* search_instruction função que irá verificar qual instrução é correspondente ao bitcode
*/

inst *search_instruction(packet_instructions *p_inst, PC pc, std::bitset<16> bitcode_16, std::bitset<32> bitcode_32) {
    s_instructions *p = p_inst->s;

    #if defined(_WIN32) || defined(_WIN64)
        str::cout << std::hex << (pc * 0x02) << ":" << std::setw(4) << std::setfill('0');
    #else
        std::cout << "\x1B[32m" << std::hex << (pc * 0x02) << "\033[0m" << ":" << "\t\t";
    #endif

    for(short int i = 0; i < p_inst->len; ++i) {
            p[i].mask.erase(std::remove(p[i].mask.begin(), p[i].mask.end(), ' '), p[i].mask.end());

            if(p[i].mask.length() == 16 && p[i].c_16(bitcode_16)) {
                IF_DEBUG std::cout << std::setw(4) << std::setfill('0') << bitcode_16.to_ulong() << "\t\t" << " ";
                inst *t_i = new inst();
                t_i->mnemonic_assembly = p[i].func_name;
                // increase 16 bits
                t_i->pc += 1;
                return p[i].e_16(t_i, p[i], bitcode_16);
            } else if(p[i].mask.length() == 32 && p[i].c_32(bitcode_32)) {
                IF_DEBUG std::cout << std::setw(8) << std::setfill('0') << std::hex << bitcode_32.to_ulong() << "\t" <<" ";
                inst *t_i = new inst();
                t_i->mnemonic_assembly = p[i].func_name;
                // increase 32 bits
                t_i->pc += 2;
                return p[i].e_32(t_i, p[i], bitcode_32);
            }
    }

    return NULL;
}
