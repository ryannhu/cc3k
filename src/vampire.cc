#include "vampire.h"

Vampire::Vampire(int x, int y) : Enemy{x, y} {
    setHp(50);
    setAtk(25);
    setDef(25);
 }

char Vampire::getSymbol() const {
    return 'V';
}

