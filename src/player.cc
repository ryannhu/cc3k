#include "player.h"
#include <cmath>
#include <iostream>

Player::Player(int x, int y, int maxHp) : maxHp{maxHp} {
    setX(x);
    setY(y);
    gold = 0;
}

Player::Player() : maxHp{100} {}

Player::Player(Player *other) : maxHp{other->maxHp} {
    setX(other->getX());
    setY(other->getY());
    setAtk(other->getAtk());
    setDef(other->getDef());
    setHp(other->getHp());
    gold = 0;
}

char Player::getSymbol() const {
    return '@';
}

void Player::move(int x, int y) {
    setX(getX() + x);
    setY(getY() + y);
}

int Player::getGold(){
    return gold;
}

void Player::updateStats() {

}

void Player::consume(Potion *p) {
    
    std::string potion = p->getPotionType();

    if (potion == "RH") {
        setHp(getHp() + 10);
    } else if (potion == "PH") {
        setHp(getHp() - 10);
    }

    // player = new BoostAtk(player);
    if (getHp() > maxHp) setHp(maxHp);
    if (getHp() < 0) setHp(0);

}



// std::string Player::getName() {
//     return "Bitch";
// }

void Player::takeDamage(Character *attacker) {
    int damage = (int) std::ceil((100/(100 + getDef())) * attacker->getAtk());
    if (barrierSuit) {
        damage = (int) std::ceil(damage/2);
    }
    setHp(getHp() - damage);
}

void Player::addGold(int amount) {
    gold += amount;
}

Player::~Player() {}
