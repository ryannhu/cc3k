#include "character.h"
#include <cmath>
#include <iostream>

int Character::getX() const {
    return xPos;
}

int Character::getY() const {
    return yPos;
}

void Character::setX(int newX) {
    xPos = newX;
}

void Character::setY(int newY) {
    yPos = newY;
}

int Character::getHp() const {
    return hp;
}

void Character::setHp(int newHp) {
    hp = newHp;
}

int Character::getAtk() const {
    return atk;
}

void Character::setAtk(int newAtk) {
    atk = newAtk;
}

int Character::getDef() const {
    return def;
}

void Character::setDef(int newDef) {
    def = newDef;
}

void Character::takeDamage(Character *attacker) {
    std::cout << "attack:" << attacker->getAtk() << std::endl;
    std::cout << "attack:" << getDef() << std::endl;
    double damage = (100.0/(100.0 + getDef())) * attacker->getAtk();

    std::cout << damage;
    setHp(getHp() - damage);
    std::cout << std::endl <<  getHp();
}

void Character::move(int x, int y) {
    setX(getX() + x);
    setY(getY() + y);
}

void Character::attack(Character *target) {
    target->takeDamage(this);
}

bool Character::isAlive() {
    if (hp > 0) {
        return true;
    }
    return false;
}

bool Character::withinRange(Character &character) {
    int x_diff = (getX() - character.getX());
    int y_diff = (getY() - character.getY());
    return (-1 <= x_diff && x_diff <= 1) &&
           (-1 <= y_diff && y_diff <= 1);
}