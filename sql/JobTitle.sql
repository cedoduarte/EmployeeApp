CREATE TABLE JobTitle (
    JobTitleID INT IDENTITY(1,1) PRIMARY KEY,  -- Unique identifier, auto-incremented
    Title NVARCHAR(100) NOT NULL,              -- Job title name (e.g., Manager, Engineer, etc.)
    Description NVARCHAR(255),                 -- Brief description of the job title
    MinSalary DECIMAL(18, 2),                  -- Minimum salary for the job title
    MaxSalary DECIMAL(18, 2)                   -- Maximum salary for the job title
);

INSERT INTO JobTitle (Title, Description, MinSalary, MaxSalary)
VALUES 
('Software Engineer', 'Responsible for developing software', 50000, 120000),
('Project Manager', 'Oversees project planning and execution', 60000, 150000),
('HR Manager', 'Manages human resources department', 55000, 90000),
('Finance Analyst', 'Responsible for financial analysis', 50000, 95000),
('Sales Executive', 'Handles client sales and business development', 40000, 85000),
('Marketing Manager', 'Leads marketing campaigns', 60000, 130000),
('Data Scientist', 'Works with data analytics and machine learning', 70000, 140000),
('DevOps Engineer', 'Responsible for deployment and operations', 60000, 130000),
('Customer Support', 'Handles customer inquiries and support', 35000, 60000),
('Business Analyst', 'Analyzes business processes', 55000, 100000);
