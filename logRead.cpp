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

//метод чтения и синтаксического анализа журнала логов
void Logan::logRead(struct logFile *logArray, QString filePath) {
    QFile file(filePath);
    qDebug() << filePath;
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "File is not opened!";
    } else {
        QTextStream in(&file);
        int i = 0;
        while(!in.atEnd()) {
            QString line = in.readLine();
            QList<QString> fields;

            //задание знака разделителя полей
            fields.append(line.split(" "));

            //парсинг записей с информационными полями и запись в массив структур
            if(fields.at(0).startsWith("2")) {
                logArray[i].date          = fields.at(0);
                logArray[i].time          = fields.at(1);
                logArray[i].c_ip          = fields.at(2);
                logArray[i].cs_username   = fields.at(3);
                logArray[i].cs_host       = fields.at(4);
                logArray[i].s_port        = fields.at(5);
                logArray[i].cs_method     = fields.at(6);
                logArray[i].cs_uri_stem   = fields.at(7);
                logArray[i].sc_status     = fields.at(8);
                logArray[i].sc_win32_stat = fields.at(9);
                logArray[i].sc_substatus  = fields.at(10);
                logArray[i].sc_bytes      = fields.at(11);
                logArray[i].cs_bytes      = fields.at(12);
                logArray[i].time_taken    = fields.at(13);
                logArray[i].x_fullpath    = fields.at(14);
                logArray[i].x_debug       = fields.at(15);
                i++;
            }
        }
    }
    ui->syntaxAnalysis->setText("Синтаксический анализ произведён");
}
