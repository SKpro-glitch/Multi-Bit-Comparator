`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module Multi_Bit_Comparator_Serialized #(parameter n=3) (    
    input clk, reset,
    input [n:0] a_in, b_in,
    
    output reg less_than, equal_to, greater_than,
    output reg [n:0] a, b, c
    );
    
    //These registers are created to enable serialization
    reg start=1;
    
    always @ (posedge clk) begin
        //The reset line will initialize all outputs to zero and the counter to all 1s
        if(reset) begin
            {less_than, equal_to, greater_than} = 3'b010;
            c = {(n+1){1'b1}};
            start = 1'b1;
        end
        else if(start) begin
            #1 {a, b} = {a_in, b_in}; //Input is taken in at the beginning of the operation
            c = {(n+1){1'b1}};
            start = 0; //Once the comparision is started new input will not be taken
        end
    end
    
    always @ (posedge clk && equal_to) begin //Next bits are checked only if current bits are equal
        #2;
        if(|c) begin //As long as counter is non-zero, it serial input will be taken
            if(reset) {less_than, equal_to, greater_than} = 3'b000;
            else if(a[n]^b[n]) {less_than, equal_to, greater_than} = {b[n], 1'b0, a[n]};
            else {less_than, equal_to, greater_than} = 3'b010;
            
            #1 a = a << 1;
            #1 b = b << 1;
            #1 c = c << 1;
        end
    end
        
endmodule