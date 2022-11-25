#include <algorithm>
#include <random>
#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include "floor.h"
#include "player.h"
#include "enemy.h"
#include "dwarf.h"
#include "human.h"
#include "orc.h"
#include "elf.h"
#include "vampire.h"
#include "goblin.h"
#include "troll.h"
#include "merchant.h"
#include "phoenix.h"
#include "potion.h"
#include "werewolf.h"
#include "dragon.h" 

SpawnFactory::SpawnFactory(std::map<int, std::vector<coordinates>> t, Floor *floor) : 
roomTiles{t}, seed{std::chrono::system_clock::now().time_since_epoch().count()}, floor{floor} {
		
}





int SpawnFactory::randomChamber() {
    // seed = std::chrono::system_clock::now().time_since_epoch().count();
    // std::default_random_engine rng{seed};
    // std::uniform_int_distribution<int> chamber(1, 5);
    // auto drugon = std::bind(chamber, rng);
    // return drugon();
    int dice[] = {1,2,3,4,5};
    seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine rng{seed};
    std::shuffle(dice , dice + sizeof(dice)/sizeof(dice[0]), rng);
    return dice[0];
}

coordinates SpawnFactory::randomTile(int chamber) {
    seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine rng{seed};
	std::vector<coordinates> room = roomTiles.at(chamber);
    std::shuffle(room.begin(), room.end(), rng);

    int i = 0;
    while (floor->isTileOccupied(room.at(i).yPos, room.at(i).xPos )) {
        i++;
    }    
    return room.at(i);    
}

Player* SpawnFactory::spawnPlayer(char race) {
    seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine rng{seed};
    coordinates coords = randomTile(randomChamber());
    int x = coords.xPos;
    int y = coords.yPos;
    switch(race) {
        case 'h':
            // human
	        return new Human{x, y};
            break;
        case 'e':
            // elf
	        return new Elf{x, y};
            break;
        case 'd':
            // dwarf
            return new Dwarf{x, y};
	        break;
        case 'o':
            // orc
	        return new Orc{x, y};
            break;
        default:
            break;
    }
}

Enemy* SpawnFactory::spawnEnemy(int chamber) {
    coordinates coords = randomTile(chamber);
    // std::cout << chamber; 
    int x = coords.xPos;
    int y = coords.yPos;
	std::default_random_engine rng{seed};
    char enemyOdds[] = {'w','w','w','w','v','v','v','g','g','g','g','g','t','t','p','p','m','m'};
    std::shuffle(enemyOdds , enemyOdds + sizeof(enemyOdds)/sizeof(enemyOdds[0]), rng);
    // std::cout << enemyOdds[0];
    switch (enemyOdds[0]) {
        case 'w':
            return new Werewolf{x, y};
        case 'v':
            return new Vampire{x, y};
        case 'g':
            return new Goblin{x, y};
        case 't':
            return new Troll{x, y};
        case 'p':
            return new Phoenix{x, y};
        case 'm':
            return new Merchant{x, y};
        default:
            break;
    }

}

Item* SpawnFactory::spawnItem(char itemType) { 
    seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine rng{seed};
    coordinates coords = randomTile(randomChamber());
    int x = coords.xPos;
    int y = coords.yPos;

    std::string potionOdds[] = {"RH","BA","BD","PH","WA","WD"};
    std::string treasureOdds[] = {"S","S","N","N","N","N","N","D"};

    switch(itemType) {
        case 'p': {
            std::shuffle(potionOdds, potionOdds + sizeof(potionOdds) / sizeof(potionOdds[0]), rng);
            std::string potion_name = potionOdds[0];
        	return new Potion(x, y, potion_name);
        }
        case 't':
        	return new Treasure(x, y, 30);
    }
}

