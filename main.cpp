#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include "huggingfaceapi.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Register the HuggingFaceAPI type so that it can be used in QML.
    qmlRegisterType<HuggingFaceAPI>("MyAPI", 1, 0, "HuggingFaceAPI");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/HuggingFaceAPITest/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
