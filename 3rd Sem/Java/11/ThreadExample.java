/*
11. Write a program to illustrate creation of threads using runnable class. 
(start method start each of the newly created thread. Inside the run method there is sleep() for suspend the thread for 500 milliseconds).
*/

class MyRunnable implements Runnable {

    Thread t;

    MyRunnable(String name) {
        t = new Thread(this, name);
        t.start();
    }

    @Override
    public void run() {
        try {
            System.out.println("Thread: " + t.getName() + " is running.");
            Thread.sleep(500);
            System.out.println("Thread: " + t.getName() + " has completed.");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class ThreadExample {
    public static void main(String[] args) {
        new MyRunnable("First Child");
        new MyRunnable("Second Child");

        System.out.println("Main thread exiting.");
    }
}
