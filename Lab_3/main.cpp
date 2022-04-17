#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <cafelist.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    CafeList viewModel;

    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();    //получаем корневой контекст модели
    context->setContextObject(&viewModel);          //устанавливаем в качестве корневой модели созданную модель
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
