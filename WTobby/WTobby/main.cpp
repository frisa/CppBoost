#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringList>
#include <QList>
#include <QVariant>
#include <QThread>

#include "DataModel/LogDataObject.h"
#include "DataModel/LogExModel.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    /* Data Models */
    LogExModel* logModel = new LogExModel();
    logModel->addMessage("A", "A1");
    logModel->addMessage("B", "B1");
    logModel->addMessage("C", "C1");
    engine.rootContext()->setContextProperty("logModel", logModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
