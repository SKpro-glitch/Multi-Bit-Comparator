module Single_Bit_Comparator_PowerGated (
    input enable, reset,
    input a, b,
    
    output reg less_than, equal_to, greater_than    
    );
    
    //This is a combinational circuit
    //The enable line assists in power gating as this module will be duplicated in the top module
    
    always @ (enable | reset) begin
        #2;
        if(reset) {less_than, equal_to, greater_than} = 3'b000;
        else if(a^b) {less_than, equal_to, greater_than} = {a, 1'b0, b};
        else {less_than, equal_to, greater_than} = 3'b010;
    end
    
endmodule
