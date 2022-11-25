#include "item.h"

Item::Item(int x, int y) : xPos{x}, yPos{y} { }


int Item::getX() {
    return xPos; 
}

int Item::getY() {
    return yPos;
}

bool Item::isGuarded() { return guarded; }
void Item::setUnguarded() { guarded = false; }

bool Item::isUsed() { return used; }
bool Item::setUsed() { used = true; }


Item::~Item() {}
