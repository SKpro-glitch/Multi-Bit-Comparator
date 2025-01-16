`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module Multi_Bit_Comparator #(parameter n=3) (    
    input clk, reset,
    input [n:0] a_in, b_in,
    
    output reg less_than, equal_to, greater_than
    );
    
    //These registers are created to enable serialization
    reg [n:0] a, b, c;
    
    //The start register notes when the comparision process is going on
    reg start=1;
    
    always @ (posedge clk) begin
        //The reset line will initialize all outputs to zero and the counter to all 1s
        if(reset) begin
            {less_than, equal_to, greater_than} = 3'b010;
            start = 1'b1;
        end
        else if(start) begin
            #1 {a, b} = {a_in, b_in}; //Input is taken in at the beginning of the operation
            c = {(n+1){1'b1}};
            start = 0; //Once the comparision is started new input will not be taken
        end

        if(equal_to && {|c}) begin //As long as counter is non-zero, it serial input will be taken
            if(reset) {less_than, equal_to, greater_than} = 3'b000;
            else if(a[n]^b[n]) {less_than, equal_to, greater_than} = {b[n], 1'b0, a[n]};
            else {less_than, equal_to, greater_than} = 3'b010;
            
            #1 a = a << 1;
            #1 b = b << 1;
            #1 c = c << 1;
        end
    end
        
endmodule
