#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::changeText (QSqlDatabase* db_pointer)
{
    if (db_pointer->open())
        {ui->DatabaseConnectionResultLabel->setText("Success!");}
    else
        {ui->DatabaseConnectionResultLabel->setText(db_pointer->lastError().text());}
}

void MainWindow::closeWindow()
{
    this->close();
}

void MainWindow::outputData (QString str)
{
    ui->dataOutput->append(str);
}

void MainWindow::showTable (QSqlRelationalTableModel* table_ptr)
{
    table_ptr->select();
    ui->tableViewDatabase->setModel(table_ptr);
    ui->tableViewDatabase->show();
}

void MainWindow::setTableChoices (QSqlDatabase* db_pointer)
{
    QStringList tables_list = db_pointer->tables();
    foreach(QString str, tables_list)
        {
            ui->comboBoxTableChoice->addItem(str);
        }
}

void MainWindow::chooseTableFromList (QSqlRelationalTableModel* table_ptr) //<-сюда надо передать указатель на QSqlRelationalTableModel
{
    QString name = ui->comboBoxTableChoice->currentText();
    //table_ptr->select();
    table_ptr->setTable(name);
    //table_ptr->select();
    this->showTable(table_ptr);
    table_ptr->select();
}


MainWindow::~MainWindow()
{
    delete ui;
}

