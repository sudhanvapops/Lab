// A program to design the Login page and validating the USER_ID and PASSWORD using JSP and
// DataBase.

package com.sudhanva;

import java.io.IOException;
import java.sql.*;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/login")
public class LoginServlet extends HttpServlet {

    private static final String URL = "jdbc:mysql://localhost:3306/login_db";

    private static final String USER = "root";
    private static final String PASSWORD = "P@SSW0RD";

    @Override
    protected void doPost(
            HttpServletRequest request,
            HttpServletResponse response)
            throws ServletException, IOException {

        String userid = request.getParameter("userid");

        String password = request.getParameter("password");

        try {

            Class.forName("com.mysql.cj.jdbc.Driver");

            Connection con = DriverManager.getConnection(
                    URL,
                    USER,
                    PASSWORD);

            PreparedStatement ps = con.prepareStatement(
                    "SELECT * FROM users WHERE user_id=? AND password=?");

            ps.setString(1, userid);
            ps.setString(2, password);

            ResultSet rs = ps.executeQuery();

            if (rs.next()) {
                request.setAttribute("user", userid);
                request.getRequestDispatcher("success.jsp")
               .forward(request, response);
            } else {
                response.sendRedirect("error.jsp");
            }

            con.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}