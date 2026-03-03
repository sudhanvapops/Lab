/*
Exp 10. Develop a JAVA program to create a package named mypack and import & implement it
in a suitable class.
*/

import Mypackage.MyClass;

public class MyPack {
    public static void main(String[] args) {
        MyClass myObject = new MyClass();
        myObject.displayMessage();
    }
}