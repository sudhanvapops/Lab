// JK FLIP-FLOP
module JK_FF(J, K, Q, CLK);
    input J, K, CLK;
    output reg Q;

    always @(posedge CLK)
        case ({J, K})
            2'b00: Q <= Q;      // Hold
            2'b01: Q <= 0;      // Reset
            2'b10: Q <= 1;      // Set
            2'b11: Q <= ~Q;     // Toggle
        endcase
endmodule


module JK_FF_TB();
    reg J, K, CLK;
    wire Q;

    JK_FF JK(J, K, Q, CLK);

    // Clock generation
    initial begin
        CLK = 0;
        forever #10 CLK = ~CLK;
    end

    initial begin
        J=0; K=0; #20;
        J=0; K=1; #20;
        J=1; K=0; #20;
        J=1; K=1; #20;
    end
endmodule
