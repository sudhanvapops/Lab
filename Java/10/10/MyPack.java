/*
Exp 10. Develop a JAVA program to create a package named mypack and import & implement it
in a suitable class.
*/

import Mypackage.MyClass;

public class MyPack {

    public static void main(String[] args) {

        // Create an instance of MyClass from the mypack package
        MyClass myObject = new MyClass();
        // Call the display Message method from MyClass
        myObject.displayMessage();

    }
}