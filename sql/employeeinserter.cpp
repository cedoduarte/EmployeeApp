#include "employeeinserter.h"

#include <QSqlQuery>
#include <QSqlError>

EmployeeInserter::EmployeeInserter() {}

bool EmployeeInserter::insertEmployee(const QString &firstName, const QString &lastName, const QDate &birthDate,
                                      const QDate &hireDate, const QString &email, const QString &phoneNumber,
                                      const QString &jobTitle, double salary, const QString &department, int managerID,
                                      bool isActive)
{
    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO Employee (FirstName, LastName, BirthDate, HireDate, Email, PhoneNumber, JobTitle, Salary, Department, ManagerID, IsActive)
        VALUES (:firstName, :lastName, :birthDate, :hireDate, :email, :phoneNumber, :jobTitle, :salary, :department, :managerID, :isActive)
    )");

    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":birthDate", birthDate);
    query.bindValue(":hireDate", hireDate);
    query.bindValue(":email", email);
    query.bindValue(":phoneNumber", phoneNumber);
    query.bindValue(":jobTitle", jobTitle);
    query.bindValue(":salary", salary);
    query.bindValue(":department", department);
    query.bindValue(":managerID", managerID);
    query.bindValue(":isActive", isActive);

    if (!query.exec())
    {
        qDebug() << "Insert failed:" << query.lastError().text();
        return false;
    }
    return true;
}
