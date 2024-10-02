#ifndef ILINEEDITPREPARATOR_H
#define ILINEEDITPREPARATOR_H

class QLineEdit;

class ILineEditPreparator
{
public:
    virtual void prepare() = 0;

    void setLineEdit(QLineEdit *lineEdit)
    {
        m_lineEdit = lineEdit;
    }

    QLineEdit* lineEdit() const
    {
        return m_lineEdit;
    }
protected:
    QLineEdit *m_lineEdit;
};

#endif // ILINEEDITPREPARATOR_H
