`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module Serialized_Comparator_tb();
    
    //Set the parameter 'width' for determining the data width
    parameter width = 4;
    
    parameter n = width - 1;
    
    reg clk=0, reset=0;
    reg [n:0] a, b;
    wire less_than, equal_to, greater_than;
    
    Multi_Bit_Comparator_Serialized #(n) compare (
    .clk(clk),
    .reset(reset),
    .a_in(a), .b_in(b),
    .less_than(less_than),
    .equal_to(equal_to), 
    .greater_than(greater_than)
    );
    
    always #10 clk = ~clk;
    
    initial begin
        //The reset signal needs to be made 1 then 0 after the duration of at least 1 clock cycle
        #1  reset = 1;        
        #10  reset = 0;        
        a = 4'ha; 
        b = 4'hb;
        //The circuit nees to be reset before each change in input
        #100  reset = 1;        
        #10  reset = 0;        
        a = 4'h8; 
        b = 4'h8;
     end
    
endmodule
