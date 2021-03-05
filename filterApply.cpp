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
void Logan::filterApply() {

    QString filePath = ui->filePath->text();

    //вызов метода построения таблицы с данными
    dataBuilder(filePath);
}
