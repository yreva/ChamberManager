#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtCharts>
#include <QVector>
#include "expdetails.h"
#include "ipconnector.h"
#include "datastructures.h"
#include "serialconnector.h"

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
    void addNOyDataPoint(double x, double y1, double y2, double y3);
    void addO3DataPoint(double x, double y);

private slots:
    void updateClock();
    void startExperiment();
    void updateO3Label(const QString &data);
    void updateNOyLabels(const QString &data);
    void updateRHTLabels(const QString &data);
    void simulateDataForTesting();
    void onOpenInputDialog();

signals:
    void O3DataReceived(O3_RowData &data);
    void NOyDataReceived(NOy_RowData &data);
    void RHTDataReceived(NOy_RowData &data);

private:
    Ui::MainWindow *ui;
    Experiment expmt;
    QTimer *clockTimer;
    QTimer *dataTimer;
    QChart *RHT_chart;
    QChart *Gases_chart;
    QChart *NOy_chart;
    QLineSeries *O3_series;
    QLineSeries *NOy_series;
    QLineSeries *NO_series;
    QLineSeries *DIF_series;
    QLineSeries *RHT_series;
    ipDataReceiver *Ozone;
    ipDataReceiver *NOy;
    serialDataReceiver *RHT;
    QString O3_ipAddress = "128.200.47.21";
    QVector<O3_RowData> *O3_log;
    QVector<NOy_RowData> *NOy_log;
    QVector<RHT_RowData> *RHT_log;

    int i = 0;
};
#endif // MAINWINDOW_H
