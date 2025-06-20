`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module Serialized_Comparator #(parameter n=7) (    
    input clock, reset,
    input [n:0] a_in, b_in,
    
    output reg less_than, equal_to, greater_than,
    output solved
    );
    
    //These registers are created to enable serialization
    reg [n:0] a, b, c;
    
    //The start register notes when the comparision process is going on
    reg start=1;
    
    //A register to save equality of intermediate bits until all bits of the number are checked 
    reg equal_bit=1;
    
    //A control signal to indicate that the operation is complete
    assign solved = (less_than | greater_than | equal_to);

    //A control signal to indicate whether counter is zero or not
    wire counter = |c;

    always @ (posedge clock) begin
        //Resetting the various components of the counter
        if(reset) begin
            //Reset all output values to zero
            {less_than, equal_to, greater_than} = 3'b000;

            //Reset start value to one, so the module can take inputs in the next clock cycle
            start = 1'b1;

            //Reset the intermediate equality bit to one, to continue operations
            equal_bit = 1'b1;

            //Reset counter to all-ones, indicating all bits of the input are to be checked
            c = {(n+1){1'b1}};
        end
        //Starting the operation by taking the input
        else if(start) begin
            {a, b} = {a_in, b_in}; //Input is taken in at the beginning of the operation
            start = 0; //Once the comparision is started new input will not be taken
        end
        //Proceeding to the comparison operation
        else begin
            //As long as previous bits were equal and counter is non-zero, serial input will be taken
            if(equal_bit && counter) begin
                if(a[n]^b[n]) {less_than, equal_bit, greater_than} = {b[n], 1'b0, a[n]};
                else {less_than, equal_bit, greater_than} = 3'b010;
                
                a = a << 1;
                b = b << 1;
                c = c << 1;
            end
            else
                equal_to = ~(less_than | greater_than | counter);
        end
    end
        
endmodule
