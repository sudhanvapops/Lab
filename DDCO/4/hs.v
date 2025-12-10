module halfsubtractor(A, B, diff, borrow);
    input A, B;
    output diff, borrow;

    assign diff = A ^ B;
    assign borrow = ~A & B;
endmodule


module halfsubtractor_tb();
    reg A, B;
    wire diff, borrow;

    halfsubtractor HS(.A(A), .B(B), .diff(diff), .borrow(borrow));

    initial begin
        $monitor("Time = %0t | A = %b | B = %b | Diff = %b | Borrow = %b",
                  $time, A, B, diff, borrow);

        A = 0; B = 0; #10;
        A = 0; B = 1; #10;
        A = 1; B = 0; #10;
        A = 1; B = 1; #10;

        #10 $finish;
    end
endmodule
