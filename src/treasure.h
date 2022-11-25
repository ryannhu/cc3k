#ifndef _TREASURE_H_
#define _TREASURE_H_

#include "item.h"

class Treasure : public Item {
    int goldAmount;
    public:
        Treasure(int x, int y, int gold);
        char getSymbol() override;
        int getGoldAmount();
};

#endif
