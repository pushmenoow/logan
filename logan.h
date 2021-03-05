#ifndef LOGAN_H
#define LOGAN_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Logan; }
QT_END_NAMESPACE

class Logan : public QMainWindow
{
    Q_OBJECT

public:
    Logan(QWidget *parent = nullptr);
    ~Logan();

private slots:
     int fileSize(QString filePath);
    void openFile();
    void filterApply();
    void logInit(struct logFile *logArray, int SIZE);
    void logRead(struct logFile *logArray, QString filePath);
    void logSearch(struct logFile *logArray, int SIZE, int attr, QString startValue, QString endValue, QString filePath);
    void menu(struct logFile *logArray, int SIZE, QString filePath);
    void about();
 QString dataBuilder(QString filePath);

private:
    Ui::Logan *ui;
    QStandardItemModel *csvModel;
};
#endif // LOGAN_H
