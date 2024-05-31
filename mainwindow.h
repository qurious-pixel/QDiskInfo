#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QButtonGroup>
#include <QAction>
#include <cmath>

#include "statusdot.h"
#include "custombutton.h"
#include "./ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QButtonGroup *buttonGroup;
    QHBoxLayout *horizontalLayout;
    QLabel *diskName, *temperatureValue, *healthStatusValue;
    QLineEdit *firmwareLineEdit, *serialNumberLineEdit, *typeLineEdit, *protocolLineEdit, *deviceNodeLineEdit;
    QLineEdit *totalReadsLineEdit, *totalWritesLineEdit, *rotationRateLineEdit, *powerOnCountLineEdit, *powerOnHoursLineEdit;
    QTableWidget *tableWidget;

    void scanDevices();
    void populateWindow(const QJsonObject &tempObj, const QString &health);
    void addSmartAttributesTable(const QJsonArray &attributes);
    QString getSmartctlOutput(const QStringList &arguments, bool root);
};
#endif
