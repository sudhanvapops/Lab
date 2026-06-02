package com.sudhanva;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/cookie")
public class CookieServlet extends HttpServlet {

    protected void doGet(HttpServletRequest request,
                         HttpServletResponse response)
            throws ServletException, IOException {

        Cookie cookie = new Cookie("EMPID", "AN2356");
        cookie.setMaxAge(60 * 60);
        response.addCookie(cookie);
        System.out.println("Servlet Executed");


        String empid = "Cookie Not Found";

        Cookie[] cookies = request.getCookies();

        if (cookies != null) {
            for (Cookie c : cookies) {
                if ("EMPID".equals(c.getName())) {
                    empid = c.getValue();
                    break;
                }
            }
        }

        request.setAttribute("empid", empid);
        request.getRequestDispatcher("cookie.jsp")
               .forward(request, response);
    }
}