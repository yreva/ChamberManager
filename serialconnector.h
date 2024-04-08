#ifndef SERIALCONNECTOR_H
#define SERIALCONNECTOR_H

#include <QSerialPort>
#include <QSerialPortInfo>

class serialDataReceiver : public QObject
{
    Q_OBJECT

public:
    explicit serialDataReceiver(const QString &comPort, QObject *parent = nullptr);
    virtual ~serialDataReceiver();

public slots:
    void readData();

signals:
    void dataReceived(const QString &data);

private:
    QString m_comPort;
    QSerialPort *m_serial;
};



#endif // SERIALCONNECTOR_H
