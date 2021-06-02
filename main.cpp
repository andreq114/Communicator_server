#include "HEAD/SERVER/server.h"
#include "HEAD/conf_define.h"


using namespace std;
void delayms( int millisecondsToWait );

int main(int argc, char *argv[])
    {
    QCoreApplication a(argc, argv);
    Server server(PORT);
    return a.exec();
}


