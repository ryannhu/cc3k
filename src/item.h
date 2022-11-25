#ifndef _ITEM_H
#define _ITEM_H
#include "character.h"

class Item {
    int xPos, yPos;
    char symbol;
    bool guarded;
    bool used;
    public:
        Item(int x, int y);
        int getX();
        int getY();
        virtual char getSymbol() = 0;
        // bool withinRange(Character character);
        bool isGuarded();
        bool isUsed();
        bool setUsed();
        void setUnguarded();
        virtual ~Item();
};

#endif
