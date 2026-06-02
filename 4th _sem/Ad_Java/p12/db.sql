-- Active: 1774368305703@@127.0.0.1@3306
CREATE DATABASE login_db;

USE login_db;

CREATE TABLE users (
    user_id VARCHAR(50) PRIMARY KEY,
    password VARCHAR(100)
);

INSERT INTO users VALUES
('admin','1234'),
('sudhanva','pass123');