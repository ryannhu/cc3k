#ifndef _FACTORY_H_
#define _FACTORY_H_
#include "character.h"
#include "floor.h"
#include <vector>
#include <map>
#include "coordinates.h"
#include "item.h"

class Floor;

class SpawnFactory {
    std::map<int, std::vector<coordinates>> roomTiles;
    int seed;
    Floor *floor;
	public:
        SpawnFactory(std::map<int, std::vector<coordinates>> t, Floor *floor);

        int randomChamber();
        coordinates randomTile(int chamber);
        //Character* spawnCharacter(char typeOfCharacter);
        Enemy* spawnEnemy(int chamber);
        Item* spawnItem(char itemType);
        Player* spawnPlayer(char race);
        
};


#endif
