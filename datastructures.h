#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
#include <QString>
#include <QDateTime>

struct O3_RowData {
    QDateTime time;  // Assuming time remains as a string
    float O3;
};

struct NOy_RowData {
    QDateTime time;  // Assuming time remains as a string
    float NO;
    float NOy;
    float DIF;
};

struct RHT_RowData {
    QDateTime time;  // Assuming time remains as a string
    float RH;
    float Celsius;
};

#endif // DATASTRUCTURES_H
