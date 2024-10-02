#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

class QSqlQueryModel;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionClose_triggered();

    void on_toolButton_clicked();

    void on_buttonInsert_clicked();

private:
    void connectWithSqlServer();
    void reloadEmployeeTable();

    Ui::MainWindow *ui;
    QSqlDatabase m_db;
    QSqlQueryModel *m_employeeModel;
};

#endif // MAINWINDOW_H
