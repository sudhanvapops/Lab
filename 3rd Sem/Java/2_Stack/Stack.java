import java.util.Scanner;

public class Stack {

    private int top;
    private int maxSize;
    private int[] stack;

    Stack(int maxSize){
        this.maxSize = maxSize;
        this.top = -1;
        this.stack = new int[this.maxSize]; 
    }

    public void push(Scanner sc){

        if (this.top == this.maxSize-1){
            System.out.println("Stack OverFlow\n");
            return;
        }

        System.out.print("Enter The Value to Push: ");
        int value = sc.nextInt();
        stack[++this.top] = value;
        System.out.println(value+" pushed to stack\n");

    }

    public void pop(){
        if(this.top == -1){
            System.out.println("Stack UnderFlow\n");
            return;
        }
        System.out.println(stack[this.top--]+" Poped\n");
        return;
    }

    public void display(){

        if(this.top == -1){
            System.out.println("Stack is Empty");
            return;
        }

        for(int i = 0; i<=this.top; i++){
            System.out.print(stack[i]+" ");
        }
        System.out.println("\n");

    }

    public void peek(){
        if (this.top == -1){
            System.out.println("Stack UnderFlow ");
            return;
        }

        System.out.println(stack[this.top]+" Top Element");
        return;
    }
    
}
