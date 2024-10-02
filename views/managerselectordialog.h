#ifndef MANAGERSELECTORDIALOG_H
#define MANAGERSELECTORDIALOG_H

#include <QDialog>

class QSqlQueryModel;

namespace Ui
{
class ManagerSelectorDialog;
}

class ManagerSelectorDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ManagerSelectorDialog(QWidget *parent = nullptr);
    ~ManagerSelectorDialog();
    int selectedManagerId() const;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::ManagerSelectorDialog *ui;
    QSqlQueryModel *m_managerModel;
};

#endif // MANAGERSELECTORDIALOG_H
