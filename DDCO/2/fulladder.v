// 4-bit Full Adder Module
module fulladder_4bit (
    input  [3:0] A, B,
    input        Cin,
    output [3:0] Sum,
    output       Cout
);
    assign {Cout, Sum} = A + B + Cin;
endmodule

// Testbench
module TB_FA();
    reg  [3:0] a, b;
    reg        cin;
    wire [3:0] sum;
    wire       cout;

    fulladder_4bit fl (
        .A(a),
        .B(b),
        .Cin(cin),
        .Sum(sum),
        .Cout(cout)
    );

    initial begin
        $dumpfile("fa.vcd");
        $dumpvars(0, TB_FA);
        a = 4'b0000; b = 4'b0001; cin = 1'b0; #10;
        a = 4'b0011; b = 4'b0011; cin = 1'b0; #10;
        a = 4'b1111; b = 4'b1011; cin = 1'b0; #10;
        a = 4'b0011; b = 4'b0001; cin = 1'b0; #10;
    end
endmodule
