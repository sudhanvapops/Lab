module halfadder(A, B, sum, carry);
    input A, B;
    output sum, carry;

    assign sum = A ^ B;
    assign carry = A & B;
endmodule

module halfadder_tb();
    reg A, B;
    wire sum, carry;

    halfadder HA(.A(A), .B(B), .sum(sum), .carry(carry));

    initial begin
        $monitor("Time = %0t | A = %b | B = %b | Sum = %b | Carry = %b",
                  $time, A, B, sum, carry);

        A = 0; B = 0; #10;
        A = 0; B = 1; #10;
        A = 1; B = 0; #10;
        A = 1; B = 1; #10;

        #10 $finish;
    end
endmodule
