#ifndef _CHARACTER_H_
#define _CHARACTER_H_


class Character {
    int hp;
    int atk;
    int def;
    int xPos, yPos;
    public:
        virtual void setHp(int h);
        virtual void setAtk(int newDef);
        virtual void setDef(int newDef);
        virtual void setX(int newX);
        virtual void setY(int newY);

        virtual bool withinRange(Character &character);

        virtual int getHp() const;
        virtual int getAtk() const;
        virtual int getDef() const;
        virtual int getX() const;
        virtual int getY() const;
        virtual char getSymbol() const = 0;
        virtual void move(int x, int y);
        virtual void takeDamage(Character *attacker);

        virtual void attack(Character *target);
        virtual bool isAlive();

};


#endif
