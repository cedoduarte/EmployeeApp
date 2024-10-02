#ifndef EMPLOYEEINSERTER_H
#define EMPLOYEEINSERTER_H

#include <QString>
#include <QDate>

class EmployeeInserter
{
public:
    EmployeeInserter();
    bool insertEmployee(const QString &firstName, const QString &lastName, const QDate &birthDate,
                        const QDate &hireDate, const QString &email, const QString &phoneNumber,
                        const QString &jobTitle, double salary, const QString &department,
                        int managerID, bool isActive);
};

#endif // EMPLOYEEINSERTER_H
