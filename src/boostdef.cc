#include "boostdef.h"

BoostDef::BoostDef(Player *component) : Decorator{component} {}

int BoostDef::getDef() const {
    return component->getDef() + 5;
}