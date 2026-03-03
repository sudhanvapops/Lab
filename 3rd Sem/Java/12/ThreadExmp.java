/*
Exp 12. Develop a program to create a class MyThread in this class a constructor, call the base class constructor, 
using super and start the thread. The run method of the class starts after this. 
It can be observed that both main thread and created child thread are executed concurrently.
*/

class MyThread extends Thread {

    // Constructor
    public MyThread(String threadName) {
        super(threadName);     // Call base class constructor
        start();               // Start the thread
    }

    @Override
    public void run() {
        System.out.println("Thread: " + getName() + " is running.");
        System.out.println("Thread: " + getName() + " is exiting.");
    }
}

public class ThreadExmp {

    public static void main(String[] args) {

        // Print the main thread name
        System.out.println("Thread Name: " + Thread.currentThread().getName());

        // Create a child thread
        new MyThread("Child Thread");

        System.out.println("Main thread exiting.");
    }
}
