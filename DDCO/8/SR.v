// SR FLIP-FLOP
module SR_FF(S, R, CLK, Q, Qbar);
    input S, R, CLK;
    output Q, Qbar;

    wire s1, r1;

    nand n1(s1, S, CLK);
    nand n2(r1, R, CLK);
    nand n3(Q,  s1, Qbar);
    nand n4(Qbar, r1, Q);
endmodule

module SR_FF_TB();
    reg S, R, CLK;
    wire Q, Qbar;

    SR_FF SR(S, R, CLK, Q, Qbar);

    initial begin
        $monitor("S=%b, R=%b, CLK=%b, Q=%b, Qbar=%b",
                  S, R, CLK, Q, Qbar);

        S=1; R=0; CLK=1; #10;
        S=0; R=0; CLK=1; #10;
        S=0; R=1; CLK=1; #10;
        S=1; R=1; CLK=1; #10;
    end
endmodule


