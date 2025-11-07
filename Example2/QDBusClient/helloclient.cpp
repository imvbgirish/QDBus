#include "helloclient.h"
#include <QDebug>

HelloClient::HelloClient(QObject *parent)
    : QObject{parent}
{
    m_iface = new QDBusInterface("org.example.MyService",
                                 "/org/example/MyObject",
                                 "org.example.MyInterface",
                                 QDBusConnection::sessionBus(),
                                 this);

    if (!m_iface->isValid()) {
        qCritical() << "Failed to connect to D-Bus service!";
    } else {
        qDebug() << "Connected to org.example.MyService";
    }
}

bool HelloClient::connectToSignal()
{
    // Classic Qt connection for D-Bus signal -> local slot
    bool ok = QDBusConnection::sessionBus().connect(
        "org.example.MyService",
        "/org/example/MyObject",
        "org.example.MyInterface",
        "helloSent",
        this,
        SLOT(onHelloReceived(QString)));    // slot declared above

    if (!ok)
        qCritical() << "Failed to connect to D-Bus signal!";
    else
        qDebug() << "Connected to D-Bus signal helloSent";

    return ok;
}

void HelloClient::callSayHello(const QString &name)
{
    if (!m_iface->isValid())
        return;

    // Asynchronous D-Bus call
    QDBusPendingCall pending = m_iface->asyncCall("sayHello", name);
    auto *watcher = new QDBusPendingCallWatcher(pending, this);

    // Optional timeout check (5 s)
    QTimer::singleShot(5000, this, [watcher]() {
        if (!watcher->isFinished())
            qWarning() << "Timeout waiting for reply!";
    });

    connect(watcher, &QDBusPendingCallWatcher::finished,
            this, [this, watcher]() { onCallFinished(watcher); });
}

void HelloClient::onCallFinished(QDBusPendingCallWatcher *watcher)
{
    QDBusPendingReply<QString> reply = *watcher;
    if (reply.isValid())
        qDebug() << "Async reply received:" << reply.value();
    else
        qWarning() << "Async call failed:" << reply.error().message();

    watcher->deleteLater();
}

void HelloClient::onHelloReceived(const QString &message)
{
    qDebug() << "Received D-Bus signal:" << message;
}
