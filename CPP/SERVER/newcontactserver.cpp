#include "HEAD/SERVER/newcontactserver.h"

NewContactServer::NewContactServer(qintptr ID, QObject *parent) : QThread(parent)
{
        this->socketDescriptor = ID;
        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName(DATABASE_PATH);
        this->conveterQuery = new ConveterData(database, ID);
}

void NewContactServer::run()
{
    qDebug() << " Thread started" << endl;

    socket = new QTcpSocket();

    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(disconnected()), conveterQuery, SLOT(disconnected()));


    qDebug() << socketDescriptor << " Client connected" << endl;

    exec();
}

void NewContactServer::readyRead()
{
    connect(conveterQuery, SIGNAL (readyToSend(QByteArray)), this, SLOT(writeToSocket(QByteArray)), Qt::DirectConnection);
    QByteArray becameData = socket->readAll();
    qDebug() << socketDescriptor << "Arrived data=" << endl;
    qDebug() << becameData << endl;
    conveterQuery->exec(becameData);
}

void NewContactServer::writeToSocket(QByteArray dataToSend)
{
    socket->write(dataToSend);
    socket->flush();
}

void NewContactServer::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected" << endl;
    socket->deleteLater();
    exit(0);
}
