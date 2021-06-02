#ifndef DATABASERESPONSE_H
#define DATABASERESPONSE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QtSql>
#include <QDebug>
#include <QMap>

#include "HEAD/conststaticflags.h"

//Class executes a request to database and return the result.


class ConveterData : public QObject
{
    Q_OBJECT
public:
    ConveterData(QSqlDatabase database, qintptr ID);
    ~ConveterData();
signals:
    void readyToSend(QByteArray);
public slots:
    void exec(QByteArray);
    void disconnected();
private:
    // Confirming method sends a status of request. (Execute positive or negative)
    void C_Confirm(QString);


    void C_LOGIN_DbRequest(QByteArray nick, QByteArray password);
    void C_LOGIN_decoding(QByteArray);

    void C_SEND_DbRequest(QByteArray nick, QByteArray message);
    void C_SEND_decoding(QByteArray);

    QMap<int,QString> C_ULIST_DbRequest();
    void C_ULIST_coding(QMap<int,QString>);

    void C_MESSAGES_decoding(QByteArray);
    void C_MESSAGES_DbRequest(QByteArray nick);
    void C_MESSAGES_coding(QByteArray sender, QByteArray message, QByteArray date);
    QByteArray getHeader(QByteArray);

    bool _result;
    int _idUser;
    QSqlQuery request;
    QSqlDatabase database;
};

#endif // HEAD\DATABASE\DATABASERESPONSE_H
