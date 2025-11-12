#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QtDBus/QDBusConnection"
#include "calculator_proxy.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    auto connection = QDBusConnection::sessionBus();
    ComExampleCalculatorInterface proxy("com.example.calculator","/Calculator",connection,nullptr);
    int result =proxy.add();
    qDebug()<<"result ="<<result;
    QQmlApplicationEngine engine;
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
