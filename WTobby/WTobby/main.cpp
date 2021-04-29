#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringList>
#include <QList>
#include "DataModel/LogDataObject.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    /* Data Models */
    QList<QObject*> dataList = {
        new LogDataObject("atype","amessage"),
        new LogDataObject("btype","bmessage"),
        new LogDataObject("ctype","cmessage") };
    engine.rootContext()->setContextProperty("logModel", QVariant::fromValue(dataList));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
