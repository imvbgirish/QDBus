#include <QCoreApplication>
#include <QDBusInterface>
#include <QDBusReply>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QDBusInterface iface("org.example.MyService",
                         "/org/example/MyObject",
                         "org.example.MyInterface",
                         QDBusConnection::sessionBus());

    if (!iface.isValid()) {
        qDebug() << "Failed to connect to service!";
        return 1;
    }

    QDBusReply<QString> reply = iface.call("sayHello", "Girish");

    if (reply.isValid())
        qDebug() << "Reply:" << reply.value();
    else
        qDebug() << "Call failed:" << reply.error().message();

    return 0;
}
