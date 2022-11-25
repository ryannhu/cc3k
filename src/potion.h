#ifndef _POTION_H
#define _POTION_H
#include "item.h"
#include <string>

class Potion : public Item {
    bool abilitiesVisible;
    std::string potionType;
    public:
        Potion(int x, int y, std::string potionType);
        std::string getPotionType();
        void consume();
        char getSymbol() override;
};

#endif
