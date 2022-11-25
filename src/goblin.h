#ifndef _GOBLIN_H
#define _GOBLIN_H

#include "enemy.h"

class Goblin : public Enemy {
    public:
        Goblin(int x, int y);
        char getSymbol() const override;
};

#endif
