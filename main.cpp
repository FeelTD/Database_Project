#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("F:\\Program Files\\SQLiteStudio\\students");
    db.open();//открытие базы данных

    QApplication a(argc, argv);
    MainWindow w;

    QSqlDatabase* db_pointer = &db;
    w.changeText (db_pointer);

    QSqlQuery query;
    query.exec("SELECT FIO FROM enrollees");

    if (query.first())
    {
        QSqlRecord record = query.record();
        QString FIO = query.value(record.indexOf("FIO")).toString();
        w.outputData (FIO);
    }
    else
    {
        w.outputData ("FAILED TO EXECUTE!");
    }//всё это нужно только для проверки работоспособности таблицы, потом можно будет переделать под эскуэль-запросы

    w.setTableChoices(db_pointer);
//    //QString name = ui->comboBoxTableChoice->currentText();
//    QSqlRelationalTableModel* table_ptr=nullptr;
//    table_ptr->setTable("enrollees");
//    w.showTable(table_ptr);
    QSqlRelationalTableModel* table_ptr = new QSqlRelationalTableModel(nullptr,db);
    w.chooseTableFromList (table_ptr);
    w.show();

    db.close();
    return a.exec();
}
