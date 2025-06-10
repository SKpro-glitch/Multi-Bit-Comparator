#include "VMulti_Bit_Comparator_Serialized.h"

VMulti_Bit_Comparator_Serialized* create_VMulti_Bit_Comparator_Serialized() {
    return new VMulti_Bit_Comparator_Serialized();
}

void eval (VMulti_Bit_Comparator_Serialized* obj) {
    obj->eval();
}

void finalize (VMulti_Bit_Comparator_Serialized* obj) {
    obj->final();
}
