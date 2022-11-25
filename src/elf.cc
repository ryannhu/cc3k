#include "elf.h"

Elf::Elf(int x, int y) : Player{x, y, 140} {
	setHp(140);
    setAtk(30);
    setDef(10);
}

void Elf::updateStats() {

	return;
}

std::string Elf::getName() { return "Elf"; }
