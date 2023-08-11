#include "components/link.h"
#include "components/connection.h"
#include "components/item.h"
#include "icon/icon.h"
#include "icon/linkicon.h"
#include "qdebug.h"
#include <iterator>
#include <memory>

Link::Link(Schema         *schema,
           unsigned        id,
           const char     *name,
           LinkConnections connections)
{
    this->id          = id;
    this->connections = connections;
    this->schema      = schema;
    this->name        = name;
    qDebug() << "BEFORE MAKING UNIQUE ICON OF LINK";
    this->icon        = std::make_unique<LinkIcon>(this);
    qDebug() << "AFTER MAKING UNIQUE ICON OF LINK";
}

Link::~Link()
{
    qDebug() << "Deleting " << this->name.c_str();
}

void Link::addLine()
{
    this->connections.begin->getConnectedLinks()->insert(
        std::pair(this->id, this));
    this->connections.end->getConnectedLinks()->insert(
        std::pair(this->id, this));

    this->icon->draw();
}

void Link::showConfiguration() {
    // TODO IMPLEMENT
}

Icon *Link::getIcon() {
    return nullptr;
}
