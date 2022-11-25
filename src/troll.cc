#include "troll.h"

Troll::Troll(int x, int y) : Enemy{x, y} {
    setHp(120);
    setAtk(25);
    setDef(15);
}

char Troll::getSymbol() const {
    return 'T';
}
