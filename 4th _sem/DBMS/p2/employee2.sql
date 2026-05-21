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

UPDATE Employee2
SET JOB = 'Senior Clerk'
WHERE JOB = 'Clerk';

ALTER TABLE Employee2
RENAME COLUMN ENAME TO EMP_NAME;

DELETE FROM Employee2
WHERE EMPNO = 105;


SELECT * FROM employee2




-- ! Output


-- mysql> CREATE TABLE Employee2 (
--     ENAME VARCHAR(50),
--     ->     EMPNO INT PRIMARY KEY,
--     ->     ENAME VARCHAR(50),
--     ->     JOB VARCHAR(50),
--     ->     MGR INT,
--     ->     SAL DECIMAL(10,2)
--     -> );
-- Query OK, 0 rows affected (0.05 sec)


-- mysql> ALTER TABLE Employee2
--     -> ADD commission DECIMAL(10,2) CHECK (commission >= 0);
-- Query OK, 0 rows affected (0.11 sec)
-- Records: 0  Duplicates: 0  Warnings: 0


-- mysql> INSERT INTO Employee2 (EMPNO, ENAME, JOB, MGR, SAL, commission) VALUES
--     -> (101, 'Ravi', 'Clerk', 201, 20000, 500),
--     -> (102, 'Anita', 'Manager', NULL, 50000, 2000),
--     -> (103, 'Kiran', 'Analyst', 202, 40000, 1500),
--     -> (104, 'Meena', 'Clerk', 201, 22000, 600),
--     -> (105, 'Arjun', 'Salesman', 203, 30000, 1000);
-- Query OK, 5 rows affected (0.01 sec)
-- Records: 5  Duplicates: 0  Warnings: 0


-- mysql> INSERT INTO Employee2 (EMPNO, ENAME, JOB, MGR, SAL, commission) VALUES
--     -> (106, 'Kumar', 'Salesman', 203, 30000, -20);
-- ERROR 3819 (HY000): Check constraint 'Employee2_chk_1' is violated.


-- mysql> UPDATE Employee2
--     -> SET JOB = 'Senior Clerk'
--     -> Where job = 'Clerk';
-- Query OK, 2 rows affected (0.01 sec)
-- Rows matched: 2  Changed: 2  Warnings: 0


-- mysql> ALTER TABLE Employee2
--     -> RENAME COLUMN ENAME TO EMP_NAME;
-- Query OK, 0 rows affected (0.02 sec)
-- Records: 0  Duplicates: 0  Warnings: 0


-- mysql> SELECT * FROM employee2
--     -> ;
-- ERROR 1146 (42S02): Table 'lab.employee2' doesn't exist

-- mysql> SELECT * FROM Employee2
--     -> ;
-- +-------+----------+--------------+------+----------+------------+
-- | EMPNO | EMP_NAME | JOB          | MGR  | SAL      | commission |
-- +-------+----------+--------------+------+----------+------------+
-- |   101 | Ravi     | Senior Clerk |  201 | 20000.00 |     500.00 |
-- |   102 | Anita    | Manager      | NULL | 50000.00 |    2000.00 |
-- |   103 | Kiran    | Analyst      |  202 | 40000.00 |    1500.00 |
-- |   104 | Meena    | Senior Clerk |  201 | 22000.00 |     600.00 |
-- |   105 | Arjun    | Salesman     |  203 | 30000.00 |    1000.00 |
-- +-------+----------+--------------+------+----------+------------+
-- 5 rows in set (0.00 sec)


-- mysql> DELETE FROM Employee2
--     -> WHERE EMPNO = 105;
-- Query OK, 1 row affected (0.01 sec)


-- mysql> SELECT * FROM Employee2;
-- +-------+----------+--------------+------+----------+------------+
-- | EMPNO | EMP_NAME | JOB          | MGR  | SAL      | commission |
-- +-------+----------+--------------+------+----------+------------+
-- |   101 | Ravi     | Senior Clerk |  201 | 20000.00 |     500.00 |
-- |   102 | Anita    | Manager      | NULL | 50000.00 |    2000.00 |
-- |   103 | Kiran    | Analyst      |  202 | 40000.00 |    1500.00 |
-- |   104 | Meena    | Senior Clerk |  201 | 22000.00 |     600.00 |
-- +-------+----------+--------------+------+----------+------------+
-- 4 rows in set (0.00 sec)