#ifndef _GAME_H_
#define _GAME_H_
#include "floor.h"
#include "player.h"
#include <string>

class Game {
   
    Floor *floor;
    Player *p;
    int floorNumber;
    std::string actionMessage;
    public:
        Game();
        void move(std::string dir);
        void attack(std::string dir);
        void update();
        void usePotion(std::string dir);
        void restart();
        std::string getActionMessage();
        void setActionMessage(std::string m);
        ~Game();

    friend std::ostream &operator<<(std::ostream &out, const Game &g);
};


#endif
