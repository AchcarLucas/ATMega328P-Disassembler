packet_instructions *init_instructions() {
    packet_instructions *p_inst = new packet_instructions;

    p_inst->len = 127;
    p_inst->s = new s_instructions[p_inst->len];

    s_instructions *p = p_inst->s;

    for(short int i = 0; i < p_inst->len; ++i) {
        p[i].mnemonic = "None";
        p[i].func_name = "None";
        p[i].mask = "xxxx xxxx xxxx xxxx";
        p[i].f_16 = &CheckNull;
        p[i].f_32 = &CheckNull;
    }

    short int i = 0;

    p[i].func_name = "ADC"; p[i].mask = ADC_MASK; p[i].f_16 = &Check_ADC; ++i;
    p[i].func_name = "ADD"; p[i].mask = ADD_MASK; p[i].f_16 = &Check_ADD; ++i;
    p[i].func_name = "AND"; p[i].mask = AND_MASK; p[i].f_16 = &Check_AND; ++i;
    p[i].func_name = "ANDI"; p[i].mask = ANDI_MASK; p[i].f_16 = &Check_ANDI; ++i;
    p[i].func_name = "ASR"; p[i].mask = ASR_MASK; p[i].f_16 = &Check_ASR; ++i;
    p[i].func_name = "BCLR"; p[i].mask = BCLR_MASK; p[i].f_16 = &Check_BCLR; ++i;
    p[i].func_name = "BLD"; p[i].mask = BLD_MASK; p[i].f_16 = &Check_BLD; ++i;
    p[i].func_name = "BRBC"; p[i].mask = BRBC_MASK; p[i].f_16 = &Check_BRBC; ++i;
    p[i].func_name = "BRBS"; p[i].mask = BRBS_MASK; p[i].f_16 = &Check_BRBS; ++i;
    p[i].func_name = "BREAK"; p[i].mask = BREAK_MASK; p[i].f_16 = &Check_BREAK; ++i;
    p[i].func_name = "BLD"; p[i].mask = BLD_MASK; p[i].f_16 = &Check_BLD; ++i;
    p[i].func_name = "BSET"; p[i].mask = BSET_MASK; p[i].f_16 = &Check_BSET; ++i;
    p[i].func_name = "CBI"; p[i].mask = CBI_MASK; p[i].f_16 = &Check_CBI; ++i;
    p[i].func_name = "COM"; p[i].mask = COM_MASK; p[i].f_16 = &Check_COM; ++i;
    p[i].func_name = "CP"; p[i].mask = CP_MASK; p[i].f_16 = &Check_CP; ++i;
    p[i].func_name = "CPC"; p[i].mask = CPC_MASK; p[i].f_16 = &Check_CPC; ++i;
    p[i].func_name = "CPI"; p[i].mask = CPI_MASK; p[i].f_16 = &Check_CPI; ++i;
    p[i].func_name = "CPSE"; p[i].mask = CPSE_MASK; p[i].f_16 = &Check_CPSE; ++i;
    p[i].func_name = "DEC"; p[i].mask = DEC_MASK; p[i].f_16 = &Check_DEC; ++i;
    p[i].func_name = "DES"; p[i].mask = DES_MASK; p[i].f_16 = &Check_DES; ++i;
    p[i].func_name = "EICALL"; p[i].mask = EICALL_MASK; p[i].f_16 = &Check_EICALL; ++i;
    p[i].func_name = "EIJMP"; p[i].mask = EIJMP_MASK; p[i].f_16 = &Check_EIJMP; ++i;
    p[i].func_name = "ELPM_I"; p[i].mask = ELPM_I_MASK; p[i].f_16 = &Check_ELPM_I; ++i;
    p[i].func_name = "ELPM_II"; p[i].mask = ELPM_II_MASK; p[i].f_16 = &Check_ELPM_II; ++i;
    p[i].func_name = "ELPM_III"; p[i].mask = ELPM_III_MASK; p[i].f_16 = &Check_ELPM_III; ++i;
    p[i].func_name = "EOR"; p[i].mask = EOR_MASK; p[i].f_16 = &Check_EOR; ++i;
    p[i].func_name = "FMUL"; p[i].mask = FMUL_MASK; p[i].f_16 = &Check_FMUL; ++i;
    p[i].func_name = "FMULS"; p[i].mask = FMULS_MASK; p[i].f_16 = &Check_FMULS; ++i;
    p[i].func_name = "FMULSU"; p[i].mask = FMULSU_MASK; p[i].f_16 = &Check_FMULSU; ++i;
    p[i].func_name = "ICALL"; p[i].mask = ICALL_MASK; p[i].f_16 = &Check_ICALL; ++i;
    p[i].func_name = "IJMP"; p[i].mask = IJMP_MASK; p[i].f_16 = &Check_IJMP; ++i;
    p[i].func_name = "IN"; p[i].mask = IN_MASK; p[i].f_16 = &Check_IN; ++i;
    p[i].func_name = "INC"; p[i].mask = INC_MASK; p[i].f_16 = &Check_INC; ++i;
    p[i].func_name = "LAC"; p[i].mask = LAC_MASK; p[i].f_16 = &Check_LAC; ++i;
    p[i].func_name = "LAS"; p[i].mask = LAS_MASK; p[i].f_16 = &Check_LAS; ++i;
    p[i].func_name = "LAT"; p[i].mask = LAT_MASK; p[i].f_16 = &Check_LAT; ++i;
    p[i].func_name = "LD_X_I"; p[i].mask = LD_X_I_MASK; p[i].f_16 = &Check_LD_X_I; ++i;
    p[i].func_name = "LD_X_II"; p[i].mask = LD_X_II_MASK; p[i].f_16 = &Check_LD_X_II; ++i;
    p[i].func_name = "LD_X_III"; p[i].mask = LD_X_III_MASK; p[i].f_16 = &Check_LD_X_III; ++i;
    p[i].func_name = "LD_Y_I"; p[i].mask = LD_Y_I_MASK; p[i].f_16 = &Check_LD_Y_I; ++i;
    p[i].func_name = "LD_Y_II"; p[i].mask = LD_Y_II_MASK; p[i].f_16 = &Check_LD_Y_II; ++i;
    p[i].func_name = "LD_Y_III"; p[i].mask = LD_Y_III_MASK; p[i].f_16 = &Check_LD_Y_III; ++i;
    p[i].func_name = "LD_Y_IV"; p[i].mask = LD_Y_IV_MASK; p[i].f_16 = &Check_LD_Y_IV; ++i;
    p[i].func_name = "LD_Z_I"; p[i].mask = LD_Z_I_MASK; p[i].f_16 = &Check_LD_Z_I; ++i;
    p[i].func_name = "LD_Z_II"; p[i].mask = LD_Z_II_MASK; p[i].f_16 = &Check_LD_Z_II; ++i;
    p[i].func_name = "LD_Z_III"; p[i].mask = LD_Z_III_MASK; p[i].f_16 = &Check_LD_Z_III; ++i;
    p[i].func_name = "LD_Z_IV"; p[i].mask = LD_Z_IV_MASK; p[i].f_16 = &Check_LD_Z_IV; ++i;
    p[i].func_name = "LDI"; p[i].mask = LDI_MASK; p[i].f_16 = &Check_LDI; ++i;
    p[i].func_name = "LDS_16"; p[i].mask = LDS_16_MASK; p[i].f_16 = &Check_LDS_16; ++i;
    p[i].func_name = "LPM_I"; p[i].mask = LPM_I_MASK; p[i].f_16 = &Check_LPM_I; ++i;
    p[i].func_name = "LPM_II"; p[i].mask = LPM_II_MASK; p[i].f_16 = &Check_LPM_II; ++i;
    p[i].func_name = "LPM_III"; p[i].mask = LPM_III_MASK; p[i].f_16 = &Check_LPM_III; ++i;
    p[i].func_name = "LSL"; p[i].mask = LSL_MASK; p[i].f_16 = &Check_LSL; ++i;

    p[i].func_name = "LSR"; p[i].mask = LSR_MASK; p[i].f_16 = &Check_LSR; ++i;
    p[i].func_name = "MOV"; p[i].mask = MOV_MASK; p[i].f_16 = &Check_MOV; ++i;
    p[i].func_name = "MOVW"; p[i].mask = MOVW_MASK; p[i].f_16 = &Check_MOVW; ++i;
    p[i].func_name = "MUL"; p[i].mask = MUL_MASK; p[i].f_16 = &Check_MUL; ++i;
    p[i].func_name = "MULS"; p[i].mask = MULS_MASK; p[i].f_16 = &Check_MULS; ++i;
    p[i].func_name = "MULSU"; p[i].mask = MULSU_MASK; p[i].f_16 = &Check_MULSU; ++i;
    p[i].func_name = "NEG"; p[i].mask = NEG_MASK; p[i].f_16 = &Check_NEG; ++i;

    p[i].func_name = "NOP"; p[i].mask = NOP_MASK; p[i].f_16 = &Check_NOP; ++i;
    p[i].func_name = "OR"; p[i].mask = OR_MASK; p[i].f_16 = &Check_OR; ++i;
    p[i].func_name = "ORI"; p[i].mask = ORI_MASK; p[i].f_16 = &Check_ORI; ++i;
    p[i].func_name = "OUT"; p[i].mask = OUT_MASK; p[i].f_16 = &Check_OUT; ++i;
    p[i].func_name = "POP"; p[i].mask = POP_MASK; p[i].f_16 = &Check_POP; ++i;
    p[i].func_name = "PUSH"; p[i].mask = PUSH_MASK; p[i].f_16 = &Check_PUSH; ++i;
    p[i].func_name = "RCALL"; p[i].mask = RCALL_MASK; p[i].f_16 = &Check_RCALL; ++i;
    p[i].func_name = "RET"; p[i].mask = RET_MASK; p[i].f_16 = &Check_RET; ++i;
    p[i].func_name = "RETI"; p[i].mask = RETI_MASK; p[i].f_16 = &Check_RETI; ++i;
    p[i].func_name = "RJMP"; p[i].mask = RJMP_MASK; p[i].f_16 = &Check_RJMP; ++i;
    p[i].func_name = "ROL"; p[i].mask = ROL_MASK; p[i].f_16 = &Check_ROL; ++i;

    p[i].func_name = "ROR"; p[i].mask = ROR_MASK; p[i].f_16 = &Check_ROR; ++i;
    p[i].func_name = "SBC"; p[i].mask = SBC_MASK; p[i].f_16 = &Check_SBC; ++i;
    p[i].func_name = "SBCI"; p[i].mask = SBCI_MASK; p[i].f_16 = &Check_SBCI; ++i;
    p[i].func_name = "SBI"; p[i].mask = SBI_MASK; p[i].f_16 = &Check_SBI; ++i;
    p[i].func_name = "SBIC"; p[i].mask = SBIC_MASK; p[i].f_16 = &Check_SBIC; ++i;
    p[i].func_name = "SBIS"; p[i].mask = SBIS_MASK; p[i].f_16 = &Check_SBIS; ++i;
    p[i].func_name = "SBIW"; p[i].mask = SBIW_MASK; p[i].f_16 = &Check_SBIW; ++i;
    p[i].func_name = "SBR"; p[i].mask = SBR_MASK; p[i].f_16 = &Check_SBR; ++i;


    p[i].func_name = "SBRC"; p[i].mask = SBRC_MASK; p[i].f_16 = &Check_SBRC; ++i;
    p[i].func_name = "SBRS"; p[i].mask = SBRS_MASK; p[i].f_16 = &Check_SBRS; ++i;
    p[i].func_name = "SEC"; p[i].mask = SEC_MASK; p[i].f_16 = &Check_SEC; ++i;
    p[i].func_name = "SEH"; p[i].mask = SEH_MASK; p[i].f_16 = &Check_SEH; ++i;
    p[i].func_name = "SEI"; p[i].mask = SEI_MASK; p[i].f_16 = &Check_SEI; ++i;
    p[i].func_name = "SEN"; p[i].mask = SEN_MASK; p[i].f_16 = &Check_SEN; ++i;
    p[i].func_name = "SER"; p[i].mask = SER_MASK; p[i].f_16 = &Check_SER; ++i;
    p[i].func_name = "SES"; p[i].mask = SES_MASK; p[i].f_16 = &Check_SES; ++i;
    p[i].func_name = "SET"; p[i].mask = SET_MASK; p[i].f_16 = &Check_SET; ++i;
    p[i].func_name = "SEV"; p[i].mask = SEV_MASK; p[i].f_16 = &Check_SEV; ++i;
    p[i].func_name = "SEZ"; p[i].mask = SEZ_MASK; p[i].f_16 = &Check_SEZ; ++i;
    p[i].func_name = "SLEEP"; p[i].mask = SLEEP_MASK; p[i].f_16 = &Check_SLEEP; ++i;
    p[i].func_name = "SPM"; p[i].mask = SPM_MASK; p[i].f_16 = &Check_SPM; ++i;
    p[i].func_name = "SPM_I_II_III"; p[i].mask = SPM_I_II_III_MASK; p[i].f_16 = &Check_SPM_I_II_III; ++i;
    p[i].func_name = "SPM_IV_V_VI"; p[i].mask = SPM_IV_V_VI_MASK; p[i].f_16 = &Check_SPM_IV_V_VI; ++i;
    p[i].func_name = "ST_X_I"; p[i].mask = ST_X_I_MASK; p[i].f_16 = &Check_ST_X_I; ++i;
    p[i].func_name = "ST_X_II"; p[i].mask = ST_X_II_MASK; p[i].f_16 = &Check_ST_X_II; ++i;
    p[i].func_name = "ST_X_III"; p[i].mask = ST_X_III_MASK; p[i].f_16 = &Check_ST_X_III; ++i;

    p[i].func_name = "STD_Y_I"; p[i].mask = STD_Y_I_MASK; p[i].f_16 = &Check_STD_Y_I; ++i;
    p[i].func_name = "STD_Y_II"; p[i].mask = STD_Y_II_MASK; p[i].f_16 = &Check_STD_Y_II; ++i;
    p[i].func_name = "STD_Y_III"; p[i].mask = STD_Y_III_MASK; p[i].f_16 = &Check_STD_Y_III; ++i;
    p[i].func_name = "STD_Y_IV"; p[i].mask = STD_Y_IV_MASK; p[i].f_16 = &Check_STD_Y_IV; ++i;

    p[i].func_name = "STD_Z_I"; p[i].mask = STD_Z_I_MASK; p[i].f_16 = &Check_STD_Z_I; ++i;
    p[i].func_name = "STD_Z_II"; p[i].mask = STD_Z_II_MASK; p[i].f_16 = &Check_STD_Z_II; ++i;
    p[i].func_name = "STD_Z_III"; p[i].mask = STD_Z_III_MASK; p[i].f_16 = &Check_STD_Z_III; ++i;
    p[i].func_name = "STD_Z_IV"; p[i].mask = STD_Z_IV_MASK; p[i].f_16 = &Check_STD_Z_IV; ++i;

    p[i].func_name = "STS_16"; p[i].mask = STS_16_MASK; p[i].f_16 = &Check_STS_16; ++i;
    p[i].func_name = "SUB"; p[i].mask = SUB_MASK; p[i].f_16 = &Check_SUB; ++i;
    p[i].func_name = "SUBI"; p[i].mask = SUBI_MASK; p[i].f_16 = &Check_SUBI; ++i;
    p[i].func_name = "SWAP"; p[i].mask = SWAP_MASK; p[i].f_16 = &Check_SWAP; ++i;
    p[i].func_name = "TST"; p[i].mask = TST_MASK; p[i].f_16 = &Check_TST; ++i;
    p[i].func_name = "WDR"; p[i].mask = WDR_MASK; p[i].f_16 = &Check_WDR; ++i;
    p[i].func_name = "WDR"; p[i].mask = XCH_MASK; p[i].f_16 = &Check_XCH; ++i;

    p[i].func_name = "LDS_32"; p[i].mask = LDS_32_MASK; p[i].f_32 = &Check_LDS_32; ++i;
    p[i].func_name = "JMP"; p[i].mask = JMP_MASK; p[i].f_32 = &Check_JMP; ++i;
    p[i].func_name = "CALL"; p[i].mask = CALL_MASK; p[i].f_32 = &Check_CALL; ++i;
    p[i].func_name = "STS_32"; p[i].mask = STS_32_MASK; p[i].f_32 = &Check_STS_32; ++i;

    return p_inst;
}
