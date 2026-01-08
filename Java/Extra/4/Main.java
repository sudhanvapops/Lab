class Main extends Thread {

    public void run() {
        System.out.println("Thread is running");
    }

    public static void main(String[] args) throws Exception {

        Main t = new Main();

        System.out.println("Before start: " + t.isAlive());

        t.start();

        System.out.println("After start: " + t.isAlive());

        t.join();   // main thread waits

        System.out.println("After completion: " + t.isAlive());
    }
}
