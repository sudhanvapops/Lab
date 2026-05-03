-- Active: 1774368305703@@127.0.0.1@3306@lab

-- Program 2

-- Create a table called Employee that contain attributes EMPNO,ENAME,JOB, MGR,SAL &
-- execute the following.
-- 1. Add a column commission with domain to the Employeetable.
-- 2. Insert any five records into the table.
-- 3. Update the column details of job
-- 4. Rename the column of Employ table using alter command.
-- 5. Delete the employee whose Empno is 105.


CREATE TABLE Employee2 (
    EMPNO INT PRIMARY KEY,
    ENAME VARCHAR(50),
    JOB VARCHAR(50),
    MGR INT,
    SAL DECIMAL(10,2)
);

ALTER TABLE Employee2
ADD commission DECIMAL(10,2) CHECK (commission >= 0);

INSERT INTO Employee2 (EMPNO, ENAME, JOB, MGR, SAL, commission) VALUES
(101, 'Ravi', 'Clerk', 201, 20000, 500),
(102, 'Anita', 'Manager', NULL, 50000, 2000),
(103, 'Kiran', 'Analyst', 202, 40000, 1500),
(104, 'Meena', 'Clerk', 201, 22000, 600),
(105, 'Arjun', 'Salesman', 203, 30000, 1000);

INSERT INTO Employee2 (EMPNO, ENAME, JOB, MGR, SAL, commission) VALUES
(106, 'Kumar', 'Salesman', 203, 30000, -20);

UPDATE Employee
SET JOB = 'Senior Clerk'
WHERE JOB = 'Clerk';

ALTER TABLE Employee
RENAME COLUMN ENAME TO EMP_NAME;

DELETE FROM Employee
WHERE EMPNO = 105;


SELECT * FROM employee2