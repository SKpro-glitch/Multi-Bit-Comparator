CC              = gcc
CFLAGS		= -Wall -O3 -fPIC
SEED            = 1

DFLAGS = -relocation-model=pic -w -O3

LDC2BINDIR = $(dir $(shell which ldc2))
VLBINDIR = $(dir $(shell which verilator))
VERBOSITY = NONE

VLATOR_SRC = euvm_dir/VSerialized_Comparator_euvm.d euvm_dir/VSerialized_Comparator_euvm_funcs.cpp obj_dir/VSerialized_Comparator.cpp obj_dir/VSerialized_Comparator.h

.PHONY: all clean

all: Serialized_Comparator

clean:
	rm -rf euvm_dir obj_dir verilator.stamp

run: Serialized_Comparator
	./Serialized_Comparator +UVM_TESTNAME=Serialized_Comparator.random_test +UVM_VERBOSITY=$(VERBOSITY) +random_seed=$(SEED) # +UVM_OBJECTION_TRACE

verilator.stamp: Serialized_Comparator.v
	touch verilator.stamp
	verilator --no-timing --threads 1 --trace --cc --euvm $^
	(cd euvm_dir; g++ -c -I ../obj_dir/ -I $(VLBINDIR)/../share/verilator/include VSerialized_Comparator_euvm_funcs.cpp)
	(cd euvm_dir; g++ -c -I ../obj_dir/ -I $(VLBINDIR)/../share/verilator/include $(LDC2BINDIR)/../import/esdl/intf/verilator/cpp/verilated_vcd_d.cpp -o verilated_vcd_d.o)
	(cd euvm_dir; g++ -c -I ../obj_dir/ -I $(VLBINDIR)/../share/verilator/include $(LDC2BINDIR)/../import/esdl/intf/verilator/cpp/verilated_d.cpp -o verilated_d.o)
	(cd obj_dir; make -f VSerialized_Comparator.mk VSerialized_Comparator__ALL.a verilated.o verilated_vcd_c.o verilated_threads.o)

euvm_dir/VSerialized_Comparator_euvm.d euvm_dir/VSerialized_Comparator_euvm_funcs.o euvm_dir/verilated_vcd_d.o obj_dir/VSerialized_Comparator__ALL.a obj_dir/verilated.o: verilator.stamp


Serialized_Comparator: Serialized_Comparator.d \
	   euvm_dir/VSerialized_Comparator_euvm.d  \
	   $(LDC2BINDIR)../import/esdl/intf/verilator/trace.d \
	   euvm_dir/verilated_vcd_d.o euvm_dir/verilated_d.o \
	   euvm_dir/VSerialized_Comparator_euvm_funcs.o  \
	   obj_dir/VSerialized_Comparator__ALL.a \
	   obj_dir/verilated.o  obj_dir/verilated_threads.o obj_dir/verilated_vcd_c.o \
	   obj_dir/verilated_threads.o
	ldc2 $(DFLAGS) -Ieuvm_dir -link-defaultlib-shared -of$@ -L-luvm-ldc-shared -L-lesdl-ldc-shared -L-lz3 \
		-L-lphobos2-ldc-shared -L-ldl $^ -L-lstdc++

run_overide: Serialized_Comparator
	./Serialized_Comparator +UVM_TESTNAME=Serialized_Comparator.random_test +UVM_VERBOSITY=$(VERBOSITY) +random_seed=$(SEED) +UVM_SET_TYPE_OVERRIDE=Serialized_Comparator.comp_item # +UVM_OBJECTION_TRACE
