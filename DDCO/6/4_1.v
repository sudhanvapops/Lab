// 4:1 Multiplexer
module Mux4to1(d0, d1, d2, d3, Sel, Out);
    input d0, d1, d2, d3;
    input [1:0] Sel;
    output reg Out;

    always @(*) begin
        case(Sel)
            2'b00: Out = d0;
            2'b01: Out = d1;
            2'b10: Out = d2;
            2'b11: Out = d3;
        endcase
    end
endmodule

module Mux4to1_TB();
    reg d0, d1, d2, d3;
    reg [1:0] Sel;
    wire Out;

    Mux4to1 MUX(.d0(d0), .d1(d1), .d2(d2), .d3(d3), .Sel(Sel), .Out(Out));

    initial begin
        $monitor("Time=%0t  Sel=%b  Out=%b", $time, Sel, Out);

        d0=1; d1=0; d2=0; d3=0; Sel=2'b00; #10;
        d0=0; d1=1; d2=0; d3=0; Sel=2'b01; #10;
        d0=0; d1=0; d2=1; d3=0; Sel=2'b10; #10;
        d0=0; d1=0; d2=0; d3=1; Sel=2'b11; #10;

        $finish;
    end
endmodule
