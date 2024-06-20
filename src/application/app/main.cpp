#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>
#include <QQmlContext>

#include "planeviewmodel.h"
#include "planeapi.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "rect_cut_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    auto plane = PlanePtr::create(QSizeF{ 500, 500 });

    auto chunk1 = ChunkPtr::create(QSizeF{ 100, 100 });
    auto chunk2 = ChunkPtr::create(QSizeF{ 50, 50 });

    plane->addChunk(chunk1);
    plane->addChunk(chunk2);

    auto planeViewModel = PlaneViewModelPtr::create(plane);
    auto planeAPI = PlaneAPIPtr::create();

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("planeViewModel", planeViewModel.data());
    engine.rootContext()->setContextProperty("planeAPI", planeAPI.data());

    engine.loadFromModule("rect_cut_app", "Main");

    return app.exec();
}
