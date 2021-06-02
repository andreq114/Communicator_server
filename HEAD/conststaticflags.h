#ifndef CONSTSTATICFLAGS_H
#define CONSTSTATICFLAGS_H
#include <QString>

namespace FLAG{

//TCP HEADERS

static const QString C_LOGIN    = "C_LOGIN";
static const QString S_LOGIN    = "S_LOGIN";
static const QString C_SEND     = "C_SEND";
static const QString S_SEND     = "S_SEND";
static const QString S_ULIST    = "S_ULIST";
static const QString C_ULIST    = "C_ULIST";
static const QString C_MESSAGES = "C_REQUEST";
static const QString S_MESSAGES = "S_REQUEST";


//TCP FLAGS

static const QString ACT = "ACT";
static const QString ERR = "ERR";

//DATABASE FLAGS

static const QString FORMAT_DATA = "yyyy-MM-dd hh:mm:ss";

//DEBUG FLAGS

static const QString ERROR = "Error: ";
static const QString NEW_LINE = "\r\n";
}
#endif // CONSTSTATICFLAGS_H
