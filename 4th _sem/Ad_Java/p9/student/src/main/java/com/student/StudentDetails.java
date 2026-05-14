// A servlet program to display the name, USN, and total marks by accepting student detail

package com.student;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/details")
public class StudentDetails extends HttpServlet{
    
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        
        String name = req.getParameter("name");
        String usn = req.getParameter("usn");

        int m1 = Integer.parseInt(req.getParameter("m1"));
        int m2 = Integer.parseInt(req.getParameter("m2"));
        int m3 = Integer.parseInt(req.getParameter("m3"));

        int total = m1 + m2 + m3;

        int perc = (total / 300)*100;

        // Store data in request scope
        req.setAttribute("name", name);
        req.setAttribute("usn", usn);
        req.setAttribute("total", total);
        req.setAttribute("perc", perc);

        // Forward to JSP page
        req.getRequestDispatcher("result.jsp").forward(req, resp);
    }
}
