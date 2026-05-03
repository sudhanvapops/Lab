-- Active: 1774368305703@@127.0.0.1@3306@lab

-- LAB Program 3

-- MYSQL Quiery Queries using aggregate functions(COUNT,AVG,MIN,MAX,SUM),Group by,Orderby. 
-- Employee(E_id, E_name, Age, Salary) 
-- 1. Create Employee table containing all Records E_id, E_name, Age, Salary. 
-- 2. Count number of employee names from employeetable 
-- 3. Find the Maximum age from employee table. 
-- 4. Find the Minimum age from employeetable. 
-- 5. Find salaries of employee in Ascending Order. 6. Find grouped salaries of employees.


-- 1. Create Employee table containing all Records E_id, E_name, Age, Salary.
CREATE TABLE Employee3 (
    E_id INT PRIMARY KEY,
    E_name VARCHAR(50),
    Age INT,
    Salary DECIMAL(10,2)
);


-- Insert sample data to test queries
INSERT INTO Employee3 VALUES
(1, 'Amit', 25, 30000),
(2, 'Ravi', 30, 40000),
(3, 'Sneha', 28, 35000),
(4, 'Kiran', 35, 50000),
(5, 'Akash', 35, 50000);


SELECT * FROM Employee3;

-- 2. Count number of employee names from Employee table
SELECT COUNT(E_name) AS Total_Employees
FROM Employee3;
-- Ouput: 5


-- 3. Find Maximum Age
SELECT MAX(Age) AS Max_Age
FROM Employee3;
-- Output: 35


-- 3. Find Maximum Age
SELECT MIN(Age) AS Max_Age
FROM Employee3;
-- Output 25


-- 5. Salaries in Ascending Order
SELECT E_name, Salary
FROM Employee3
ORDER BY Salary ASC;


-- 6. Grouped Salaries of Employees
-- grouping → by salary
SELECT Salary, COUNT(*) AS Num_Employees
FROM Employee3
GROUP BY Salary;