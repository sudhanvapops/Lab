<%@ page language="java" contentType="text/html;charset=UTF-8" isELIgnored="false" %>
<!DOCTYPE html>
<html>
<head>
    <title>Student Form</title>
</head>
<body>

    <h2>Enter Student Details</h2>

    <form action="details" method="post">
        Name: <input type="text" name="name"><br><br>
        USN: <input type="text" name="usn"><br><br>

        Marks 1: <input type="number" name="m1"><br><br>
        Marks 2: <input type="number" name="m2"><br><br>
        Marks 3: <input type="number" name="m3"><br><br>

        <input type="submit" value="Submit">
    </form>

</body>
</html>