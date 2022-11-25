#include <ostream>
#include "game.h"
#include "dwarf.h"
#include "human.h"
#include "elf.h"
#include "orc.h"
#include <iostream>

Game::Game() {
    
    // create floor
    floor = new Floor();
    floorNumber = 1;

    // get race from user and update player
    char race;
    std::cin >> race;
    floor->setPlayer(race);
    
    floor->update();
    
    p = floor->getPlayer();

}


std::string Game::getActionMessage() {
    return actionMessage;
}
void Game::setActionMessage(std::string m) {
    actionMessage = m;
}

void Game::move(std::string dir) {
    try {
        floor->moveCharacter(dir, p);

    } catch (...) {throw 3;}
    setActionMessage("PC moves " + dir);
}

void Game::attack(std::string dir) {
    std::string msg = "";
    floor->attack(p, dir, msg);
    setActionMessage(msg);
}

void Game::usePotion(std::string dir) {
    floor->usePotion(dir);
        move(dir);

    p = floor->getPlayer();
}

void Game::update() {
    floor->update();
}

std::ostream &operator<<(std::ostream &out, const Game &g){
    out << *g.floor;
    out << "\x1B[96m";
    out << "Race: " << g.p->getName();
    out << " Gold: " << g.p->getGold() << "\t\t\t\t\t\t     Floor " << g.floorNumber << "\n";
    out << "HP: " << g.p->getHp() << '\n';
    out << "Atk: " << g.p->getAtk() << '\n';
    out << "Def: " << g.p->getDef() << '\n';
    out << "Action: " << g.actionMessage << '\n';
    if (g.floor->playerSeesPotion()) {
        out << "I SEE A POTION " << '\n';
    }
    out << "\031[0m";

    out << g.p->getX() << ", " << g.p->getY() << '\n';

    out << "\033[0m";
    return out;
}

Game::~Game() {
    delete floor;
    delete p;
}