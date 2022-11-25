#include <ostream>
#include <iostream>
#include "floor.h"
#include "dwarf.h"
#include "human.h"
#include "orc.h"
#include "elf.h"
#include "vampire.h"
#include "potion.h"
#include "werewolf.h"
#include "dragon.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

Floor::Floor() : seed{std::chrono::system_clock::now().time_since_epoch().count()} {
    // player = new Dwarf{16, 16};
    // TODO ( maybe add a vector/map of all chambers as a private attributes so random number generator can disturbitly likely)
    map<int, vector<coordinates>> chambers;
    for (int chamber_number = 1; chamber_number <= 5; ++chamber_number) {
        vector<coordinates> insert_vector;
        chambers[chamber_number] = insert_vector;
    }

    for (int row = 0; row < 25; row ++) {
        std::vector<char> new_row;
        std::vector<char> char_row;
        for (int col = 0; col < 79; col ++) { 
            char_row.push_back(MAP_STR[row*79+col]);

            if(MAP_STR[row*79+col] == '1' || MAP_STR[row*79+col] == '2' || MAP_STR[row*79+col] == '3' ||MAP_STR[row*79+col] == '4' || MAP_STR[row*79+col] == '5') {
                chambers.at((int)MAP_STR[row*79+col]- 48).emplace_back(coordinates{col, row});
                new_row.push_back('.');
            } else {
                new_row.push_back(MAP_STR[row*79+col]);
            }
        }
        grid.push_back(new_row);
        MAP.push_back(char_row);

    }
    roomtiles = chambers;
    // generate seed (using time)
    spawnfactory = new SpawnFactory{roomtiles, this};

    generateFloor();

    update(); 
}

int randomInt(int low, int high) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed}; 
    vector<int> s;
    for (int i = low; i <= high; ++i) {
        s.emplace_back(i);
    }
    std::shuffle(s.begin(), s.end(), rng);
    return s[0];
}



void Floor::generateFloor() {
    // int rng = 1 + (rand() % 5);

    // generate the rng engine
    std::default_random_engine rng{seed};


    for (int i = 0; i < 20; i++) {

        int x = randomInt(1,5);
        // cout << x;
        enemies.push_back(spawnfactory->spawnEnemy(x));
    }

    // Spawn 10 potions
    for (int i = 0; i < 10; i++) {
        items.push_back(spawnfactory->spawnItem('p'));
    }
    
    //update();
}

bool Floor::playerSeesPotion() {
    
    int row = player->getY();
    int col = player->getX();
    
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
                try {
                    if (grid.at(row + i).at(col + j) == 'P') {
                        return true;
                    }
             } catch (...) {}
        }
    }
    
    

    return false;
}

Player *Floor::getPlayer() {
    return this->player;
}

void Floor::setPlayer(char race) {
    player = spawnfactory->spawnPlayer(race);
   // grid[player->getY()][player->getX()] = player->getSymbol(); // replace this
}

bool Floor::containsPotion(int row, int col) {
    if (grid[row][col] == 'P') return true;
    return false;
}

void Floor::usePotion(std::string direction) {
    
    int x_dir = 0;
    int y_dir = 0;
    if (direction == "no") {
        y_dir = -1;
    } else if (direction == "nw") {
        y_dir = -1;
        x_dir = -1;
    } else if (direction == "ne") {
        y_dir = -1;
        x_dir = 1;
    } else if (direction == "so") {
        y_dir = 1;
    } else if (direction == "se") {
        y_dir = 1;
        x_dir = 1;
    } else if (direction == "sw") {
        y_dir = 1;
        x_dir = -1;
    } else if (direction == "ea") {
        x_dir = 1;
    } else if (direction == "we") {
        x_dir = -1;
    }

    if (containsPotion(player->getY() + y_dir, player->getX() + x_dir)) {
        //cout << "HERE " << endl;
        for (auto i : items) {
            if (i->getY() == player->getY() + y_dir && i->getX() == player->getX() + x_dir) {
                Potion *p = dynamic_cast<Potion *>(i);
                cout << "yo im about to slurp up this potion " << endl;
                if (p->getPotionType() == "RH" || p->getPotionType() == "PH") {
                    player->consume(p);
                } else if (p->getPotionType() == "BA") {
                    player = new BoostAtk{player};
                } else if (p->getPotionType() == "WA") {
                    player = new WoundAtk{player};
                } else if (p->getPotionType() == "BD") {
                    player = new BoostDef{player};
                } else if (p->getPotionType() == "WD") {
                    player = new WoundDef{player};
                }
                p->setUsed();

                std::cout << "Potion TYPE : " << p->getPotionType() << std::endl;
            }
        }
        //moveCharacter(direction, player);
        // player->consume();
    } else {
        throw 3;
    }

}

bool Floor::isTileOccupied(int x, int y) {
    for (Enemy *e : enemies) {
        if (e->isAlive()) {
            if (e->getY() == y && e->getX() == x) return true;
        }
    }
    for (Item *i : items) {
        if (!i->isUsed()) {
            if (i->getY() == y && i->getX() == x) return true;
        }
    }
    if (player != nullptr && player->getY() == y && player->getX() == x) return true;
    return false;
}

bool Floor::validMove(int y, int x) {


    if (isTileOccupied(x, y)) return false;

    char cell = MAP[y][x];
    if (!(cell == ' ' || cell == '|' || cell == '-')) {
        return true;
    }
    return false;
}

void Floor::moveCharacter(std::string direction, Character *c) {

    int x_dir = 0;
    int y_dir = 0;
    if (direction == "no") {
        y_dir = -1;
    } else if (direction == "nw") {
        y_dir = -1;
        x_dir = -1;
    } else if (direction == "ne") {
        y_dir = -1;
        x_dir = 1;
    } else if (direction == "so") {
        y_dir = 1;
    } else if (direction == "se") {
        y_dir = 1;
        x_dir = 1;
    } else if (direction == "sw") {
        y_dir = 1;
        x_dir = -1;
    } else if (direction == "ea") {
        x_dir = 1;
    } else if (direction == "we") {
        x_dir = -1;
    }



    if (validMove(c->getY() + y_dir, c->getX() + x_dir)) {
        // grid[c->getY()][c->getX()] = (MAP[c->getY()][c->getX()] == '!' || MAP[c->getY()][c->getX()] == '+')? MAP[c->getY()][c->getX()] : '.';
        c->setY(c->getY() + y_dir);
        c->setX(c->getX() + x_dir);
        // grid[c->getY()][c->getX()] = c->getSymbol();
    } else {
        throw 3;
    }

}

void Floor::attack(Character *attacker, std::string direction, std::string &msg) {
    // std::cout<<"henry is  a epdo";
    int x_dir = 0;
    int y_dir = 0;
    if (direction == "no") {
        y_dir = -1;
    } else if (direction == "nw") {
        y_dir = -1;
        x_dir = -1;
    } else if (direction == "ne") {
        y_dir = -1;
        x_dir = 1;
    } else if (direction == "so") {
        y_dir = 1;
    } else if (direction == "se") {
        y_dir = 1;
        x_dir = 1; 
    } else if (direction == "sw") {
        y_dir = 1;
        x_dir = -1;
    } else if (direction == "ea") {
        x_dir = 1;
    } else if (direction == "we") {
        x_dir = -1;
    }
    for (auto e : enemies) {
        if (e->withinRange(*player))  
            std::cout << "p: " <<attacker->getX() + x_dir << " e: " << e->getX() << "p: " << attacker->getY() + y_dir << " e: "<< e->getY() << endl;
        if ((attacker->getX() + x_dir == e->getX()) && (attacker->getY() + y_dir == e->getY())) {
            auto victim = e;
            std::cout << "get shit on bitch";
            attacker->attack(victim);

            msg = "PC deals 1 damage to V (4 HP). V deals 2 damage to PC.";
            return;
            // grid[c->getY()][c->getX()] = c->getSymbol();
        } 
    }

    if (attacker->getX() + x_dir == player->getX() && attacker->getY() + y_dir == player->getY()) {
            auto victim = player;
            attacker->attack(victim);
            return;
        }
}

void Floor::moveCharacterRandom(Character *c) {
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    string directions[] = {"no", "so", "ea", "we", "ne", "nw", "se", "sw"};
    std::shuffle(directions , directions  + sizeof(directions)/sizeof(directions[0]), rng);
    for (string dir: directions) {
        try {
            moveCharacter(dir, c);
            return;
        } catch (...) { }
    }
}

int Floor::randomChamber() {
       return randomInt(1,5);
}

void Floor::spawnPlayer(Player *p) {
    player = p;
    update();
}

void Floor::update() {
    cout << "update" << endl;

    for (Enemy *e : enemies) {
        if (e->isAlive()) {
            if (player != nullptr && e->withinRange(*player)) {

            } else {
                moveCharacterRandom(e);
            }
        }
        // cout << e->getX()<< ", " << e->getY() << " " << e->getSymbol() << endl; 
    }

    for (int row = 0; row < 25; row ++) {
        for (int col = 0; col < 79; col ++) { 
            if(MAP[row][col] == '1' || MAP[row][col] == '2' || MAP[row][col] == '3' || MAP[row][col] == '4' || MAP[row][col] == '5') {
                grid[row][col] = '.';
            } else if (MAP[row][col] == '!'){
                grid[row][col] = '#';
            } else {
                grid[row][col] = MAP[row][col];
            }
        }
        for (Enemy *e : enemies) {
            if (e->isAlive()) {
                grid[e->getY()][e->getX()] = e->getSymbol();
            } else {
                cout << e->getX()<< ", " << e->getY() << " " << e->getSymbol() << endl; 

            }
        }
        for (Item *i : items) {
            if (!i->isUsed()) {
                grid[i->getY()][i->getX()] = i->getSymbol();
            } else {
                // cout << i->getX() << ", " << i->getY() << " " << i->isUsed() << endl;
            }
        }
        if (player != nullptr) {
            if (player->isAlive()) {
                grid[player->getY()][player->getX()] = player->getSymbol();
            }
        }
    }
}

Floor::~Floor() {
    for (auto i : items) {
        delete i;
    }
    for (auto j : enemies) {
        delete j;
    }
    delete spawnfactory;
}



std::ostream &operator<<(std::ostream &out, Floor &f){
    
    //coords print
    for (int x = 0; x < 79; x++) out << x;

    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 79; x++) {
            // Draw borders

            if (f.grid[y][x] == '@') 
                out << "\x1B[35m";
            else if (f.grid[y][x] == '-' || f.grid[y][x] == '|') 
                out << "\x1B[33m";
            else if (f.grid[y][x] == '.'|| f.grid[y][x] == '#'|| f.grid[y][x] == '+') 
                out << "\x1B[30m";
            else 
                out << "\033[0m";
            out << f.grid[y][x];
            out << "\033[0m";
        }
        out << endl;
    }
    return out;
}

#include "coordinates.h"

