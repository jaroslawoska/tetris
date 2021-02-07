#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <tetrismodel.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<TetrisModel>("TetrisModel", 1, 0, "TetrisModel");
    engine.load(QUrl(QStringLiteral("qrc:/tetris.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
