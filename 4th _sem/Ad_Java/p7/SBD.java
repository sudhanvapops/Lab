// 7. Implement a java program to Demonstrate a swing event handling application that creates 2 buttons Alpha and Beta and displays the text “Alpha pressed” when alpha button is clicked and “Beta pressed” when beta button is clicked.

import javax.swing.*;

public class SBD {

    public SBD() {
        // Create frame
        JFrame f = new JFrame("Button Demo");
        f.setSize(300, 200);
        f.setLayout(null);

        // Create buttons
        JButton b1 = new JButton("Alpha");
        JButton b2 = new JButton("Beta");

        // Set positions
        b1.setBounds(50, 50, 80, 30);
        b2.setBounds(150, 50, 80, 30);

        // Create label
        JLabel l = new JLabel();
        l.setBounds(80, 100, 150, 30);

        // Add action for Alpha button
        b1.addActionListener(e -> l.setText("Alpha pressed"));
        b2.addActionListener(e -> l.setText("Beta pressed"));

        // Add components to frame
        f.add(b1);
        f.add(b2);
        f.add(l);

        // Frame settings
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        new SBD();
    }
}