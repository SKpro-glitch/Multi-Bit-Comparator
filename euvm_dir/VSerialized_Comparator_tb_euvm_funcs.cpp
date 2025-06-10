#include "Vadder_avst.h"

Vadder_avst* create_VSerialized_Comparator_tb() {
    return new VSerialized_Comparator_tb();
}

void eval (VSerialized_Comparator_tb* obj) {
    obj->eval();
}

void finalize (VSerialized_Comparator_tb* obj) {
    obj->final();
}
