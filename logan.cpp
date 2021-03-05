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
#include <QMessageBox>

//метод построения и вывода графического пользовательского интерфейса на экран
Logan::Logan(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Logan) {
    QWidget::setFixedSize(1255, 790);
    ui->setupUi(this);
    csvModel = new QStandardItemModel(this);
    ui->tableView->setModel(csvModel);

    //установка связи между сигналом открытия файла и соответствующим методом
    connect(ui->openFile, SIGNAL(clicked()), this, SLOT(openFile()));

    //установка связи между сигналом применения фильтров и соответствующим методом
    connect(ui->filterApply, SIGNAL(clicked()), this, SLOT(filterApply()));
}

//деструктор графического пользовательского интерфейса и модели представления данных
Logan::~Logan() {
    delete ui;
    delete csvModel;
}


