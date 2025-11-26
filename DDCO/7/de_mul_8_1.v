// 8:1 Demultiplexer
module Demux8to1(I, S0, S1, S2, Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7);
    input I, S0, S1, S2;
    output Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7;

    assign Y0 = (~S0) & (~S1) & (~S2) & I;
    assign Y1 = (~S0) & (~S1) & ( S2) & I;
    assign Y2 = (~S0) & ( S1) & (~S2) & I;
    assign Y3 = (~S0) & ( S1) & ( S2) & I;
    assign Y4 = ( S0) & (~S1) & (~S2) & I;
    assign Y5 = ( S0) & (~S1) & ( S2) & I;
    assign Y6 = ( S0) & ( S1) & (~S2) & I;
    assign Y7 = ( S0) & ( S1) & ( S2) & I;

endmodule


module Demux8to1_TB();
    reg I, S0, S1, S2;
    wire Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7;

    Demux8to1 DEMUX(I, S0, S1, S2, 
                    Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7);

    initial begin
        $monitor("Time=%0t  S2=%b S1=%b S0=%b  I=%b  |  Y0=%b Y1=%b Y2=%b Y3=%b Y4=%b Y5=%b Y6=%b Y7=%b",
                  $time, S2, S1, S0, I,
                  Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7);

        S0=0; S1=0; S2=0; I=1; #10;
        S0=0; S1=0; S2=1; I=1; #10;
        S0=0; S1=1; S2=0; I=1; #10;
        S0=0; S1=1; S2=1; I=1; #10;
        S0=1; S1=0; S2=0; I=1; #10;
        S0=1; S1=0; S2=1; I=1; #10;
        S0=1; S1=1; S2=0; I=1; #10;
        S0=1; S1=1; S2=1; I=1; #10;

        $finish;
    end
endmodule
