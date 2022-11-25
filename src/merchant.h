#ifndef _MERCHANT_H
#define _MERCHANT_H

#include "enemy.h"

class Merchant : public Enemy {
    static bool hostile;
    public:
        Merchant(int x, int y);
        char getSymbol() const override;
        bool isHostile();
        void makeHostile();

};

#endif
