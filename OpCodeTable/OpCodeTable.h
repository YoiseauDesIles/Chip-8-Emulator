#pragma once

#include <iostream>
#include <map>
#include <array>

enum EnumInstruction {
    ERRORS = -1,
    RCA1802_NNN = 0, 
    CLEAR_S = 1,
    RETURN,
    JUMP_NNN,
    SUBROUTINE,
    JUMP_VX_EQ_NN,
    JUMP_VX_NEQ_NN,
    JUMP_VX_EQ_VY,
    SET_VX_NN,
    ADD_NN_VX,
    SET_VX_VY,
    SET_VX_VX_OR_VY,
    SET_VX_VX_AND_VY,
    SET_VX_VX_XOR_VY,
    ADD_VY_VX,
    SUB_VX_VY,
    SHIFTRIGHT_VX,
    SUB_VY_VX,
    SHIFTLEFT_VX,
    JUMP_VX_NEQ_VY,
    SET_NNN_I,
    GOTO_NNN_PLUS_VO,
    SET_VX_RDM_NN,
    DRAW,
    JUMP_NEXT_IF_X_PRESSED,
    JUMP_NEXT_IF_X_NOT_PRESSED,
    SET_VX_DELAY,
    SET_INPUT_VX,
    SET_DELAY_VX,
    SET_VX_SOUND_DELAY,
    ADD_VX_I,
    SET_I_VX_CHAR,
    STORE_MEM_VX_DECIMAL,
    STORE_MEM_V0_VX_FROM_I,
    LOAD_MEM_TO_VO_VX_FROM_I
    };

class OpCodeTable 
{
    private:
        std::array<std::pair<uint16_t, uint16_t>, 35> maskList;

        void initMaskMap();

    public:
        OpCodeTable();
        virtual ~OpCodeTable() {}

        EnumInstruction getInstruction(uint16_t opcode) const;

};

