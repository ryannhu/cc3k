#include "wounddef.h"

WoundDef::WoundDef(Player *component) : Decorator{component} {}

int WoundDef::getDef() const {
    int newDef = component->getDef() - 5;
    if (newDef < 0) newDef = 0;
    return newDef;
}