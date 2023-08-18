#include "components/cloner/machinecloner.h"
#include "components/conf/machineconfiguration.h"
#include "components/machine.h"
#include "components/machinebuilder.h"
#include "components/schema.h"
#include "icon/pixmapicon.h"
#include <memory>
#include <string>

MachineCloner::MachineCloner(Machine *base, SchemaCloner *parent)
{
    qDebug() << "Before copying machine conf.";
    this->clonedConf = new MachineConfiguration(*base->conf);
    this->parent     = parent;
    qDebug() << "Before getting machineIcon scenePos.";
    this->pos = static_cast<QGraphicsPixmapItem *>(base->getIcon())->scenePos();
}

Connectable *MachineCloner::clone(Schema *schema)
{
    MachineConfiguration *newMachineConfiguration =
        new MachineConfiguration(*this->clonedConf);
    Machine *newMachine = MachineBuilder()
                              .setSchema(schema)
                              ->setConf(newMachineConfiguration)
                              ->build();

    newMachine->getIcon()->setPos(this->pos);

    auto [newId, newName] = schema->ids->getNewMachineBase();
    newMachine->conf->setId(newId);
    newMachine->conf->setName(newName);

    return newMachine;
}
