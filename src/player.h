#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "character.h"
#include "potion.h"
#include <string>

class Player : public Character {
    int gold;
    bool barrierSuit;
    
    protected:
        const int maxHp;
    public:
        Player(int x, int y, int maxHp = 0);
        Player();
        Player(Player *other);
        virtual void updateStats(); 
        virtual void addGold(int amount);
        char getSymbol() const override;
        virtual std::string getName() = 0;
        virtual int getGold();
        void consume(Potion *p);
        void move(int x, int y) override;
        void takeDamage(Character *attacker) override;
        virtual ~Player();
};

#endif
