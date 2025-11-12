#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "QtDBus/QtDBus"

class DBusCaller : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE int callAdd(int a, int b) {
        QDBusInterface iface("org.example.Calculator",
                             "/Calculator",
                             "org.example.Calculator",
                             QDBusConnection::sessionBus());
        QDBusReply<int> reply = iface.call("add", a, b);
        if (reply.isValid()) {
            qDebug() << "Client: D-Bus call result =" << reply.value();
            return reply.value();
        } else {
            qDebug() << "Client: D-Bus error:" << reply.error().message();
            return -1;
        }
    }
};

#include "main.moc"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    DBusCaller caller;
    engine.rootContext()->setContextProperty("dbusCaller", &caller);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
