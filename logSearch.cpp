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

//метод организации процесса фильтрации записей
void Logan::logSearch(struct logFile *logArray, int SIZE, int attr, QString startValue, QString endValue, QString filePath) {
    QFile file(filePath + ".csv");

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        QTextLength length;

        double sc_bytes_sum = 0;
        double cs_bytes_sum = 0;
        int countTrue = 0;
        int v_index = 0;

        for(int i = 0; i < SIZE; i++) {
                 if (attr == 1)  logArray[i].attr = logArray[i].date;
            else if (attr == 2)  logArray[i].attr = logArray[i].time;
            else if (attr == 3)  logArray[i].attr = logArray[i].c_ip;
            else if (attr == 4)  logArray[i].attr = logArray[i].cs_username;
            else if (attr == 5)  logArray[i].attr = logArray[i].cs_host;
            else if (attr == 6)  logArray[i].attr = logArray[i].s_port;
            else if (attr == 7)  logArray[i].attr = logArray[i].cs_method;
            else if (attr == 8)  logArray[i].attr = logArray[i].cs_uri_stem;
            else if (attr == 9)  logArray[i].attr = logArray[i].sc_status;
            else if (attr == 10) logArray[i].attr = logArray[i].sc_win32_stat;
            else if (attr == 11) logArray[i].attr = logArray[i].sc_substatus;
            else if (attr == 12) logArray[i].attr = logArray[i].sc_bytes;
            else if (attr == 13) logArray[i].attr = logArray[i].cs_bytes;
            else if (attr == 14) logArray[i].attr = logArray[i].time_taken;
            else if (attr == 15) logArray[i].attr = logArray[i].x_fullpath;
            else if	(attr == 16) logArray[i].attr = logArray[i].x_debug;
            else if (attr == 17) logArray[i].attr = logArray[i].date;
            else if (attr == 18) logArray[i].attr = logArray[i].time;
            else if (attr == -1) goto output;

        //поиск соответствий в пользовательском запросе и в значениях выбранного поле записи
        if((attr > 0) & (attr < 17)) {
            for(int j = 0; j < logArray[i].attr.length(); j++) {
                if(logArray[i].attr[j] == startValue[v_index]) {
                    countTrue++;
                    v_index++;
                } else {
                    countTrue = 0;
                    v_index = 0;
                }
                if(v_index == startValue.length()) {
                    break;
                }
            }

        //поиск соответствий в пользовательском запросе и в диапазоне указанных дат
        } else if(attr == 17) {
            if(startValue == "") {
                startValue = "0000-00-00";
            }
            if(endValue == "") {
                endValue = "9999-99-99";
            }
            if((logArray[i].attr >= startValue) && (logArray[i].attr <= endValue)) {
                countTrue = startValue.length();
            }

        //поиск соответствий в пользовательском запросе и в диапазоне указанного времени
        } else if (attr == 18) {
            if(startValue == "") {
                startValue = "00:00:00";
            }
            if(endValue == "") {
                endValue = "23:59:59";
            }
            if((logArray[i].attr >= startValue) && (logArray[i].attr <= endValue)) {
                countTrue = startValue.length();
            }
        } else {
            qDebug() << "Will be continued soon...";
        }

        //вывод соответствующих записей в результирующее табличное предаставление
        if (countTrue == startValue.length()) {
output:     stream << logArray[i].date          << "; "
                   << logArray[i].time          << "; "
                   << logArray[i].c_ip          << "; "
                   << logArray[i].cs_username   << "; "
                   << logArray[i].cs_host       << "; "
                   << logArray[i].s_port        << "; "
                   << logArray[i].cs_method     << "; "
                   << logArray[i].cs_uri_stem   << "; "
                   << logArray[i].sc_status     << "; "
                   << logArray[i].sc_win32_stat << "; "
                   << logArray[i].sc_substatus  << "; "
                   << logArray[i].sc_bytes      << "; "
                   << logArray[i].cs_bytes      << "; "
                   << logArray[i].time_taken    << "; "
                   << logArray[i].x_fullpath    << "; "
                   << logArray[i].x_debug       << "; "
                   << Qt::endl;
        } else {
            logArray[i].date          = " "; // logArray[i+1].date;
            logArray[i].time          = " "; // logArray[i+1].time);
            logArray[i].c_ip          = " "; // logArray[i+1].c_ip);
            logArray[i].cs_username   = " "; // logArray[i+1].cs_username);
            logArray[i].cs_host       = " "; // logArray[i+1].cs_host);
            logArray[i].s_port        = " "; // logArray[i+1].s_port);
            logArray[i].cs_method     = " "; // logArray[i+1].cs_method);
            logArray[i].cs_uri_stem   = " "; // logArray[i+1].cs_uri_stem);
            logArray[i].sc_status     = " "; // logArray[i+1].sc_status);
            logArray[i].sc_win32_stat = " "; // logArray[i+1].sc_win32_stat);
            logArray[i].sc_substatus  = " "; // logArray[i+1].sc_substatus);
            logArray[i].sc_bytes      = " "; // logArray[i+1].sc_bytes);
            logArray[i].cs_bytes      = " "; // logArray[i+1].cs_bytes);
            logArray[i].time_taken    = " "; // logArray[i+1].time_taken);
            logArray[i].x_fullpath    = " "; // logArray[i+1].x_fullpath);
            logArray[i].x_debug       = " "; //stream << trimmed();// logArray[i+1].x_debug);*/
        }
        countTrue = 0;
        v_index = 0;

        //расчёт объёма переданных данных
        if (logArray[i].sc_bytes.toDouble() >= 0) {
            sc_bytes_sum += logArray[i].sc_bytes.toDouble();
        }

        //расчёт объёма полученных данных
        if (logArray[i].cs_bytes.toDouble() >= 0) {
            cs_bytes_sum += logArray[i].cs_bytes.toDouble();
        }

        //вывод рассчитанного объёма переданных данный в GUI
        ui->labelSent->setText("Передано:");
        ui->bytesSent->setText(QString::number(sc_bytes_sum, 'f', 1) + " байт");
        ui->kbSent->setText(QString::number(sc_bytes_sum/1024, 'f', 1) + " Кб");
        ui->mbSent->setText(QString::number(sc_bytes_sum/1048576, 'f', 1) + " Мб");
        ui->gbSent->setText(QString::number(sc_bytes_sum/1073741824, 'f', 1) + " Гб");

        //вывод рассчитанного объёма полученных данный в GUI
        ui->labelReceived->setText("Получено:");
        ui->bytesReceived->setText(QString::number(cs_bytes_sum, 'f', 1) + " байт"  );
        ui->kbReceived->setText(QString::number(cs_bytes_sum/1024, 'f', 1) + " Кб");
        ui->mbReceived->setText(QString::number(cs_bytes_sum/1048576, 'f', 1) + " Мб");
        ui->gbReceived->setText(QString::number(cs_bytes_sum/1073741824, 'f', 1) + " Гб");

    }
    sc_bytes_sum = 0;
    cs_bytes_sum = 0;
    startValue = "";
    endValue   = "";
    }
};
