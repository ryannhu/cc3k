#ifndef _BARRIER_SUIT_H
#define _BARRIER_SUIT_H

#include "item.h"

class BarrierSuit : public Item {
    public:
        char getSymbol() override;
};

#endif
