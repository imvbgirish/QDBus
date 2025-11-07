#ifndef HELLOSERVICE_H
#define HELLOSERVICE_H

#include <QObject>
#include <QDBusConnection>

class HelloService : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.example.MyInterface")
public:
    explicit HelloService(QObject *parent = nullptr);
    bool registerOnDBus(); //Registers the service and object

public slots:
    QString sayHello(const QString &name);

signals:
    void helloSent(const QString &message);
};

#endif // HELLOSERVICE_H
