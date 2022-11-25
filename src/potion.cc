#include "potion.h"

Potion::Potion(int x, int y, std::string potionType) : Item{x, y}, potionType{potionType} { }

void Potion::consume() {
    

}

char Potion::getSymbol() {
    return 'P';
}

std::string Potion::getPotionType() {
    return potionType;
}
