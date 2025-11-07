#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include "helloservice.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/QDBusServer/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);


    QCoreApplication myApp(argc, argv);

    HelloService service;
    if(!service.registerOnDBus())
        return 1;

    qDebug() << "DBusServer running...";
    return app.exec();
}
