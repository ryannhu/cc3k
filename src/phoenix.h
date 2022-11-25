#ifndef _PHOENIX_H
#define _PHOENIX_H

#include "enemy.h"

class Phoenix : public Enemy {
    
    public:
        Phoenix(int x, int y);
        char getSymbol() const override;
};

#endif
