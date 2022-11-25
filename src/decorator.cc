#include "decorator.h"
#include "player.h"

Decorator::Decorator(Player *comp) : component{comp} {}

int Decorator::getAtk() const {
    return component->getAtk();
}

int Decorator::getDef() const {
    return component->getDef();
}

std::string Decorator::getName() {
    return component->getName();
}

int Decorator::getGold() {
    return component->getGold();
}

int Decorator::getHp() const {
    return component->getHp();
}

int Decorator::getX() const {
    return component->getX();
}

int Decorator::getY() const {
    return component->getY();
}

void Decorator::setHp(int h) {
    component->setHp(h);
}

void Decorator::setAtk(int newAtk) {
    component->setAtk(newAtk);
}

void Decorator::setDef(int newDef) {
    component->setDef(newDef);
}

void Decorator::setX(int newX) {
    component->setX(newX);
}

void Decorator::setY(int newY) {
    component->setY(newY);
}

bool Decorator::isAlive() {
    return component->isAlive();
}

Decorator::~Decorator() {delete component;}
