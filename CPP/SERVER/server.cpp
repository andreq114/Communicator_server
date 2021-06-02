
#include "HEAD/SERVER/server.h"
#include "HEAD/SERVER/newcontactserver.h"
#include "HEAD/conf_define.h"

using namespace std;

Server::Server(quint16 port, QObject *parent) : QTcpServer(parent)
{
    if(!this->listen(QHostAddress::Any,port))qDebug() << "\nWeb server could not start";
    else qDebug() <<"\nServer is waiting for a connection on port " << port << "\r\n";
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...\r\n";

    NewContactServer *thread = new NewContactServer(socketDescriptor, this);

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

Server::~Server()
    {
    socket->close();
}
