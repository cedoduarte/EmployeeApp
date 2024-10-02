#include "salarylineeditpreparator.h"

#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

SalaryLineEditPreparator::SalaryLineEditPreparator() {}

void SalaryLineEditPreparator::prepare()
{
    if (!m_lineEdit)
    {
        return;
    }
    QRegularExpression salaryRegex(R"(^[0-9]+(\.[0-9]{1,2})?$)"); // Allows integers and decimals up to 2 decimal places
    QRegularExpressionValidator *salaryValidator = new QRegularExpressionValidator(salaryRegex, m_lineEdit);
    m_lineEdit->setValidator(salaryValidator);
}
