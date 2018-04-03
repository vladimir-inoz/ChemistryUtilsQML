#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>

#include "backend.h"
#include "datasource.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");

    QQmlApplicationEngine engine;

    DataSource dataSource;
    engine.rootContext()->setContextProperty("dataSource", &dataSource);
    BackEnd backEnd;
    engine.rootContext()->setContextProperty("backend", &backEnd);
    QObject::connect(&backEnd, &BackEnd::chartReady,
                     &dataSource, &DataSource::setData);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
