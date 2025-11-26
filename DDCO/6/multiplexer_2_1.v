// 2:1 Multiplexer
module Mux2to1(I0, I1, S, Out);
    input I0, I1, S;
    output reg Out;

    always @(*) begin
        case(S)
            1'b0: Out = I0;
            1'b1: Out = I1;
        endcase
    end
endmodule

module Mux2to1_TB();
    reg I0, I1, S;
    wire Out;

    Mux2to1 MX(.I0(I0), .I1(I1), .S(S), .Out(Out));

    initial begin
        $monitor("Time=%0t  S=%b  I0=%b  I1=%b  Out=%b", $time, S, I0, I1, Out);

        S=0; I0=1; I1=0; #10;
        S=1; I0=0; I1=1; #10;

        $finish;
    end
endmodule
