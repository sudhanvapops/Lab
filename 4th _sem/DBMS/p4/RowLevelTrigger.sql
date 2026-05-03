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