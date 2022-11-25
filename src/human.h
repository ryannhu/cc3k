#ifndef _HUMAN_H
#define _HUMAN_H

#include "player.h"

class Human : public Player {
    public:
        Human(int x, int y);
        std::string getName() override;
};

#endif
