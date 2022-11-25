#ifndef _COMPASS_H
#define _COMPASS_H

#include "item.h"

class Compass: public Item {
    public:
        char getSymbol() override;
};

#endif
