#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "expdetails.h"
//#include "ipconnector.h"
//#include "chartplotter.h"
#include "datastructures.h"
//#include "serialconnector.h"
#include "inputdialog.h"
#include "chartutils.h"

#include <QDateTime>
#include <QtCharts>
#include <QPushButton>
#include <QString>
#include <QRegularExpression>
#include <QVector>
#include <QAction>
#include <QDialog>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QPen>

#include <string>
#include <iostream>
#include <cmath>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    //Ozone(new ipDataReceiver(O3_ipAddress,9881,this)),
    //NOy(new ipDataReceiver("128.200.47.21",9881,this)),
    //RHT(new serialDataReceiver("COM4",this)),
    O3_log(new QVector<O3_RowData>),
    NOy_log(new QVector<NOy_RowData>),
    RHT_log(new QVector<RHT_RowData>)
{
    ui->setupUi(this);

    connect(ui->actionO3_IP_Address, &QAction::triggered, this, &MainWindow::onOpenInputDialog);

    // Connect start button to start experiment function
    connect(ui->startExperiment_button, &QPushButton::clicked, this, &MainWindow::startExperiment);


    // Create timer for displayed Clock
    clockTimer = new QTimer(this);
    connect(clockTimer, SIGNAL(timeout()), this, SLOT(updateClock()));
    clockTimer->start(1000); // Update every 1000 milliseconds (1 second)

    //connect(Ozone, &ipDataReceiver::dataReceived, this, &MainWindow::updateO3Label);
    //connect(NOy, &ipDataReceiver::dataReceived, this, &MainWindow::updateNOyLabels);
    //connect(RHT, &serialDataReceiver::dataReceived, this, &MainWindow::updateRHTLabels);


    Gases_chart = new QChart();
    O3_series = new QLineSeries();
    NOy_series = new QLineSeries();
    NO_series = new QLineSeries();
    //DIF_series = new QLineSeries();

    Gases_chart->addSeries(O3_series);
    Gases_chart->addSeries(NOy_series);
    Gases_chart->addSeries(NO_series);
    //Gases_chart->addSeries(DIF_series);

    // Create the first Y axis
    QValueAxis *axisY1 = new QValueAxis;
    axisY1->setLabelFormat("%i");
    axisY1->setTitleText("Ozone (ppb)");
    Gases_chart->addAxis(axisY1, Qt::AlignLeft);
    O3_series->attachAxis(axisY1);
    O3_series->setName("Ozone");

    // Create the second Y axis
    QValueAxis *axisY2 = new QValueAxis;
    axisY2->setLabelFormat("%i");
    axisY2->setTitleText("NOy (ppb)");
    Gases_chart->addAxis(axisY2, Qt::AlignRight);
    NOy_series->attachAxis(axisY2);
    NOy_series->setName("NOy");
    NO_series->attachAxis(axisY2);
    NO_series->setName("NO");

    // Optionally, setup the X axis as well
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Scan #");
    Gases_chart->addAxis(axisX, Qt::AlignBottom);
    O3_series->attachAxis(axisX);
    NOy_series->attachAxis(axisX);
    NO_series->attachAxis(axisX);

    ui->Gases_ChartView->setChart(Gases_chart);

    ChartUtils::adjustPlotMargins(Gases_chart,ui->Gases_ChartView);
    ChartUtils::removeGridlines(Gases_chart);
    ChartUtils::increaseTickFontSize(Gases_chart, 12); // Change 12 to desired font size
    ChartUtils::setLineStyes(O3_series,NOy_series,NO_series);


    // Create timer for simulating Data
    dataTimer = new QTimer(this);
    connect(dataTimer, SIGNAL(timeout()), this, SLOT(simulateDataForTesting()));
    dataTimer->start(500); // Update every 1000 milliseconds (1 second)


    // Connect fetchData signal to addData slot
    //connect(this, &MainWindow::O3DataReceived, this, &MainWindow::updateO3Plot);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startExperiment()
{
    std::string username = ui->instrumentUser->text().toStdString();
    std::string experimentTitle = ui->experimentName->text().toStdString();
    std::string expFolder = expmt.start_experiment(username,experimentTitle);
}

void MainWindow::updateClock()
{
    // Update the clock display with current date and time
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentTime =  QString::asprintf("%02d:%02d:%02d", currentDateTime.time().hour(), currentDateTime.time().minute(), currentDateTime.time().second());
    ui->lcdClock->display(currentTime);
}


void MainWindow::updateO3Label(const QString &data)
{
    static QRegularExpression str = QRegularExpression("\\s+");
    // Update the label with received data
    QStringList O3_outputStr = data.split(str);
    QString O3_valueStr = O3_outputStr[3];
    ui->O3_label->setText(O3_valueStr);

    O3_RowData row;
    row.time = QDateTime::currentDateTime();
    row.O3 = O3_valueStr.toFloat();

    O3_log->append(row);

    emit O3DataReceived(row);
}

void MainWindow::updateNOyLabels(const QString &data)
{
    // Update the label with received data
    QStringList NOy_outputStr = data.split(QRegularExpression("\\s+"));
    QString NO_valueStr = NOy_outputStr[3];
    QString DIF_valueStr = NOy_outputStr[4];
    QString NOy_valueStr = NOy_outputStr[5];
    ui->NO_label->setText(NO_valueStr);
    ui->DIFF_label->setText(DIF_valueStr);
    ui->NOy_label->setText(NOy_valueStr);

    NOy_RowData row;
    row.time = QDateTime::currentDateTime();
    row.NO = NO_valueStr.toFloat();
    row.NOy = NOy_valueStr.toFloat();
    row.DIF = DIF_valueStr.toFloat();

    NOy_log->append(row);


}


void MainWindow::updateRHTLabels(const QString &data)
{
    // Update the label with received data
    QStringList RHT_outputStr = data.split(QRegularExpression("\\s+"));
    QString RH_valueStr = RHT_outputStr[1];
    QString Celsius_valueStr = RHT_outputStr[4];
    ui->RH_label->setText(RH_valueStr);
    ui->T_label->setText(Celsius_valueStr);

    std::cout << "Labels should have updated" << std::endl;

    RHT_RowData row;
    row.time = QDateTime::currentDateTime();
    row.RH = RH_valueStr.toFloat();
    row.Celsius = Celsius_valueStr.toFloat();

    RHT_log->append(row);
}




// Function to add new data points to the chart
void MainWindow::addNOyDataPoint(double x, double y1, double y2, double y3)
{
    // Access the existing series object
    QLineSeries *series1 = qobject_cast<QLineSeries*>(ui->Gases_ChartView->chart()->series().at(1));
    if (series1) {
        series1->append(x, y1);
    }
    QLineSeries *seriesB = qobject_cast<QLineSeries*>(ui->Gases_ChartView->chart()->series().at(2));
    if (seriesB) {
        seriesB->append(x, y2);
    }

    // Access the existing horizontal axis object
    QValueAxis *xAxis = qobject_cast<QValueAxis*>(ui->Gases_ChartView->chart()->axes(Qt::Horizontal).first());
    if (xAxis) {
        // Calculate new minimum and maximum values for x coordinate
        double minX = std::min(xAxis->min(), x);
        double maxX = std::max(xAxis->max(), x);
        // Set the new range for the horizontal axis
        xAxis->setRange(minX, maxX+1);
    }

    // Access the existing vertical axis object
    QValueAxis *yAxis = qobject_cast<QValueAxis*>(ui->Gases_ChartView->chart()->axes(Qt::Vertical).at(1));
    if (yAxis) {
        // Calculate new minimum and maximum values for y coordinate
        double maxY = std::max(40.0, std::max(yAxis->max(), y2));
        // Set the new range for the vertical axis
        yAxis->setRange(0, maxY);
    }
}

// Function to add new data points to the chart
void MainWindow::addO3DataPoint(double x, double y)
{
    // Access the existing series object
    QLineSeries *series = qobject_cast<QLineSeries*>(ui->Gases_ChartView->chart()->series().at(0));
    if (series) {
        series->append(x, y);

        // Access the existing horizontal axis object
        QValueAxis *xAxis = qobject_cast<QValueAxis*>(ui->Gases_ChartView->chart()->axes(Qt::Horizontal).first());
        if (xAxis) {
            // Calculate new minimum and maximum values for x coordinate
            //double minX = std::min(xAxis->min(), x);
            double maxX = std::max(xAxis->max(), x);
            // Set the new range for the horizontal axis
            xAxis->setRange(0, maxX);
        }

        // Access the existing vertical axis object
        QValueAxis *yAxis = qobject_cast<QValueAxis*>(ui->Gases_ChartView->chart()->axes(Qt::Vertical).at(0));
        if (yAxis) {
            // Calculate new minimum and maximum values for y coordinate
            //double minY = std::min(yAxis->min(), y);
            double maxY = std::max(40.0, std::max(yAxis->max(), y));
            // Set the new range for the vertical axis
            yAxis->setRange(0, maxY);
        }
    }
}

void MainWindow::simulateDataForTesting()
{
    QLineSeries *series1 = qobject_cast<QLineSeries*>(ui->Gases_ChartView->chart()->series().at(1));

    double nMeasurements = series1->count();

    double randomNumber1 = QRandomGenerator::global()->bounded(15, 18);
    double randomNumber2 = QRandomGenerator::global()->bounded(1, 2);
    double randomNumber3 = QRandomGenerator::global()->bounded(1, 5);

    if (nMeasurements > 15.0) {
        randomNumber3 = QRandomGenerator::global()->bounded(300, 310);
    }

    if (nMeasurements > 40.0) {
            randomNumber1 = QRandomGenerator::global()->bounded(900, 950);
            randomNumber2 = randomNumber3 * (1-exp(-nMeasurements/120.0));
            randomNumber3 = randomNumber3 * exp(-nMeasurements/120.0);
    }

    addO3DataPoint(nMeasurements,randomNumber1);
    addNOyDataPoint(nMeasurements,randomNumber2,randomNumber3,0.33);

    ui->NO_label->setText(QString::number(randomNumber3));
    ui->O3_label->setText(QString::number(randomNumber1));
    ui->NOy_label->setText(QString::number(randomNumber2));
}

void MainWindow::onOpenInputDialog() {
    InputDialog *dialog = new InputDialog(this);
    if (dialog->exec() == QDialog::Accepted) {
        QString userInput = dialog->getText();
        O3_ipAddress = userInput;
    }
    // The dialog is automatically deleted when it goes out of scope
}
