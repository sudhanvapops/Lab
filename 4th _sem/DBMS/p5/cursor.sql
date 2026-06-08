-- Active: 1774368305703@@127.0.0.1@3306@lab

-- Program 5

-- Create cursor for Employee table & extract the values from the table.
--  Declare the variables ,Open the cursor & extrct the values from the cursor. 
-- Close the cursor. 
-- Employee(E_id, E_name, Age, Salary)


-- Program is basically doing this:
-- Go to the table → pick one row → store it → print it → repeat until no rows left


-- Create Employee table (for testing)
CREATE TABLE Employee5 (
    E_id INT,
    E_name VARCHAR(50),
    Age INT,
    Salary DECIMAL(10,2)
);

-- Insert sample data
INSERT INTO Employee5 VALUES
(1, 'Amit', 25, 20000),
(2, 'Ravi', 30, 30000),
(3, 'Sneha', 28, 25000);

SELECT * from employee5

-- Cursor Program
DELIMITER $$

CREATE PROCEDURE employee5_cursor_demo()
BEGIN
    -- 1. Declare variables to store fetched values
    DECLARE v_id INT;
    DECLARE v_name VARCHAR(50);
    DECLARE v_age INT;
    DECLARE v_salary DECIMAL(10,2);

    -- Variable to control loop
    DECLARE done INT DEFAULT 0;

    -- 2. Declare cursor
    DECLARE emp_cursor CURSOR FOR
        SELECT E_id, E_name, Age, Salary FROM Employee5;

    -- 3. Declare handler (important to stop loop)
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    -- 4. Open cursor
    OPEN emp_cursor;

    -- 5. Fetch rows one by one
    read_loop: LOOP
        FETCH emp_cursor INTO v_id, v_name, v_age, v_salary;

        IF done THEN
            LEAVE read_loop;
        END IF;

        -- Process each row (here we just display it)
        SELECT v_id, v_name, v_age, v_salary;
    END LOOP;

    -- 6. Close cursor
    CLOSE emp_cursor;

END $$

DELIMITER ;


-- Run it
CALL employee5_cursor_demo();