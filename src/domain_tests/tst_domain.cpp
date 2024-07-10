#include <QtTest>

// add necessary includes here

#include "plane.h"
#include "chunkmanager.h"

class Domain : public QObject
{
    Q_OBJECT

public:
    Domain();
    ~Domain();

private slots:
    
    void chunkManagerEasyCase1();
};

Domain::Domain() {}

Domain::~Domain() {}

void Domain::chunkManagerEasyCase1() {
    auto plane = PlanePtr::create(QSizeF{ 100, 100 });
    auto chunkManager = ChunkManagerPtr::create();
    auto chunkTemplates = QList<ChunkTemplate> {
        { QSize{ 1, 1 }, 1, QColor{ "black" } },
    };
    
    auto [isOk, err] = chunkManager->calculate(plane, QSizeF{ 1, 1 }, chunkTemplates);
    
    for (const auto &chunk : plane->chunks()) {
        qDebug() << chunk->rect();
    }
    
}

QTEST_APPLESS_MAIN(Domain)

#include "tst_domain.moc"
