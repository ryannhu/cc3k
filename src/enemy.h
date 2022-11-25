#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"

class Enemy : public Character {
    public:
        Enemy(int x, int y);
        virtual bool isHostile();
        char getSymbol() const override;
        void move(int x, int y) override;
        virtual ~Enemy();
        
};

#endif
