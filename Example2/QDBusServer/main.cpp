#include <QCoreApplication>
#include "helloservice.h"

int main(int argc, char *argv[])
{

    QCoreApplication myApp(argc, argv);

    HelloService service;
    if(!service.registerOnDBus())
        return 1;

    qDebug() << "DBusServer running...";
    return myApp.exec();
}
