#ifndef SERVER_H
#define SERVER_H

#include <QCoreApplication>
#include <QNetworkInterface>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>

#include <iostream>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(quint16 port=50000, QObject *parent = nullptr);
    ~Server();
    QTcpSocket *socket ;
    void startServer();
    void incomingConnection(qintptr socketDescriptor);
public slots:
signals:
};

#endif // SERVER_H
