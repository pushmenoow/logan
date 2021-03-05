#include "logan.h"
#include "logFile.h"

#include <QApplication>
#include <QMessageBox>

//точка входа в программу
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Logan w;

    //отображение главного окна программы
    w.show();
    return a.exec();
}
