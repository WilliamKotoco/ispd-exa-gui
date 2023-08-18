#pragma once
#include "icon/pixmappair.h"

class PixmapIcon;
class Connectable;

class PixmapIconBuilder
{
public:
    PixmapIconBuilder();

    PixmapIconBuilder *setOwner(Connectable *item);
    PixmapIconBuilder *setPixmapPair(PixmapPair pixmapPair);

    PixmapIcon *build();

private:
    Connectable *owner;
    PixmapPair *pixmapPair;
};
