#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../sql/sqlserver.h"
#include "../sql/employeeinserter.h"
#include "../populators/jobtitlecombopopulator.h"
#include "../populators/departmentcombopopulator.h"
#include "../preparators/emaillineeditpreparator.h"
#include "../preparators/salarylineeditpreparator.h"
#include "managerselectordialog.h"

#include <QSqlError>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_employeeModel = new QSqlQueryModel(this);
    ui->employeeTableView->setModel(m_employeeModel);

    connectWithSqlServer();

    JobTitleComboPopulator comboJobTitlePopulator;
    comboJobTitlePopulator.setCombo(ui->comboJobTitle);
    comboJobTitlePopulator.populate();

    DepartmentComboPopulator comboDepartmentPopulator;
    comboDepartmentPopulator.setCombo(ui->comboDepartment);
    comboDepartmentPopulator.populate();

    EmailLineEditPreparator emailPreparator;
    emailPreparator.setLineEdit(ui->txtEmail);
    emailPreparator.prepare();

    SalaryLineEditPreparator salaryPreparator;
    salaryPreparator.setLineEdit(ui->txtSalary);
    salaryPreparator.prepare();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectWithSqlServer()
{
    m_db = QSqlDatabase::addDatabase(QT_DATABASE_DRIVER);
    m_db.setDatabaseName(SQL_SERVER_CONNECTION_STRING);
    if (!m_db.open())
    {
        QMessageBox::critical(this, "Error", m_db.lastError().text());
        return;
    }
    ui->statusbar->showMessage("SQL Server connection done!");
    reloadEmployeeTable();
}

void MainWindow::reloadEmployeeTable()
{
    m_employeeModel->setQuery(QSqlQuery("SELECT * FROM Employee"));
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_toolButton_clicked()
{
    ManagerSelectorDialog selectorDialog(this);
    if (selectorDialog.exec() == QDialog::Accepted)
    {
        ui->txtManagerId->setText(QString::number(selectorDialog.selectedManagerId()));
    }
}

void MainWindow::on_buttonInsert_clicked()
{
    EmployeeInserter inserter;
    if (inserter.insertEmployee(ui->txtFirstName->text(), ui->txtLastName->text(), ui->dateBirthdate->date(),
                                ui->dateHireDate->date(), ui->txtEmail->text(), ui->txtPhoneNumber->text(),
                                ui->comboJobTitle->currentText(), ui->txtSalary->text().toDouble(),
                                ui->comboDepartment->currentText(), ui->txtManagerId->text().toInt(),
                                ui->checkIsActive->isChecked()))
    {
        reloadEmployeeTable();
    }
}

