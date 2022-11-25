#include "treasure.h"

Treasure::Treasure(int x, int y, int gold) : Item{x, y}, goldAmount{gold} { }

char Treasure::getSymbol() {
    return 'G';
}

int Treasure::getGoldAmount() {
    return this->goldAmount;
}
