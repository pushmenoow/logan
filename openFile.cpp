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

//метод обработки нажатия на кнопку "Открыть файл"
void Logan::openFile() {

    //сброс всех значений последней выборки из таблицы
    csvModel->clear();

    ui->filePath->setText("");

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

    //открытие исходного файла для чтения и проведения синтаксического анализа
    QString filePath;
    filePath = QFileDialog::getOpenFileName(0, tr("Открыть файл журнала Microsoft IIS"), "", tr("Microsoft IIS logfile (*.log)"));
    ui->filePath->setText(filePath);
    dataBuilder(filePath);
}
