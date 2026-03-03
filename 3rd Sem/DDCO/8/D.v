// D FLIP-FLOP
module D_FF(Q, D, CLK, RST);
    input D, CLK, RST;
    output reg Q;

    always @(posedge CLK or posedge RST) begin
        if (RST)
            Q <= 0;
        else
            Q <= D;
    end
endmodule


module D_FF_TB();
    reg D, CLK, RST;
    wire Q;

    D_FF DFF(Q, D, CLK, RST);

    // Clock generation
    initial begin
        CLK = 0;
        forever #10 CLK = ~CLK;
    end

    initial begin
        RST = 1; #10; // makes Q = 0 and start from here
        RST = 0; #10;

        D = 0; #20;
        D = 1; #20;
    end
endmodule
