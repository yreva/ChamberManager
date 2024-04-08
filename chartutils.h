#ifndef CHARTUTILS_H
#define CHARTUTILS_H

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QLineSeries>

class ChartUtils
{
public:
    static void removeGridlines(QChart *chart);
    static void increaseTickFontSize(QChart *chart, int fs);
    static void adjustPlotMargins(QChart *chart, QChartView *chartView);
    static void setLineStyes(QLineSeries *O3_series, QLineSeries *NOy_series, QLineSeries *NO_series);
};

#endif // CHARTUTILS_H
