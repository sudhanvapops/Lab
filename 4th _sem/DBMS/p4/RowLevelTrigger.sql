-- Active: 1774368305703@@127.0.0.1@3306@lab

-- Program 4

-- Create a row level trigger for the CUSTOMERS table 
-- that would fire for INSERT or UPDATE or DELETE operations performed on the CUSTOMERS table. 
-- This trigger will display the salary difference between the old & new Salary.
-- CUSTOMERS(ID,NAME,AGE,ADDRESS,SALARY)



-- Create Table
CREATE TABLE CUSTOMERS (
    ID INT PRIMARY KEY,
    NAME VARCHAR(20) NOT NULL,
    AGE INT,
    ADDRESS VARCHAR(25),
    SALARY DECIMAL
);


-- 2. Insert Sample Data
INSERT INTO CUSTOMERS VALUES 
(111, 'Kavana', 20, 'Bengaluru', 29000),
(222, 'Darshan', 35, 'Hassan', 15000);

SELECT * FROM CUSTOMERS;




-- 3. Create a LOG table
-- WHY?
-- Triggers in MySQL cannot print output directly,
-- so we store results here and view them using SELECT
CREATE TABLE salary_log (
    log_id INT AUTO_INCREMENT PRIMARY KEY,  -- Unique log entry
    customer_id INT,                        -- Which customer was affected
    old_salary DECIMAL(10,2),               -- Salary before operation
    new_salary DECIMAL(10,2),               -- Salary after operation
    difference DECIMAL(10,2),               -- Calculated difference
    action_type VARCHAR(10),                -- INSERT / UPDATE / DELETE
    log_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP -- When event occurred
);



-- ================================
-- TRIGGERS
-- ================================

-- Note:
-- MySQL does NOT allow one trigger for multiple events
-- So we create 3 separate triggers


-- 4. Trigger for UPDATE
-- WHY?
-- To capture change in salary when it is modified
DELIMITER $$

CREATE TRIGGER salary_update_trigger
AFTER UPDATE ON CUSTOMERS
FOR EACH ROW
BEGIN
    -- Variable to store difference
    DECLARE salary_diff DECIMAL(10,2);

    -- OLD = value before update
    -- NEW = value after update
    SET salary_diff = NEW.SALARY - OLD.SALARY;

    -- Store result in log table
    INSERT INTO salary_log(customer_id, old_salary, new_salary, difference, action_type)
    VALUES (NEW.ID, OLD.SALARY, NEW.SALARY, salary_diff, 'UPDATE');
END $$



-- 5. Trigger for INSERT
-- WHY?
-- When new record is added, there is no OLD value
-- So difference = NEW salary itself

CREATE TRIGGER salary_insert_trigger
AFTER INSERT ON CUSTOMERS
FOR EACH ROW
BEGIN
    INSERT INTO salary_log(customer_id, old_salary, new_salary, difference, action_type)
    VALUES (NEW.ID, NULL, NEW.SALARY, NEW.SALARY, 'INSERT');
END $$



-- 6. Trigger for DELETE
-- WHY?
-- When row is deleted, NEW does not exist
-- So we use OLD salary and store negative difference

CREATE TRIGGER salary_delete_trigger
AFTER DELETE ON CUSTOMERS
FOR EACH ROW
BEGIN
    INSERT INTO salary_log(customer_id, old_salary, new_salary, difference, action_type)
    VALUES (OLD.ID, OLD.SALARY, NULL, -OLD.SALARY, 'DELETE');
END $$

DELIMITER ;


-- 7. Check if triggers are created successfully
SHOW TRIGGERS LIKE 'CUSTOMERS';



-- ================================
-- TESTING SECTION
-- ================================

-- Clear old logs for clean testing
TRUNCATE TABLE salary_log;

-- Check initial state
SELECT * FROM CUSTOMERS;
SELECT * FROM salary_log;



-- Test INSERT trigger
-- EXPECTATION:
-- old_salary = NULL, new_salary = value inserted
INSERT INTO CUSTOMERS VALUES (333, 'Ravi', 28, 'Mysuru', 20000);

SELECT * FROM salary_log;


-- Test UPDATE trigger
-- EXPECTATION:
-- old_salary = previous value, new_salary = updated value
UPDATE CUSTOMERS 
SET SALARY = 25000 
WHERE ID = 333;

SELECT * FROM salary_log;


-- Test DELETE trigger
-- EXPECTATION:
-- old_salary = last value, new_salary = NULL
DELETE FROM CUSTOMERS 
WHERE ID = 333;

SELECT * FROM salary_log;


-- Optional: Reset logs again
TRUNCATE TABLE salary_log;




-- ! Output

CREATE TRIGGER salary_insert_trigger
    -> AFTER INSERT ON CUSTOMERS
O salary_log(cus    -> FOR EACH ROW
    -> BEGIN
tomer_id, old_sa    ->     INSERT INTO salary_log(customer_id, old_salary, new_salary, difference, action_type)
    ->     VALUES (NEW.ID, NULL, NEW.SALARY, NEW.SALARY, 'INSERT');
    -> END $$
Query OK, 0 rows affected (0.03 sec)

mysql> CREATE TRIGGER salary_delete_trigger
    -> AFTER DELETE ON CUSTOMERS
    -> OR EACH ROW
BEGIFOR EACH ROW
    -> BEGIN
    ->     INSERT INTO salary_log(customer_id, old_salary, new_salary, difference, action_type)
ALUES (OLD.ID, O    ->     VALUES (OLD.ID, OLD.SALARY, NULL, -OLD.SALARY, 'DELETE');
    -> END $$

DELIMITER ;
Query OK, 0 rows affected (0.02 sec)

mysql> 
mysql> DELIMITER ;

 TRUNCATE TABLE salary_log;
Query OK, 0 rows affected (0.08 sec)

mysql> 
mysql> -- Check initial state
mysql> SELECT * FROM CUSTOMERS;
+-----+---------+------+-----------+--------+
| ID  | NAME    | AGE  | ADDRESS   | SALARY |
+-----+---------+------+-----------+--------+
| 111 | Kavana  |   20 | Bengaluru |  29000 |
| 222 | Darshan |   35 | Hassan    |  15000 |
+-----+---------+------+-----------+--------+
2 rows in set (0.00 sec)

mysql> SELECT * FROM salary_log;
Empty set (0.00 sec)

mysql> INSERT INTO CUSTOMERS VALUES (333, 'Ravi', 28, 'Mysuru', 20000);
Query OK, 1 row affected (0.02 sec)

mysql> 
mysql> SELECT * FROM salary_log;
+--------+-------------+------------+------------+------------+-------------+---------------------+
| log_id | customer_id | old_salary | new_salary | difference | action_type | log_time            |
+--------+-------------+------------+------------+------------+-------------+---------------------+
|      1 |         333 |       NULL |   20000.00 |   20000.00 | INSERT      | 2026-05-14 23:34:04 |
+--------+-------------+------------+------------+------------+-------------+---------------------+
1 row in set (0.00 sec)

mysql> UPDATE CUSTOMERS 
    -> SET SALARY = 25000 
    -> WHERE ID = 333;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> 
mysql> SELECT * FROM salary_log;
+--------+-------------+------------+------------+------------+-------------+---------------------+
| log_id | customer_id | old_salary | new_salary | difference | action_type | log_time            |
+--------+-------------+------------+------------+------------+-------------+---------------------+
|      1 |         333 |       NULL |   20000.00 |   20000.00 | INSERT      | 2026-05-14 23:34:04 |
|      2 |         333 |   20000.00 |   25000.00 |    5000.00 | UPDATE      | 2026-05-14 23:34:14 |
+--------+-------------+------------+------------+------------+-------------+---------------------+
2 rows in set (0.00 sec)

mysql> DELETE FROM CUSTOMERS 
    -> WHERE ID = 333;
Query OK, 1 row affected (0.01 sec)

mysql> 
mysql> SELECT * FROM salary_log;
+--------+-------------+------------+------------+------------+-------------+---------------------+
| log_id | customer_id | old_salary | new_salary | difference | action_type | log_time            |
+--------+-------------+------------+------------+------------+-------------+---------------------+
|      1 |         333 |       NULL |   20000.00 |   20000.00 | INSERT      | 2026-05-14 23:34:04 |
|      2 |         333 |   20000.00 |   25000.00 |    5000.00 | UPDATE      | 2026-05-14 23:34:14 |
|      3 |         333 |   25000.00 |       NULL |  -25000.00 | DELETE      | 2026-05-14 23:34:23 |
+--------+-------------+------------+------------+------------+-------------+---------------------+
3 rows in set (0.00 sec)

mysql> TRUNCATE TABLE salary_log;
Query OK, 0 rows affected (0.06 sec)

mysql> 