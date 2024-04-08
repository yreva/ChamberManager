#include "chartutils.h"
#include <QtCharts/QValueAxis>
#include <QFont>

// Function to remove gridlines from a chart
void ChartUtils::removeGridlines(QChart *chart) {
    // Get the axes of the chart
    QList<QAbstractAxis*> axes = chart->axes();

    // Iterate through the axes and disable gridlines
    for (QAbstractAxis* axis : axes) {
        axis->setGridLineVisible(false);
    }
}

void ChartUtils::increaseTickFontSize(QChart *chart, int fs) {
    QList<QAbstractAxis*> axes = chart->axes();
    for (QAbstractAxis* axis : axes) {
        if (axis->type() == QAbstractAxis::AxisTypeValue) {
            QValueAxis *valueAxis = qobject_cast<QValueAxis*>(axis);
            if (valueAxis) {
                QFont font = valueAxis->labelsFont();
                font.setPointSize(fs);
                valueAxis->setLabelsFont(font);
                valueAxis->setTitleFont(QFont("Arial", 12, QFont::Bold));
            }

        }
    }
}

void ChartUtils::adjustPlotMargins(QChart *chart, QChartView *chartView) {
    chart->setMargins(QMargins(0, 0, 0, 0)); // Set chart margins to zero
    chartView->setContentsMargins(0, 0, 0, 0);
    chartView->setStyleSheet("padding:0px; border: none; margin: 0px;");
}


void ChartUtils::setLineStyes(QLineSeries *O3_series, QLineSeries *NOy_series, QLineSeries *NO_series)
{
    QColor O3_color(0, 200, 0); // RGB color; this would be bright red
    QPen O3_pen(O3_color);
    O3_pen.setWidth(2);
    O3_series->setPen(O3_pen);

    QColor NOy_color(140, 70, 70); // RGB color; this would be bright red
    QPen NOy_pen(NOy_color);
    NOy_pen.setWidth(2);
    NOy_series->setPen(NOy_pen);

    QColor NO_color(255, 170, 70); // RGB color; this would be bright red
    QPen NO_pen(NO_color);
    NO_pen.setWidth(2);
    NO_series->setPen(NO_pen);



}
