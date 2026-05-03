1. Database Basics
CREATE DATABASE mydb;
USE mydb;

SHOW DATABASES;
DROP DATABASE mydb;



2. Table Operations
CREATE TABLE Employee (
id INT PRIMARY KEY,
name VARCHAR(50),
salary DECIMAL(10,2)
);

SHOW TABLES;
DESC Employee;

DROP TABLE Employee;



3. ALTER (Modify Table)
ALTER TABLE Employee ADD age INT;
ALTER TABLE Employee MODIFY salary INT;
ALTER TABLE Employee RENAME COLUMN name TO emp\_name;
ALTER TABLE Employee DROP COLUMN age;



1. Insert Data
INSERT INTO Employee VALUES (1, 'Ravi', 20000);
INSERT INTO Employee (id, name) VALUES (2, 'Anita');



1. SELECT (Core of SQL)
SELECT \* FROM Employee;
SELECT name, salary FROM Employee;

SELECT \* FROM Employee WHERE salary > 20000;
SELECT \* FROM Employee WHERE name LIKE 'A%';

SELECT \* FROM Employee ORDER BY salary DESC;
SELECT \* FROM Employee LIMIT 3;



6. UPDATE \& DELETE
UPDATE Employee
SET salary = 30000
WHERE id = 1;

DELETE FROM Employee
WHERE id = 2;



7. Aggregate Functions
SELECT COUNT(\*) FROM Employee;
SELECT AVG(salary) FROM Employee;
SELECT MAX(salary), MIN(salary) FROM Employee;



1. GROUP BY \& HAVING
SELECT job, COUNT(\*)
FROM Employee
GROUP BY job;

SELECT job, AVG(salary)
FROM Employee
GROUP BY job
HAVING AVG(salary) > 25000;



9. JOINS
-- INNER JOIN
SELECT e.name, d.dept\_name
FROM Employee e
INNER JOIN Department d
ON e.dept\_id = d.id;

\-- LEFT JOIN
SELECT \* FROM Employee e
LEFT JOIN Department d
ON e.dept\_id = d.id;



10. Constraints
id INT PRIMARY KEY
email VARCHAR(100) UNIQUE
salary INT NOT NULL
age INT CHECK (age >= 18)
dept\_id INT FOREIGN KEY REFERENCES Department(id)



1. Useful Shortcuts
SELECT DISTINCT job FROM Employee;
SELECT \* FROM Employee WHERE salary BETWEEN 20000 AND 40000;
SELECT \* FROM Employee WHERE id IN (1,2,3);

\-- Alias
SELECT name AS EmployeeName FROM Employee;

