#pragma once

#include <iostream>

class Registry
{
    private:
        uint8_t V0 = 0x00;
        uint8_t V1 = 0x00;
        uint8_t V2 = 0x00;
        uint8_t V3 = 0x00;
        uint8_t V4 = 0x00;
        uint8_t V5 = 0x00;
        uint8_t V6 = 0x00;
        uint8_t V7 = 0x00;
        uint8_t V8 = 0x00;
        uint8_t V9 = 0x00;
        uint8_t VA = 0x00;
        uint8_t VB = 0x00;
        uint8_t VC = 0x00;
        uint8_t VD = 0x00;
        uint8_t VE = 0x00;
        uint8_t VF = 0x00;
        uint16_t I = 0x0000;

    public:

        Registry() {}
        uint8_t getV0() const { return V0; }
        uint8_t getV1() const { return V1; }
        uint8_t getV2() const { return V2; }
        uint8_t getV3() const { return V3; }
        uint8_t getV4() const { return V4; }
        uint8_t getV5() const { return V5; }
        uint8_t getV6() const { return V6; }
        uint8_t getV7() const { return V7; }
        uint8_t getV8() const { return V8; }
        uint8_t getV9() const { return V9; }
        uint8_t getVA() const { return VA; }
        uint8_t getVB() const { return VB; }
        uint8_t getVC() const { return VC; }
        uint8_t getVD() const { return VD; }
        uint8_t getVE() const { return VE; }
        uint8_t getVF() const { return VF; }
        uint16_t getI() const { return I; }
        
        void setV0(uint8_t reg) {V0 = reg;}
        void setV1(uint8_t reg) {V1 = reg;}
        void setV2(uint8_t reg) {V2 = reg;}
        void setV3(uint8_t reg) {V3 = reg;}
        void setV4(uint8_t reg) {V4 = reg;}
        void setV5(uint8_t reg) {V5 = reg;}
        void setV6(uint8_t reg) {V6 = reg;}
        void setV7(uint8_t reg) {V7 = reg;}
        void setV8(uint8_t reg) {V8 = reg;}
        void setV9(uint8_t reg) {V9 = reg;}
        void setVA(uint8_t reg) {VA = reg;}
        void setVB(uint8_t reg) {VB = reg;}
        void setVC(uint8_t reg) {VC = reg;}
        void setVD(uint8_t reg) {VD = reg;}
        void setVE(uint8_t reg) {VE = reg;}
        void setVF(uint8_t reg) {VF = reg;}
        void setI(uint16_t reg) {I = reg;}
};