#ifndef _DECORATOR_H
#define _DECORATOR_H

#include "player.h"

class Decorator : public Player {
    protected:
        Player *component;
    public:
        int getAtk() const override;
        int getDef() const override;
        std::string getName() override;
        int getGold() override;
        int getHp() const override;
        int getX() const override;
        int getY() const override;
        void setHp(int h) override;
        void setAtk(int newAtk) override;
        void setDef(int newDef) override;
        void setX(int newX) override;
        void setY(int newY) override;
        bool isAlive() override;
        Decorator(Player *component);
        ~Decorator();
};

#endif
