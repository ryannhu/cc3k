#ifndef _WOUNDDEF_H
#define _WOUNDDEF_H

#include "decorator.h"

class WoundDef : public Decorator {
    public:
        WoundDef(Player *component);
        int getDef() const override;
};

#endif
