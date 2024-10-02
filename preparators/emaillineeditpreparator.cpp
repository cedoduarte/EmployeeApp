#include "emaillineeditpreparator.h"

#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

EmailLineEditPreparator::EmailLineEditPreparator() {}

void EmailLineEditPreparator::prepare()
{
    if (!m_lineEdit)
    {
        return;
    }
    QRegularExpression emailRegex(R"((^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$))");
    QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegex, m_lineEdit);
    m_lineEdit->setValidator(emailValidator);
}
