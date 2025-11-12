#include "Calculator.h"
#include "calculator_adaptor.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QtDBus/QDBusConnection"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Calculator calculator;
    CalculatorAdaptor adopter(&calculator);

    auto connection = QDBusConnection::sessionBus();
    if (!connection.registerService("com.example.calculator")) {
        qDebug() << "Not Able to register the service:" << connection.lastError().message();
        return -1;
    } else {
        qDebug() << "Able to register the service";
    }

    if (!connection.registerObject("/Calculator",&calculator)) {
        qDebug() << "Not Able to register the service:" << connection.lastError().message();
        return -1;
    } else {
        qDebug() << "Able to register the service";
    }
    const QUrl url(QStringLiteral("qrc:/main.qml"));
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
