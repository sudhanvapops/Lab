// 4:1 Demultiplexer
module Demux4to1(I, S0, S1, Y0, Y1, Y2, Y3);
    input I, S0, S1;
    output Y0, Y1, Y2, Y3;

    assign Y0 = (~S0) & (~S1) & I;
    assign Y1 = (~S0) & ( S1) & I;
    assign Y2 = ( S0) & (~S1) & I;
    assign Y3 = ( S0) & ( S1) & I;
endmodule


module Demux4to1_TB();
    reg I, S0, S1;
    wire Y0, Y1, Y2, Y3;

    Demux4to1 DEMUX(I, S0, S1, Y0, Y1, Y2, Y3);

    initial begin
        $dumpfile("demux.vcd");     // output waveform file
        $dumpvars(0, Demux4to1_TB); // dump all signals in testbench

        $monitor("Time=%0t  S1=%b S0=%b  I=%b  |  Y0=%b Y1=%b Y2=%b Y3=%b",
                  $time, S1, S0, I, Y0, Y1, Y2, Y3);

        S0 = 0; S1 = 0; I = 1; #10;
        S0 = 0; S1 = 1; I = 1; #10;
        S0 = 1; S1 = 0; I = 1; #10;
        S0 = 1; S1 = 1; I = 1; #10;

        $finish;
    end
endmodule

