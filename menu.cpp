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

//метод определения типа выбранного фильтра записей
void Logan::menu(struct logFile *logArray, int SIZE, QString filePath) {
    QString startValue = "";
    QString endValue   = "";

    //фильтр по полю Дата
    if(ui->checkData->isChecked()) {
        startValue = ui->lineDate->text();
        logSearch(logArray, SIZE, 1, startValue, endValue, filePath);
    }
    //фильтр по полю Время
    if(ui->checkTime->isChecked()) {
        startValue = ui->lineTime->text();
        logSearch(logArray, SIZE, 2, startValue, endValue, filePath);
    }
    //фильтр по полю IP-адрес клиента
    if(ui->checkClientIP->isChecked()) {
        startValue = ui->lineClientIP->text();
        logSearch(logArray, SIZE, 3, startValue, endValue, filePath);
    }
    //фильтр по полю Имя пользователя
    if(ui->checkUsername->isChecked()) {
        startValue = ui->lineUsername->text();
        logSearch(logArray, SIZE, 4, startValue, endValue, filePath);
    }
    //фильтр по полю Хост
    if(ui->checkHost->isChecked()) {
        startValue = ui->lineHost->text();
        logSearch(logArray, SIZE, 5, startValue, endValue, filePath);
    }
    //фильтр по полю Порт сервера
    if(ui->checkServerPort->isChecked()) {
        startValue = ui->lineServerPort->text();
        logSearch(logArray, SIZE, 6, startValue, endValue, filePath);
    }
    //фильтр по полю Метод
    if(ui->checkMethod->isChecked()) {
        startValue = ui->lineMethod->text();
        if(!(startValue.startsWith("Da") | startValue.startsWith("Co"))) {
            for(int i = 0; i < startValue.length(); i++) {
                if (startValue[i] >= 'a' && startValue[i] <= 'z') startValue[i] = startValue[i].toUpper();
            }
        }
        logSearch(logArray, SIZE, 7, startValue, endValue, filePath);
    }
    //фильтр по полю Ресурс URI
    if(ui->checkURIStem->isChecked()) {
        startValue = ui->lineURIStem->text();
        logSearch(logArray, SIZE, 8, startValue, endValue, filePath);
    }
    //фильтр по полю Состояние протокола
    if(ui->checkProtocolStatus->isChecked()) {
        startValue = ui->lineProtocolStatus->text();
        logSearch(logArray, SIZE, 9, startValue, endValue, filePath);
    }
    //фильтр по полю Состояние Win32
    if(ui->checkWin32Status->isChecked()) {
        startValue = ui->lineWin32Stat->text();
        logSearch(logArray, SIZE, 10, startValue, endValue, filePath);
    }
    //фильтр по полю Субсостояние протокола
    if(ui->checkProtocolSubstatus->isChecked()) {
        startValue = ui->lineProtocolSubstatus->text();
        logSearch(logArray, SIZE, 11, startValue, endValue, filePath);
    }
    //фильтр по полю Байт передано
    if(ui->checkBytesSent->isChecked()) {
        startValue = ui->lineBytesSent->text();
        logSearch(logArray, SIZE, 12, startValue, endValue, filePath);
    }
    //фильтр по полю Байт получено
    if(ui->checkBytesReceived->isChecked()) {
        startValue = ui->lineBytesReceived->text();
        logSearch(logArray, SIZE, 13, startValue, endValue, filePath);
    }
    //фильтр по полю Время выполнения
    if(ui->checkTimeTaken->isChecked()) {
        startValue = ui->lineTimeTaken->text();
        logSearch(logArray, SIZE, 14, startValue, endValue, filePath);
    }
    //фильтр по полю Полный путь
    if(ui->checkFullPath->isChecked()) {
        startValue = ui->lineFullPath->text();
        logSearch(logArray, SIZE, 15, startValue, endValue, filePath);
    }
    //фильтр по полю Дополнительная информация
    if(ui->checkAddInfo->isChecked()) {
        startValue = ui->lineAddInfo->text();
        logSearch(logArray, SIZE, 16, startValue, endValue, filePath);
    }
    //фильтр по диапазону дат
    if(ui->checkDateCorridor->isChecked()) {
        startValue = ui->lineDateStart->text();
        endValue   = ui->lineDateStop->text();
        logSearch(logArray, SIZE, 17, startValue, endValue, filePath);
    }
    //фильтр по диапазону времени
    if(ui->checkTimeCorridor->isChecked()) {
        startValue = ui->lineTimeStart->text();
        endValue   = ui->lineTimeStop->text();
        logSearch(logArray, SIZE, 18, startValue, endValue, filePath);
    }
    //если фильтрация записей отключена
    logSearch(logArray, SIZE, -1, startValue, endValue, filePath);
}
