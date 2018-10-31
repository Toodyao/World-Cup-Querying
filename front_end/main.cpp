#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QDateTime>

#include "backendqml.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<BackEndQml>("BackEndQml", 1, 0, "BackEndQml");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
