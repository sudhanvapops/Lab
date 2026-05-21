<%@ page language="java" contentType="text/html;charset=UTF-8" isELIgnored="false" %>
<!DOCTYPE html>
<html>
<head>
    <title>Student Result</title>
</head>
<body>
    <h2>Student Details</h2>

    Name: ${name} <br><br>
    USN: ${usn} <br><br>
    Total Marks: ${total} <br><br>
    Percentage: <%= String.format("%.2f", request.getAttribute("perc")) %><br><br>

    <a href="index.jsp">Go Back</a>


</body>
</html>
