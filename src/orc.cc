#include "orc.h"

Orc::Orc(int x, int y) : Player{x, y, 180} {
	setHp(180);
    setAtk(30);
    setDef(25);
}


void Orc::addGold(int amount) {
	gold += (amount / 2);
}

std::string Orc::getName() { return "Orc"; }
