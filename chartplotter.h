#ifndef CHARTPLOTTER_H
#define CHARTPLOTTER_H

#include <QObject>
#include <QtCharts>
#include <QTimer>
#include "datastructures.h"

class ChartPlotter : public QObject {
    Q_OBJECT
public:
    explicit ChartPlotter(QChart *chart, QObject *parent = nullptr);
    void addO3Data(O3_RowData &row);
    void addNOyData(NOy_RowData &row);

private:
    QLineSeries *series;
    QValueAxis *axisX;
    QValueAxis *axisY;
};

#endif // CHARTPLOTTER_H
