#ifndef IPCONNECTOR_H
#define IPCONNECTOR_H

#pragma once
#include <QObject>
#include <QTcpSocket>

class ipDataReceiver : public QObject
{
    Q_OBJECT

public:
    explicit ipDataReceiver(const QString &ipAddress, quint16 ipPort, QObject *parent = nullptr);

public slots:
    void readData();

signals:
    void dataReceived(const QString &data);

private:
    QString m_ipAddress;
    quint16 m_ipPort;
    QTcpSocket *m_tcpSocket;
};



#endif // IPCONNECTOR_H
