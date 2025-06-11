#include "VSerialized_Comparator.h"

VSerialized_Comparator* create_VSerialized_Comparator() {
    return new VSerialized_Comparator();
}

void eval (VSerialized_Comparator* obj) {
    obj->eval();
}

void finalize (VSerialized_Comparator* obj) {
    obj->final();
}
