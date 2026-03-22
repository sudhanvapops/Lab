// 3. Implement a java program to illustrate storing user defined classes in collection.

import java.util.*;

class Student {
    int id;
    String name;

    Student(int id, String name) {
        this.id = id;
        this.name = name;
    }
}

public class Demo {
    public static void main(String[] args) {

        ArrayList<Student> list = new ArrayList<>();

        Student s1 = new Student(1, "Deepak");
        Student s2 = new Student(2, "Rahul");

        list.add(s1);
        list.add(s2);

        for (Student s : list) {
            System.out.println(s.id + " " + s.name);
        }
    }
}
