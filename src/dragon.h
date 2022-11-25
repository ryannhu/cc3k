#ifndef _DRAGON_H
#define _DRAGON_H

#include "enemy.h"
#include "treasure.h"

class Dragon : public Enemy {
    Treasure *booty;
    public:
        Dragon(int x, int y);
        // char getSymbol() override;
        // Treasure getHoard();
        // void move() override;
        int rewardAmount();
};

#endif
