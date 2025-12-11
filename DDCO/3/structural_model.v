// Design Verilog HDL to implement simple circuits using structural, Data 
// flow and Behavioural model.

// Structural Modeling
module structural(A, B, C, D, E);
    input A, B, C, D;
    output E;
    wire W1, W2, W3, W4;

    and(W1, B, C);      // BC
    not(W2, B);         // B'
    and(W3, W2, D);     // B'D
    or(W4, W1, W3);     // BC + B'D
    or(E, A, W4);       // A + BC + B'D

endmodule

module structural_tb();
    reg A, B, C, D;
    wire E;

    structural EX(.A(A), .B(B), .C(C), .D(D), .E(E));

    initial begin
        A=0; B=0; C=0; D=0; #10;
        B=1; C=0; D=1; #10;
        A=0; B=1; C=1; D=0; #10;
        A=0; B=1; C=1; D=1; #10;
        A=1; B=0; C=0; D=0; #10;
        A=1; B=0; C=0; D=1; #10;
        A=1; B=0; C=1; D=0; #10;
        A=1; B=0; C=1; D=1; #10;
        A=1; B=1; C=0; D=0; #10;
        A=1; B=1; C=0; D=1; #10;
        A=1; B=1; C=1; D=0; #10;
        A=1; B=1; C=1; D=1; #10;
    end
endmodule
