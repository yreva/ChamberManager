#include "serialconnector.h"
#include <QDebug>
#include <iostream>
#include <string>


serialDataReceiver::~serialDataReceiver()
{
    if (m_serial->isOpen())
        m_serial->close();
}


serialDataReceiver::serialDataReceiver(const QString &comPort, QObject *parent)
    : QObject(parent), m_comPort(comPort), m_serial(new QSerialPort(this))
{
    m_serial->setPortName(m_comPort);
    m_serial->setBaudRate(QSerialPort::Baud4800);
    m_serial->setDataBits(QSerialPort::Data7);
    m_serial->setParity(QSerialPort::EvenParity);
    m_serial->setStopBits(QSerialPort::OneStop);

    //std::cout << "Attempted to set serial settings" << std::endl;

    if (!m_serial->open(QIODevice::ReadOnly)) {
        // Handle error
        qDebug() << "Failed to open port" << comPort << ", error:" << m_serial->errorString();
        return;
    }

    connect(m_serial, &QSerialPort::readyRead, this, &serialDataReceiver::readData);
}

void serialDataReceiver::readData()
{
    m_serial->readLine();
    QByteArray data = m_serial->readLine();
    std::string output = QString::fromUtf8(data).toStdString();
    std::cout << output << std::endl;
    emit dataReceived(QString::fromUtf8(data));
}
