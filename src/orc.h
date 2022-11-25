#ifndef _ORC_H
#define _ORC_H

#include "player.h"

class Orc : public Player {
    int gold;
    public:
        Orc(int x, int y);
        void addGold(int amount) override;
        std::string getName() override;
};

#endif
