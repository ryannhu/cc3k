#include "dwarf.h"

Dwarf::Dwarf(int x, int y) : Player{x, y, 100} {
    setHp(100);
    setAtk(20);
    setDef(30);
}

void Dwarf::addGold(int amount) {
    gold += (amount * 2);
}

std::string Dwarf::getName() { return "Dwarf"; }
