#ifndef _TROLL_H
#define _TROLL_H

#include "enemy.h"

class Troll : public Enemy {
    public:
        Troll(int x, int y);
        char getSymbol() const override;
};

#endif
