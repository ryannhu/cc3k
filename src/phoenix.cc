#include "phoenix.h"

Phoenix::Phoenix(int x, int y) : Enemy{x, y} {
    setHp(50);
    setAtk(35);
    setDef(20);
}

char Phoenix::getSymbol() const {
    return 'X';
}
