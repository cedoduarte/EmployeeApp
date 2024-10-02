CREATE TABLE Employee (
    EmployeeID INT IDENTITY(1,1) PRIMARY KEY, -- Unique identifier, auto-incremented
    FirstName NVARCHAR(50) NOT NULL,          -- Employee's first name (max 50 characters)
    LastName NVARCHAR(50) NOT NULL,           -- Employee's last name (max 50 characters)
    BirthDate DATE,                           -- Employee's birth date
    HireDate DATE NOT NULL,                   -- Date the employee was hired
    Email NVARCHAR(100),                      -- Employee's email address
    PhoneNumber NVARCHAR(15),                 -- Employee's phone number
    JobTitle NVARCHAR(100) NOT NULL,          -- Employee's job title (max 100 characters)
    Salary DECIMAL(18, 2) NOT NULL,           -- Employee's salary (using DECIMAL for financial precision)
    Department NVARCHAR(50),                  -- Department the employee belongs to
    ManagerID INT,                            -- ID of the manager (foreign key reference if applicable)
    IsActive BIT NOT NULL DEFAULT 1           -- Status of employment (active/inactive)
);

INSERT INTO Employee (FirstName, LastName, BirthDate, HireDate, Email, PhoneNumber, JobTitle, Salary, Department, ManagerID, IsActive)
VALUES 
('Alice', 'Taylor', '1990-03-15', '2020-05-22', 'alice.taylor@example.com', '123-456-7890', 'Software Engineer', 85000.00, 'IT', 2, 1),
('Bob', 'Williams', '1985-07-10', '2018-04-11', 'bob.williams@example.com', '234-567-8901', 'HR Manager', 75000.00, 'HR', 1, 1),
('Charlie', 'Harris', '1987-09-18', '2019-06-30', 'charlie.harris@example.com', '345-678-9012', 'Finance Analyst', 90000.00, 'Finance', 3, 1),
('Diana', 'Clark', '1992-02-27', '2021-08-14', 'diana.clark@example.com', '456-789-0123', 'Sales Executive', 65000.00, 'Sales', 4, 1),
('Ethan', 'Lewis', '1993-05-08', '2020-09-18', 'ethan.lewis@example.com', '567-890-1234', 'Project Manager', 95000.00, 'IT', 2, 1),
('Fiona', 'Walker', '1989-11-25', '2021-07-23', 'fiona.walker@example.com', '678-901-2345', 'Marketing Manager', 78000.00, 'Marketing', 5, 1),
('George', 'Hall', '1991-12-17', '2022-11-02', 'george.hall@example.com', '789-012-3456', 'Data Scientist', 105000.00, 'Operations', 6, 1),
('Hannah', 'Young', '1990-01-06', '2023-03-12', 'hannah.young@example.com', '890-123-4567', 'DevOps Engineer', 98000.00, 'Research and Development', 8, 1),
('Isaac', 'King', '1988-04-22', '2022-10-30', 'isaac.king@example.com', '901-234-5678', 'Customer Support', 50000.00, 'Customer Support', 7, 1),
('Julia', 'Scott', '1995-06-13', '2021-05-16', 'julia.scott@example.com', '012-345-6789', 'Business Analyst', 85000.00, 'Logistics', 9, 1);

