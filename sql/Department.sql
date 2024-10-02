CREATE TABLE Department (
    DepartmentID INT IDENTITY(1,1) PRIMARY KEY,  -- Unique identifier, auto-incremented
    DepartmentName NVARCHAR(100) NOT NULL,       -- Name of the department
    Location NVARCHAR(100),                      -- Location of the department
    ManagerID INT,                               -- ID of the department manager (foreign key from Employee table)
    Budget DECIMAL(18, 2)                        -- Budget allocated for the department
);

INSERT INTO Department (DepartmentName, Location, ManagerID, Budget)
VALUES 
('HR', 'New York', 1, 100000),
('IT', 'San Francisco', 2, 200000),
('Finance', 'Los Angeles', 3, 150000),
('Sales', 'Chicago', 4, 120000),
('Marketing', 'Miami', 5, 130000),
('Operations', 'Boston', 6, 175000),
('Customer Support', 'Austin', 7, 90000),
('Research and Development', 'Seattle', 8, 250000),
('Logistics', 'Denver', 9, 110000),
('Legal', 'Philadelphia', 10, 160000);
