module decimal_adder(a, b, cin, sum, carry);
    input  [3:0] a, b;
    input        cin;
    output [3:0] sum;
    output       carry;

    reg    [4:0] s;        // Temporary 5-bit sum register
    reg          c;        // Carry register

    assign sum = s[3:0];
    assign carry = c;

    always @(*) begin
        s = a + b + cin;       // Binary addition

        if (s > 9) begin       // Check for BCD correction
            s = s + 6;         // Add 6 to convert to valid BCD
            c = 1;
        end else begin
            c = 0;
        end
    end
endmodule

module decimal_adder_TB();

    reg  [3:0] a, b;
    reg        cin;
    wire [3:0] sum;
    wire       carry;

    decimal_adder DA(.a(a), .b(b), .cin(cin), .sum(sum), .carry(carry));

    initial begin
        $monitor("Time=%0t  a=%d  b=%d  cin=%b  |  sum=%d  carry=%b", 
                  $time, a, b, cin, sum, carry);

        a=0; b=0; cin=0; #10;
        a=6; b=9; cin=0; #10;
        a=3; b=3; cin=0; #10;
        a=4; b=5; cin=0; #10;
        a=8; b=2; cin=0; #10;
        a=9; b=9; cin=0; #10;

        $finish;
    end
endmodule

