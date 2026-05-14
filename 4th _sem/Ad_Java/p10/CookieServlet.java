import java.io.IOException;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/CookieServlet")
public class CookieServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request,
                         HttpServletResponse response)
            throws ServletException, IOException {

        // Create cookie
        Cookie cookie = new Cookie("EMPID", "AN2356");

        // Set expiry time (1 hour)
        cookie.setMaxAge(60 * 60);

        // Add cookie
        response.addCookie(cookie);

        // Read cookie
        String empid = "Cookie Not Found";

        Cookie[] cookies = request.getCookies();

        if (cookies != null) {
            for (Cookie c : cookies) {
                if (c.getName().equals("EMPID")) {
                    empid = c.getValue();
                }
            }
        }

        // Send value to JSP
        request.setAttribute("empid", empid);

        // Forward to JSP page
        request.getRequestDispatcher("cookie.jsp")
               .forward(request, response);
    }
}


<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Cookie Example</title>
</head>
<body>

    <h2>Cookie Created Successfully</h2>

    <p>
        Cookie Name : EMPID
    </p>

    <p>
        Cookie Value : AN2356
    </p>

    <hr>

    <h3>Reading Cookie</h3>

    <p>
        Employee ID from Cookie :
        <%= request.getAttribute("empid") %>
    </p>

</body>
</html>


http://localhost:8080/YourProjectName/CookieServlet