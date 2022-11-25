#include "enemy.h"

Enemy::Enemy(int x, int y) {
    setX(x);
    setY(y);
};

void Enemy::move(int x, int y) {
    //TODO should be random
    setX(getX() + x);
    setY(getY() + y);
}



bool Enemy::isHostile() {
    return true;
}

char Enemy::getSymbol() const {
    return ' ';
}

Enemy::~Enemy() {}
