#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSqlDatabase>
#include <QMainWindow>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QTextEdit>
#include <QTextBrowser>
#include <QSqlRecord>
#include <QTableView>
#include <QSqlRelationalTableModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void changeText(QSqlDatabase* db_pointer);
    void closeWindow();
    void outputData(QString str);
    void showTable (QSqlRelationalTableModel* table_ptr);
    void setTableChoices (QSqlDatabase* db_pointer);
    void selectTable (QSqlRelationalTableModel* table_ptr, QSqlDatabase* db_pointer);
    void chooseTableFromList (QSqlRelationalTableModel* table_ptr);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
