#ifndef ICOMBOPOPULATOR_H
#define ICOMBOPOPULATOR_H

class QComboBox;

class IComboPopulator
{
public:
    virtual void populate() = 0;

    void setCombo(QComboBox *combo)
    {
        m_combo = combo;
    }

    QComboBox* combo() const
    {
        return m_combo;
    }
protected:
    QComboBox *m_combo;
};

#endif // ICOMBOPOPULATOR_H
