#ifndef _DWARF_H_
#define _DWARF_H_
#include "player.h"

class Dwarf : public Player {
   int gold; 
   public:
    Dwarf(int x, int y);
    void addGold(int amount) override;
    std::string getName() override;
};


#endif
