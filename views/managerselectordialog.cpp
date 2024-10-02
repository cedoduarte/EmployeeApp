#include "managerselectordialog.h"
#include "ui_managerselectordialog.h"

#include <QSqlQueryModel>
#include <QSqlQuery>

ManagerSelectorDialog::ManagerSelectorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManagerSelectorDialog)
{
    ui->setupUi(this);
    ui->managerTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->managerTableView->setSelectionMode(QAbstractItemView::SingleSelection);

    m_managerModel = new QSqlQueryModel(this);
    m_managerModel->setQuery(QSqlQuery("SELECT * FROM Manager"));
    ui->managerTableView->setModel(m_managerModel);
}

ManagerSelectorDialog::~ManagerSelectorDialog()
{
    delete ui;
}

int ManagerSelectorDialog::selectedManagerId() const
{
    QModelIndex currentIndex = ui->managerTableView->currentIndex();
    if (!currentIndex.isValid())
    {
        return 0;
    }
    int row = currentIndex.row();
    int idColumn = 0;
    QVariant data = m_managerModel->data(m_managerModel->index(row, idColumn));
    return data.toInt();
}

void ManagerSelectorDialog::on_buttonBox_accepted()
{
    accept();
}

void ManagerSelectorDialog::on_buttonBox_rejected()
{
    reject();
}

