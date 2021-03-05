#include "logan.h"
#include "logFile.h"
#include "ui_logan.h"

#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QList>
#include <QWidget>
#include <QFlags>
#include <QDebug>

//основной метод построения таблицы с данными
QString Logan::dataBuilder(QString filePath) {

    //сброс всех значений последней выборки из таблицы
    csvModel->clear();
    csvModel->setColumnCount(15);

    ui->linesAmount->setText("");
    ui->structInitialization->setText("");
    ui->syntaxAnalysis->setText("");
    ui->labelSent->setText("");
    ui->labelReceived->setText("");
    ui->bytesSent->setText("");
    ui->bytesReceived->setText("");

    ui->kbSent->setText("");
    ui->mbSent->setText("");
    ui->gbSent->setText("");
    ui->kbReceived->setText("");
    ui->mbReceived->setText("");
    ui->gbReceived->setText("");

    //задание наименований столбцов таблицы
    csvModel->setHorizontalHeaderLabels(QStringList()
        << "Дата"              << "Время"             << "IP адрес\nклиента"    << "Логин"
        << "Хост"              << "Порт\nсервера"     << "Метод"                << "URI Stem"
        << "Статус\nпротокола" << "Статус\nWin32"     << "Субстатус\nпротокола" << "Байт\nпередано"
        << "Байт\nпринято"     << "Время\nвыполнения" << "Полный\nпуть"         << "Доп.\nинф-я");

    //установка ширины столбцов таблицы
    ui->tableView->setColumnWidth(0, 75);
    ui->tableView->setColumnWidth(1, 65);
    ui->tableView->setColumnWidth(2, 100);
    ui->tableView->setColumnWidth(3, 100);
    ui->tableView->setColumnWidth(4, 45);
    ui->tableView->setColumnWidth(5, 65);
    ui->tableView->setColumnWidth(6, 60);
    ui->tableView->setColumnWidth(7, 85);
    ui->tableView->setColumnWidth(8, 75);
    ui->tableView->setColumnWidth(9, 55);
    ui->tableView->setColumnWidth(10, 80);
    ui->tableView->setColumnWidth(11, 80);
    ui->tableView->setColumnWidth(12, 85);
    ui->tableView->setColumnWidth(13, 85);
    ui->tableView->setColumnWidth(14, 65);
    ui->tableView->setColumnWidth(15, 65);

    //вызов метода определения количества записей в исходном файле, запись возвращаемого значения в переменную
    int SIZE = fileSize(filePath);

    //выделение памяти под массив структур, используемый для хранения записей
    struct logFile *logArray = new logFile[SIZE];

    //вызов метода инициализации массива структур нулевыми значениями
    logInit(logArray, SIZE);

    //вызов метода проведения синтаксического анализа исходного файла
    logRead(logArray, filePath);

    //вызов метода управления фильтрацией записей
    menu(logArray, SIZE, filePath);

    //вставка в результирующую таблицу выборки записей, удовлетворяющих условиям фильтрации
    int rowCounter = 0;
    QFile file(filePath + ".csv");
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "File is not exist!";
    } else {
        QTextStream in(&file);
        while(!in.atEnd()) {
            QString line = in.readLine();
            if(line.startsWith("2")) {
                rowCounter++;
                QList<QStandardItem *> standardItemList;
                for(QString item : line.split("; ")) {
                    standardItemList.append(new QStandardItem(item));
                }
                csvModel->insertRow(csvModel->rowCount(), standardItemList);
            }
        }
        //вывод в интерфейс значения количества записей в текущей выборке
        ui->linesAmount->setText("Количество записей: " + QString::number(rowCounter));
        file.close();
    }
    file.remove();
    return filePath;

}
