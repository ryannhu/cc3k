#ifndef _WEREWOLF_H
#define _WEREWOLF_H

#include "enemy.h"

class Werewolf : public Enemy {
    public:
        Werewolf(int x, int y);
        char getSymbol() const override;
};

#endif
