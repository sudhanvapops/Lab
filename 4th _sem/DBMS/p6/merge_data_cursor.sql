-- Write a SQL block of code using parameterized Cursor 
-- that will merge the data available in the newly created table N_RollCall with the data available in the table O_RollCall. 
-- If the data in the first table already exist in the second table then that data should be skipped


-- Create Old Roll Call Table
CREATE TABLE O_RollCall (
    RollNo INT,
    Name VARCHAR(30)
);

-- Create New Roll Call Table
CREATE TABLE N_RollCall (
    RollNo INT,
    Name VARCHAR(30)
);

-- Insert Sample Data into O_RollCall
INSERT INTO O_RollCall VALUES 
(1, 'RAHUL'),
(2, 'ANU');

-- Insert Sample Data into N_RollCall
INSERT INTO N_RollCall VALUES (2, 'ANU'),(3, 'KIRAN');

SELECT * from o_rollcall

SELECT * from n_rollcall

DELIMITER //

CREATE PROCEDURE Merge_RollCall()
BEGIN
    -- Variable to indicate end of cursor data
    DECLARE done INT DEFAULT 0;

    -- Variables to store fetched row values
    DECLARE v_roll INT;
    DECLARE v_name VARCHAR(30);

    -- Variable to check record existence
    DECLARE v_count INT;

    -- Cursor to fetch records from N_RollCall
    DECLARE roll_cursor CURSOR FOR
        SELECT RollNo, Name
        FROM N_RollCall;

    -- Handler executes when no more rows are available
    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    -- Open cursor
    OPEN roll_cursor;

    read_loop: LOOP

        -- Fetch one record at a time
        FETCH roll_cursor INTO v_roll, v_name;

        -- Exit loop when all rows are processed
        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        -- Check whether RollNo already exists
        SELECT COUNT(*)
        INTO v_count
        FROM O_RollCall
        WHERE RollNo = v_roll;

        -- Insert only if record does not exist
        IF v_count = 0 THEN
            INSERT INTO O_RollCall
            VALUES (v_roll, v_name);
        END IF;

    END LOOP;

    -- Close cursor
    CLOSE roll_cursor;

END //

DELIMITER ;

-- Execute Procedure
CALL Merge_RollCall();

-- Display Final Result
SELECT * FROM O_RollCall;