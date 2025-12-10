// 8:1 Multiplexer
module Mux8to1(d0,d1,d2,d3,d4,d5,d6,d7,Sel,Out);
    input d0,d1,d2,d3,d4,d5,d6,d7;
    input [2:0] Sel;
    output reg Out;

    always @(*) begin
        case(Sel)
            3'b000: Out = d0;
            3'b001: Out = d1;
            3'b010: Out = d2;
            3'b011: Out = d3;
            3'b100: Out = d4;
            3'b101: Out = d5;
            3'b110: Out = d6;
            3'b111: Out = d7;
        endcase
    end
endmodule

module Mux8to1_TB();
    reg d0,d1,d2,d3,d4,d5,d6,d7;
    reg [2:0] Sel;
    wire Out;

    Mux8to1 MUX(.d0(d0), .d1(d1), .d2(d2), .d3(d3), .d4(d4), .d5(d5), .d6(d6), .d7(d7), .Sel(Sel), .Out(Out));

    initial begin
        $monitor("Time=%0t Sel=%b Out=%b", $time, Sel, Out);

        d0=1; d1=0; d2=0; d3=0; d4=0; d5=0; d6=0; d7=0; Sel=3'b000; #10;
        d0=0; d1=1; d2=0; d3=0; d4=0; d5=0; d6=0; d7=0; Sel=3'b001; #10;
        d0=0; d1=0; d2=1; d3=0; d4=0; d5=0; d6=0; d7=0; Sel=3'b010; #10;
        d0=0; d1=0; d2=0; d3=1; d4=0; d5=0; d6=0; d7=0; Sel=3'b011; #10;
        d0=0; d1=0; d2=0; d3=0; d4=1; d5=0; d6=0; d7=0; Sel=3'b100; #10;
        d0=0; d1=0; d2=0; d3=0; d4=0; d5=1; d6=0; d7=0; Sel=3'b101; #10;
        d0=0; d1=0; d2=0; d3=0; d4=0; d5=0; d6=1; d7=0; Sel=3'b110; #10;
        d0=0; d1=0; d2=0; d3=0; d4=0; d5=0; d6=0; d7=1; Sel=3'b111; #10;

        $finish;
    end
endmodule
