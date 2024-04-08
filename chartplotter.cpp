#include "chartplotter.h"
#include "datastructures.h"

ChartPlotter::ChartPlotter(QChart *chart, QObject *parent)
    : QObject(parent) {
    series = new QLineSeries();
    chart->addSeries(series);

    axisX = new QValueAxis;
    axisY = new QValueAxis;
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
}

void ChartPlotter::addO3Data(O3_RowData &row) {
    const QDateTime x = QDateTime::currentDateTime();
    const float y = row.O3;
    series->append(x.toMSecsSinceEpoch(), y);

    // Adjust axis ranges if needed
    //if (x.toMSecsSinceEpoch() > axisX->max()) {
    //    axisX->setRange(x.addSecs(-3600).toMSecsSinceEpoch(), x.addSecs(3600).toMSecsSinceEpoch()); // Adjust range dynamically
    //}
    //if (y > axisY->max()) {
    //    axisY->setRange(0, y + 10); // Adjust range dynamically
    //}
}

void ChartPlotter::addNOyData(NOy_RowData &row) {
    QDateTime x = QDateTime::currentDateTime();
    const float y1 = row.NO;
    const float y2 = row.NOy;
    const float y3 = row.DIF;
    series->append(x.toMSecsSinceEpoch(), y1);
    series->append(x.toMSecsSinceEpoch(), y2);
    series->append(x.toMSecsSinceEpoch(), y3);


    // Adjust axis ranges if needed
    //if (x > axisX->max()) {
    //    axisX->setRange(x.addSecs(-3600), x.addSecs(3600)); // Adjust range dynamically
    //}
    //if (y1 > axisY->max()) {
    //    axisY->setRange(0, y1 + 10); // Adjust range dynamically
    //}
}
