#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDebug>
#include <QObject>

class MyService : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.example.MyInterface")

public slots:
    QString sayHello(const QString &name) {
        QString msg = QString("Hello %1 from QDBus!").arg(name);
        qDebug() << "Received sayHello:" << msg;
        return msg;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    MyService service;
    QDBusConnection connection = QDBusConnection::sessionBus();

    if (!connection.registerService("org.example.MyService")) {
        qFatal("Could not register service on D-Bus");
        return 1;
    }

    if (!connection.registerObject("/org/example/MyObject", &service, QDBusConnection::ExportAllSlots)) {
        qFatal("Could not register object on D-Bus");
        return 1;
    }

    qDebug() << "Service running...";
    return app.exec();
}

#include "server.moc"

