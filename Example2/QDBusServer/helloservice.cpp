#include "helloservice.h"

HelloService::HelloService(QObject *parent)
    : QObject{parent}
{}

bool HelloService::registerOnDBus()
{
    QDBusConnection connection = QDBusConnection::sessionBus();

    if (!connection.registerService("org.example.MyService")) {
        qCritical() << "Failed to register D-Bus service!";
        return false;
    }

    if (!connection.registerObject("/org/example/MyObject", this,
                                   QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals)) {
        qCritical() << "Failed to register D-Bus object!";
        return false;
    }

    qDebug() << "D-Bus service registered successfully!";
    return true;
}

QString HelloService::sayHello(const QString &name)
{
    QString msg = QString("Hello %1 from DBus class").arg(name);
    qDebug() << "sayHello called with:" << name;
    emit helloSent(msg); // broadcast signal
    return msg;
}
