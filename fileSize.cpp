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

//метод расчёта количества записей в журнале логов
int Logan::fileSize(QString filePath) {
    QFile file(filePath);
    int rowCounter = 0;

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 1;
    }

    while(!file.atEnd()) {
        QString line = file.readLine();
        if (line.startsWith("2")) {
            rowCounter++;
        }
    }

    file.close();
    return rowCounter;
}
