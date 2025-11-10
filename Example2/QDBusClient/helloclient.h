#ifndef HELLOCLIENT_H
#define HELLOCLIENT_H

#include <QObject>
#include <QDBusInterface>
#include <QDBusConnection>
#include <QDBusPendingCallWatcher>
#include <QDBusPendingReply>
#include <QTimer>

class HelloClient : public QObject
{
    Q_OBJECT
public:
    explicit HelloClient(QObject *parent = nullptr);

    Q_INVOKABLE void callSayHello(const QString &name);
    Q_INVOKABLE bool connectToSignal();

signals:
    void helloReceived(const QString &message);

private slots:
    void onHelloReceived(const QString &message);
    void onCallFinished(QDBusPendingCallWatcher *watcher);

private:
    QDBusInterface *m_iface = nullptr;
};

#endif // HELLOCLIENT_H
