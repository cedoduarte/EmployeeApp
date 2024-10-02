CREATE TABLE Manager (
    ManagerID INT IDENTITY(1,1) PRIMARY KEY,     -- Unique identifier, auto-incremented
    FirstName NVARCHAR(50) NOT NULL,             -- Manager's first name
    LastName NVARCHAR(50) NOT NULL,              -- Manager's last name
    Email NVARCHAR(100),                         -- Manager's email
    PhoneNumber NVARCHAR(15),                    -- Manager's phone number
    DepartmentID INT,                            -- The department managed by this manager
    HireDate DATE NOT NULL                       -- Date the manager was hired
);

INSERT INTO Manager (FirstName, LastName, Email, PhoneNumber, DepartmentID, HireDate)
VALUES 
('John', 'Doe', 'jdoe@example.com', '123-456-7890', 1, '2015-06-01'),
('Jane', 'Smith', 'jsmith@example.com', '234-567-8901', 2, '2016-08-15'),
('Michael', 'Johnson', 'mjohnson@example.com', '345-678-9012', 3, '2017-02-20'),
('Emily', 'Davis', 'edavis@example.com', '456-789-0123', 4, '2018-11-05'),
('Chris', 'Brown', 'cbrown@example.com', '567-890-1234', 5, '2019-03-18'),
('Sarah', 'Wilson', 'swilson@example.com', '678-901-2345', 6, '2020-01-07'),
('David', 'Lee', 'dlee@example.com', '789-012-3456', 7, '2021-09-13'),
('Amanda', 'Garcia', 'agarcia@example.com', '890-123-4567', 8, '2022-04-10'),
('James', 'Martinez', 'jmartinez@example.com', '901-234-5678', 9, '2022-06-29'),
('Laura', 'Anderson', 'landerson@example.com', '012-345-6789', 10, '2023-01-12');
