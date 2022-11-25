#include "dragon.h"

Dragon::Dragon(int x, int y) : Enemy{x, y}  {
    setHp(150);
    setAtk(20);
    setDef(20);
}