#include "boostatk.h"

BoostAtk::BoostAtk(Player *component) : Decorator{component} {}

int BoostAtk::getAtk() const {
    return component->getAtk() + 5;
}
