`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module Multi_Bit_Comparator_PowerGated #(parameter n=3) (
    input enable, reset,
    input [n:0] a_in, b_in,
    
    output reg less_than, equal_to, greater_than
    );
    
    //These registers are created to enable power-gating
    reg [n:0] a, b;
    //The enable function can be replaced by a clock, or used asynchronously
    always @ (posedge enable) #1 {a, b} = {a_in, b_in}; //Input is taken in at the beginning of the enable
    
    //These wires take the output from each single-bit comparator
    wire [n:0] less, equal, greater;
    
    Single_Bit_Comparator_PowerGated comp(
    .enable(enable), 
    .reset(reset),
    .a(a[n]), .b(b[n]),
    .less_than(less[n]),
    .equal_to(equal[n]),
    .greater_than(greater[n])
    );

    //Instances of the Single Bit Comparator are generated for each bit of the input
    genvar i;
    generate
        for(i=0; i<n; i=i+1) begin
            Single_Bit_Comparator_PowerGated comp0(
                .enable(equal[i+1]), 
                .reset(reset),
                .a(a[i]), .b(b[i]),
                .less_than(less[i]),
                .equal_to(equal[i]),
                .greater_than(greater[i])
                );
        end
    endgenerate
    
    //Output can be generated any time during the evaluation of the circuit
    always @ (*) begin 
        #1 less_than = |less;
        #1 greater_than = |greater;
        #1 equal_to = equal[0];
    end
    
endmodule
