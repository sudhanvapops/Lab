// Write a JAVA Program to insert data into Student DATA BASE and retrieve info based on particular queries(For example update, delete, search etc…).

package com.sudhanva;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Studentdatabase {

    private static void display(ResultSet rs) throws Exception {

        while (rs.next()) {

            System.out.println(
                    rs.getInt("usn") + "\t" +
                    rs.getString("name") + "\t" +
                    rs.getInt("marks"));
        }
    }

    public static void main(String[] args) {

        try {

            Class.forName("com.mysql.cj.jdbc.Driver");

            Connection con = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/studentdb",
                    "root",
                    "P@SSW0RD");

            Statement st = con.createStatement();

            // Create Table
            st.executeUpdate(
                    "CREATE TABLE IF NOT EXISTS student(" +
                            "usn INT PRIMARY KEY," +
                            "name VARCHAR(30)," +
                            "marks INT)");

            System.out.println("Table Created");

            // Insert Records
            st.executeUpdate(
                    "INSERT IGNORE INTO student VALUES " +
                            "(1,'Ram',80), " +
                            "(2,'Sam',90)");

            System.out.println("Records Inserted");

            // Display Records
            System.out.println("\nStudent Records");
            display( st.executeQuery("SELECT * FROM student"));

            // Update Record
            st.executeUpdate(
                    "UPDATE student SET marks=95 WHERE usn=1");

            System.out.println("\nRecord Updated");

            // Search Record
            System.out.println("\nSearch Result");

            display( st.executeQuery("SELECT * FROM student WHERE usn=1"));

            // Delete Record
            st.executeUpdate( "DELETE FROM student WHERE usn=2");

            System.out.println("\nRecord Deleted");

            // Display Final Records
            System.out.println("\nFinal Records");
            display( st.executeQuery("SELECT * FROM student"));


            con.close();

        } catch (Exception e) {

            System.out.println(e);
        }
    }
}