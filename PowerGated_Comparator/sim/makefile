CC              = gcc
CFLAGS		= -Wall -O3 -fPIC
SEED            = 1

DFLAGS = -relocation-model=pic -w -O3

LDC2BINDIR = $(dir $(shell which ldc2))
VLBINDIR = $(dir $(shell which verilator))
VERBOSITY=UVM_DEBUG

VLATOR_SRC = euvm_dir/VMulti_Bit_Comparator_PowerGated_euvm.d euvm_dir/VMulti_Bit_Comparator_PowerGated_euvm_funcs.cpp obj_dir/VMulti_Bit_Comparator_PowerGated.cpp obj_dir/VMulti_Bit_Comparator_PowerGated.h

.PHONY: all clean

all: Multi_Bit_Comparator_PowerGated

clean:
	rm -rf Multi_Bit_Comparator_PowerGated* euvm_dir obj_dir verilator.stamp

run: Multi_Bit_Comparator_PowerGated
	./Multi_Bit_Comparator_PowerGated +UVM_TESTNAME=Test.test +UVM_VERBOSITY=$(VERBOSITY) +seed=$(SEED) # +UVM_OBJECTION_TRACE

verilator.stamp: ../rtl/Multi_Bit_Comparator_PowerGated.v \
	#../rtl/Single_Bit_Comparator_PowerGated.v
	touch verilator.stamp
	verilator --no-timing --threads 1 --trace --cc --euvm $^
	(cd euvm_dir; g++ -c -I ../obj_dir/ -I $(VLBINDIR)/../share/verilator/include VMulti_Bit_Comparator_PowerGated_euvm_funcs.cpp)
	(cd euvm_dir; g++ -c -I ../obj_dir/ -I $(VLBINDIR)/../share/verilator/include $(LDC2BINDIR)/../import/esdl/intf/verilator/cpp/verilated_vcd_d.cpp -o verilated_vcd_d.o)
	(cd euvm_dir; g++ -c -I ../obj_dir/ -I $(VLBINDIR)/../share/verilator/include $(LDC2BINDIR)/../import/esdl/intf/verilator/cpp/verilated_d.cpp -o verilated_d.o)
	(cd obj_dir; make -f VMulti_Bit_Comparator_PowerGated.mk VMulti_Bit_Comparator_PowerGated__ALL.a verilated.o verilated_vcd_c.o verilated_threads.o)

euvm_dir/VMulti_Bit_Comparator_PowerGated_euvm.d euvm_dir/VMulti_Bit_Comparator_PowerGated_euvm_funcs.o euvm_dir/verilated_vcd_d.o obj_dir/VMulti_Bit_Comparator_PowerGated__ALL.a obj_dir/verilated.o: verilator.stamp


Multi_Bit_Comparator_PowerGated: ../testbench/PowerGated_Comparator_tb.d \
		../testbench/Item.d \
		../testbench/Sequencer.d \
		../testbench/Sequence.d \
		../testbench/Interface.d \
		../testbench/Driver.d \
		../testbench/Monitor.d \
		../testbench/Agent.d \
		../testbench/Scoreboard.d \
		../testbench/Environment.d \
		../testbench/Test.d \
	   euvm_dir/VMulti_Bit_Comparator_PowerGated_euvm.d  \
	   $(LDC2BINDIR)/../import/esdl/intf/verilator/trace.d \
	   euvm_dir/verilated_vcd_d.o euvm_dir/verilated_d.o \
	   euvm_dir/VMulti_Bit_Comparator_PowerGated_euvm_funcs.o  \
	   obj_dir/VMulti_Bit_Comparator_PowerGated__ALL.a \
	   obj_dir/verilated.o  obj_dir/verilated_threads.o obj_dir/verilated_vcd_c.o \
	   obj_dir/verilated_threads.o
	ldc2 $(DFLAGS) -Ieuvm_dir -link-defaultlib-shared -of$@ -L-luvm-ldc-shared -L-lesdl-ldc-shared -L-lz3 \
		-L-lphobos2-ldc-shared -L-ldl $^ -L-lstdc++

run_overide: Multi_Bit_Comparator_PowerGated
	./Multi_Bit_Comparator_PowerGated +UVM_TESTNAME=Test.test +UVM_VERBOSITY=$(VERBOSITY) +seed=$(SEED) +UVM_SET_TYPE_OVERRIDE=Multi_Bit_Comparator_PowerGated.item # +UVM_OBJECTION_TRACE
