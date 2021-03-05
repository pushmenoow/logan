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

//метод инициализации массива структур нулевыми значениями
void Logan::logInit(struct logFile *logArray, int SIZE) {
    for(int i = 0; i < SIZE; i++) {
        logArray[i].date		  = '\0';
        logArray[i].time		  = '\0';
        logArray[i].c_ip		  = '\0';
        logArray[i].cs_username   = '\0';
        logArray[i].cs_host	      = '\0';
        logArray[i].s_port	      = '\0';
        logArray[i].cs_method	  = '\0';
        logArray[i].cs_uri_stem   = '\0';
        logArray[i].sc_status	  = '\0';
        logArray[i].sc_win32_stat = '\0';
        logArray[i].sc_substatus  = '\0';
        logArray[i].sc_bytes	  = '\0';
        logArray[i].cs_bytes	  = '\0';
        logArray[i].time_taken	  = '\0';
        logArray[i].x_fullpath    = '\0';
        logArray[i].x_debug	      = '\0';
        logArray[i].attr		  = '\0';
    }
    ui->structInitialization->setText("Структура инициализирована");
}
