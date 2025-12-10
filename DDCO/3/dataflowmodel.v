// Dataflow Modeling
module dataflow(A, B, C, D, E);
    input A, B, C, D;
    output E;
    assign E = A | (B & C) | (~B & D);
endmodule

module dataflow_tb();
    reg A, B, C, D;
    wire E;

    dataflow EX(.A(A), .B(B), .C(C), .D(D), .E(E));

    initial begin
        $dumpfile("data.vcd");
        $dumpvars(0, dataflow_tb);
        A=0; B=0; C=0; D=0; #10;
        A=0; B=0; C=0; D=1; #10;
        A=0; B=0; C=1; D=0; #10;
        A=0; B=0; C=1; D=1; #10;
        A=0; B=1; C=0; D=0; #10;
        A=0; B=1; C=0; D=1; #10;
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
