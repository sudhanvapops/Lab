// Design Verilog  HDL  to  implement  Binary  Adder-Subtractor  –  Half  and  Full 
// Adder,  Half  and  Full Subtractor.

module fulladder(A, B, C, sum, cout);
    input A, B, C;
    output sum, cout;

    assign sum  = A ^ B ^ C;
    assign cout = (A & B) | (B & C) | (C & A);
endmodule

module fulladder_tb();
    reg A, B, C;
    wire sum, cout;

    fulladder FA(.A(A), .B(B), .C(C), .sum(sum), .cout(cout));

    initial begin
        $monitor("Time = %0t | A = %b | B = %b | C = %b | Sum = %b | Cout = %b",
                  $time, A, B, C, sum, cout);

        A = 0; B = 0; C = 0; #10;
        A = 0; B = 0; C = 1; #10;
        A = 0; B = 1; C = 0; #10;
        A = 0; B = 1; C = 1; #10;
        A = 1; B = 0; C = 0; #10;
        A = 1; B = 0; C = 1; #10;
        A = 1; B = 1; C = 0; #10;
        A = 1; B = 1; C = 1; #10;

        #10 $finish;
    end
endmodule
