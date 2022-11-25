#ifndef _BOOSTDEF_H
#define _BOOSTDEF_H

#include "decorator.h"

class BoostDef : public Decorator {
    public:
        BoostDef(Player *component);
        int getDef() const override;
};

#endif
