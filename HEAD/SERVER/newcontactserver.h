#ifndef NEWCONTACTSERVER_H
#define NEWCONTACTSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QSqlDatabase>
#include "HEAD/DATABASE/conveterdata.h"
#include "HEAD/conf_define.h"

//Class operates one new client, receives request and send response.

class NewContactServer : public QThread
{
    Q_OBJECT
public:
    explicit NewContactServer(qintptr ID, QObject *parent);
    void run();
signals:
    void error(QTcpSocket::SocketError socketerror);
public slots:
    void readyRead();
    void disconnected();
    void writeToSocket(QByteArray);
private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
    ConveterData *conveterQuery;
};

#endif // NEWCONTACTSERVER_H
