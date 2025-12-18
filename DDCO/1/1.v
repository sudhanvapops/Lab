// Given a 4-variable  logic  expression,  simplify it  using  appropriate 
// technique  and simulate  the  same using basic gates. 

module expression(B,C,D,E); 
    input B,C,D; 
    output E; 
    wire W1,W2,W3; 
    not(W1,B); 
    not(W2,C);
    and(W3,W1,W2); 
    or(E,D,W3); 
    // assign E = D | (~B & ~C);
endmodule  

module expression_tb(); 
    // Inputs must be reg 
    // output must be wire
    reg B,C,D; 
    wire E; 

    // This means anytime B, C, or D change, your expression module reacts.
    expression  EX(.B(B),.C(C),.D(D),.E(E)); 

    initial begin   
        B=0; C=0; D=0; #10; 
        B=0; C=0; D=1; #10; 
        B=0; C=1; D=0; #10; 
        B=0; C=1; D=1; #10; 
        B=1; C=0; D=0; #10; 
        B=1; C=0; D=1; #10; 
        B=1; C=1; D=0; #10; 
        B=1; C=1; D=1; #10; 
    end 
endmodule