#include "goblin.h"

Goblin::Goblin(int x, int y) : Enemy{x, y} {
    setHp(70);
    setAtk(5);
    setDef(10);
}

char Goblin::getSymbol() const {
    return 'N';
}

