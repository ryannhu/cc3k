#include "woundatk.h"

WoundAtk::WoundAtk(Player *component) : Decorator{component} {}

int WoundAtk::getAtk() const {
    int newAtk = component->getAtk() - 5;
    if (newAtk < 0) newAtk = 0;
    return newAtk;
}
