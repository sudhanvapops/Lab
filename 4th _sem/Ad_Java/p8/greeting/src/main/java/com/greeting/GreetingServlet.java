// 8. A program to display greeting message on the browser “Hello UserName”, “How Are You?”, accept  username from the client using servlet.

package com.greeting;


import java.io.IOException;
// Print Writter used to send HTML output
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;


@WebServlet("/greet")
public class GreetingServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        response.setContentType("text/html;charset=UTF-8");

        // Used to write HTML back to the browser
        PrintWriter out = response.getWriter();

        String name = request.getParameter("username");

        if (name == null || name.trim().isEmpty()) {
            name = "Guest";
        }

        out.println("<!DOCTYPE html>"+"\n<html>"+"\n<head><title>Greeting</title></head>"+"\n<body>"+"\n<h2>Hello " + name + ", How Are You?</h2>"+"\n</body>"+"\n</html>");

        out.close();
    }
}