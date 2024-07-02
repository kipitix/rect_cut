#include "planeapi.h"

PlaneAPI::PlaneAPI(const PlanePtr &plane, const ChunkManagerPtr &chunkManager, const PlaneViewModelPtr &planeViewModel)
    : QObject{ nullptr }
    , _plane{ plane }
    , _chunkManager{ chunkManager }
    , _planeViewModel{ planeViewModel }
{}

bool PlaneAPI::calculate(double planeWidth, double planeHeight, const QVariantList &chunkTemplates)
{
    QList<ChunkTemplate> chunkTemplateList{ chunkTemplates.length() };
    for (auto i = 0; i < chunkTemplates.length(); i ++) {
        auto input = chunkTemplates[i].toMap();
        chunkTemplateList[i] = ChunkTemplate {
            QSizeF{ input.value("width").toDouble(), input.value("height").toDouble() },
            input.value("count").toInt(),
            input.value("color").toString()
        };
    }
    
    _chunkManager->calculate(_plane, QSizeF{ planeWidth, planeHeight }, chunkTemplateList);
    
    _planeViewModel->refresh();
    return true;
}
