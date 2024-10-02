#include "jobtitlecombopopulator.h"

#include <QComboBox>
#include <QSqlQuery>

JobTitleComboPopulator::JobTitleComboPopulator() {}

void JobTitleComboPopulator::populate()
{
    if (!m_combo)
    {
        return;
    }
    QSqlQuery query;
    query.exec("SELECT Title FROM JobTitle");
    while (query.next())
    {
        m_combo->addItem(query.value(0).toString());
    }
}
