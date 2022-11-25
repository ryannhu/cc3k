#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <vector>
#include <map>
#include <ostream>
#include "item.h"
#include "enemy.h"
#include "player.h"
#include "factory.h"
#include "boostatk.h"
#include "boostdef.h"
#include "woundatk.h"
#include "wounddef.h"



struct coordinates;

class Floor {
    int stairRoomNumber;
    bool visibleStairs;
    unsigned seed;
    Player *player;
    std::vector<Item *> items;
    std::vector<Enemy *> enemies; 
    std::vector<std::vector<char>> grid; 
    std::vector<std::vector<char>> MAP; 
    std::map<int, std::vector<coordinates>> roomtiles;
    SpawnFactory *spawnfactory;
    public:
        Floor();
        int randRoom();
        void setPlayer(char race);
        Player *getPlayer();
        void generateFloor();
        void spawnPlayer(Player *p);
        void update();
        bool playerSeesPotion();
        void usePotion(std::string dir);
        bool containsPotion(int row, int col);
        void spawnStairs();
        bool validMove(int y, int x);
        bool isTileOccupied(int x, int y);
        void moveCharacter(std::string direction, Character *c);
        void moveCharacterRandom(Character *c);
        void spawnItems();
        void spawnEnemies();
        void generateBarrierSuit();
        int randomChamber();
        void attack(Character *attacker, std::string direction, std::string &msg);
        coordinates generateCoord(int chamber_room);
        ~Floor();
        friend std::ostream &operator<<(std::ostream &out, Floor &f);

        // std::map<int, int> roomtiles[5];
        const char * MAP_STR = 
        "|-----------------------------------------------------------------------------|"
        "|                                                                             |"
        "| |--------------------------|        |-----------------------|               |"
        "| |11111111111111111111111111|        |22222222222222222222222|               |"
        "| |11111111111111111111111111+########+22222222222222222222222|-------|       |"
        "| |11111111111111111111111111|   #    |2222222222222222222222222222222|--|    |"
        "| |11111111111111111111111111|   #    |2222222222222222222222222222222222|--| |"
        "| |----------+---------------|   #    |----+----------------|222222222222222| |"
        "|            #                 #############                |222222222222222| |"
        "|            #                 #     |-----+------|         |222222222222222| |"
        "|            #                 #     |333333333333|         |222222222222222| |"
        "|            ###################     |333333333333|   ######+222222222222222| |"
        "|            #                 #     |333333333333|   #     |222222222222222| |"
        "|            #                 #     |-----+------|   #     |--------+------| |"
        "|  |---------+-----------|     #           #          #              #        |"
        "|  |444444444444444444444|     #           #          #         |----+------| |"
        "|  |444444444444444444444|     ########################         |55555555555| |"
        "|  |444444444444444444444|     #           #                    |55555555555| |"
        "|  |444444444444444444444|     #    |------+--------------------|55555555555| |"
        "|  |444444444444444444444|     #    |555555555555555555555555555555555555555| |"
        "|  |444444444444444444444+##########+555555555555555555555555555555555555555| |"
        "|  |444444444444444444444|          |555555555555555555555555555555555555555| |"
        "|  |---------------------|          |---------------------------------------| |"
        "|                                                                             |"
        "|-----------------------------------------------------------------------------|";
};

#endif
