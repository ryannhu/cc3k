#include "merchant.h"

Merchant::Merchant(int x, int y) : Enemy{x, y} {
    setHp(30);
    setAtk(70);
    setDef(5);
}

bool Merchant::isHostile() {
    return true;
}

char Merchant::getSymbol() const {
    return 'M';
}
