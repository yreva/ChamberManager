// ipDataReceiver.cpp
#include "ipconnector.h"

ipDataReceiver::ipDataReceiver(const QString &ipAddress, quint16 ipPort, QObject *parent)
    : QObject(parent), m_ipAddress(ipAddress), m_ipPort(ipPort), m_tcpSocket(new QTcpSocket(this))
{
    // Connect to the IP address and port
    m_tcpSocket->connectToHost(ipAddress, ipPort);

    // Connect readyRead() signal of the socket to readData() slot
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &ipDataReceiver::readData);
}

void ipDataReceiver::readData()
{
    if (m_tcpSocket->bytesAvailable() > 0) {
        // Read data from the socket
        QByteArray data = m_tcpSocket->readAll();

        // Emit the dataReceived signal
        emit dataReceived(QString::fromUtf8(data));
    }
}
