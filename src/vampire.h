#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "enemy.h"

class Vampire : public Enemy {
    public:
        Vampire(int x, int y);
        char getSymbol() const override;

};

#endif
