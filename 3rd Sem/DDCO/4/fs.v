module fullsubtractor(A, B, C, diff, bout);
    input A, B, C;
    output diff, bout;

    assign diff = A ^ B ^ C;
    assign bout = (~A & B) | (B & C) | (~A & C);
endmodule


module fullsubtractor_tb();
    reg A, B, C;
    wire diff, bout;

    fullsubtractor FS(.A(A), .B(B), .C(C), .diff(diff), .bout(bout));

    initial begin
        $monitor("Time = %0t | A = %b | B = %b | C = %b | Diff = %b | Bout = %b",
                  $time, A, B, C, diff, bout);

        A = 0; B = 0; C = 0; #10;
        A = 0; B = 0; C = 1; #10;
        A = 0; B = 1; C = 0; #10;
        A = 0; B = 1; C = 1; #10;
        A = 1; B = 0; C = 0; #10;
        A = 1; B = 0; C = 1; #10;
        A = 1; B = 1; C = 0; #10;
        A = 1; B = 1; C = 1; #10;

        #10 $finish;
    end
endmodule
