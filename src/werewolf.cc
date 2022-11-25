#include "werewolf.h"

Werewolf::Werewolf(int x, int y) : Enemy{x, y} {
    setHp(120);
    setAtk(30);
    setDef(5);
}

char Werewolf::getSymbol() const {
    return 'W';
}

