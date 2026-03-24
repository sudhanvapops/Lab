-- Active: 1774368305703@@127.0.0.1@3306@lab
-- 1 Create a table called Employee & execute the following.
-- Employee(EMPNO,ENAME,JOB, MANAGER_NO, SAL, COMMISSION)
-- 1. Create a user and grant all permissions to theuser.
-- 2. Insert the any three records in the employee table contains attributes
-- EMPNO,ENAME JOB, MANAGER_NO, SAL, COMMISSION and use rollback.
-- Check the result.
-- 3. Add primary key constraint and not null constraint to the employee table.
-- 4. Insert null values to the employee table and verify the result

CREATE TABLE Employee (
    EMPNO INT,
    ENAME VARCHAR(50),
    JOB VARCHAR(50),
    MANAGER_NO INT,
    SAL DECIMAL(10,2),
    COMMISSION DECIMAL(10,2)
);

-- Create User & Grant Permissions
CREATE USER 'emp_user' IDENTIFIED BY 'password123';

-- *.* = all databases + all tables
GRANT ALL PRIVILEGES ON *.* TO 'emp_user';


-- Insert Records + Roll Back

START TRANSACTION;
INSERT INTO Employee VALUES (101, 'John', 'Manager', 100, 50000, 5000);
INSERT INTO Employee VALUES (102, 'Alice', 'Developer', 101, 40000, 2000);
INSERT INTO Employee VALUES (103, 'Bob', 'Tester', 101, 30000, 1000);

SELECT * FROM Employee;

ROLLBACK;

SELECT * FROM Employee;

-- ADD CONSTRAINTS
ALTER TABLE Employee
ADD CONSTRAINT emp_pk PRIMARY KEY (EMPNO);

ALTER TABLE Employee
MODIFY ENAME VARCHAR(50) NOT NULL;


-- Insert NULL Values (Test Constraints)
INSERT INTO Employee VALUES (NULL, 'Sam', 'Clerk', 101, 20000, 500);
INSERT INTO Employee VALUES (104, NULL, 'Clerk', 101, 20000, 500);
INSERT INTO Employee VALUES (105, 'David', 'Clerk', NULL, 20000, NULL);


SELECT * FROM Employee;