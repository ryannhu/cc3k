#include "human.h"

Human::Human(int x, int y) : Player{x, y, 140} {
    setHp(140);
    setAtk(20);
    setDef(20);
}

std::string Human::getName() { return "Human"; }
