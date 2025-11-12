#include <QCoreApplication>
#include <QtDBus/QtDBus>
#include "Calculator.h"
#include "calculator_adaptor.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Calculator calc;
    new CalculatorAdaptor(&calc);

    QDBusConnection conn = QDBusConnection::sessionBus();
    if (!conn.registerService("org.example.Calculator"))
        qFatal("Failed to register D-Bus service");

    conn.registerObject("/Calculator", &calc);

    qDebug() << "DBusServer running... org.example.Calculator registered.";
    return app.exec();
}
