#include "departmentcombopopulator.h"

#include <QComboBox>
#include <QSqlQuery>

DepartmentComboPopulator::DepartmentComboPopulator() {}

void DepartmentComboPopulator::populate()
{
    if (!m_combo)
    {
        return;
    }
    QSqlQuery query;
    query.exec("SELECT DepartmentName FROM Department");
    while (query.next())
    {
        m_combo->addItem(query.value(0).toString());
    }
}
