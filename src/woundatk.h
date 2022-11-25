#ifndef _WOUNDATK_H
#define _WOUNDATK_H

#include "decorator.h"

class WoundAtk : public Decorator {
    public:
        WoundAtk(Player *component);
        int getAtk() const override;
};

#endif
