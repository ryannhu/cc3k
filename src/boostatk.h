#ifndef _BOOSTATK_H
#define _BOOSTATK_H

#include "decorator.h"

class BoostAtk : public Decorator {
    public:
        BoostAtk(Player *component);
        int getAtk() const override;
};

#endif
