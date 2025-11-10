#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "helloclient.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Register HelloClient as a QML type
    qmlRegisterType<HelloClient>("QDBus", 1, 0, "HelloClient");

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/QDBusClient/main.qml"));
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

    return app.exec();
}
