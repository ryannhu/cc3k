#ifndef _ELF_H
#define _ELF_H

#include "player.h"

class Elf : public Player {
    public:
        Elf(int x, int y);
        void updateStats() override;
        std::string getName() override;

};

#endif
