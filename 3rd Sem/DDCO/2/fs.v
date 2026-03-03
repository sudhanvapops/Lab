// 4-bit Full Subtractor
module fullsub_4bit (
    input  [3:0] A, B,
    input        Bin,
    output [3:0] Diff,
    output       Bout
);
    assign {Bout, Diff} = A - B - Bin;
endmodule

// Testbench
module TB_FS();
    reg  [3:0] a, b;
    reg        bin;
    wire [3:0] diff;
    wire       bout;

    fullsub_4bit fs (
        .A(a),
        .B(b),
        .Bin(bin),
        .Diff(diff),
        .Bout(bout)
    );

    initial begin
        $dumpfile("fa.vcd");
        $dumpvars(0, TB_FS);
        a = 4'b0000; b = 4'b0001; bin = 1'b0; #10;
        a = 4'b0011; b = 4'b0011; bin = 1'b0; #10;
        a = 4'b1111; b = 4'b1011; bin = 1'b0; #10;
        a = 4'b0011; b = 4'b0001; bin = 1'b0; #10;
    end
    
endmodule
