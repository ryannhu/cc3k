#include <iostream>
#include "game.h"
using namespace std;

int main() {
    Game game{};

    cout << game;
    // game controller
    char cmd;
    char cmd2;
    bool quit = false;
    while (true && !quit) {
        
        std::cin >> cmd;

        char direction;
        std::string dir;

        try {
                switch(cmd) {
                    
                    case 'n':
                        // move character north               
                        std::cin >> direction;

                        switch (direction) {
                            case 'o':
                                // character moves north fully
                                game.move("no");
                                break;
                            case 'w':
                                // move character north-west
                                game.move("nw");
                                break;
                            case 'e':
                                // move character north-east
                                game.move("ne");
                                break;
                        }
			            game.update();
                        cout << game;
                        break;
                    case 's':
                        // move character south
                        std::cin >> direction;
                        
                        switch (direction) {
                            case 'o':
                                // character moves north fully
                                game.move("so");
                                break;
                            case 'w':
                                // move character north-west
                                game.move("sw");
                                break;
                            case 'e':
                                // move character north-east
                                game.move("se");
                                break;
                        }
                        game.update();
                        cout << game;
                        break;
                    case 'e':
                        // move character east
                        std::cin >> direction;

                        switch (direction) {
                            case 'a':
                                // character moves north fully
                                game.move("ea");
                                break;
                        }
                        game.update();
                        cout << game;
                        break;
                    case 'w':
                        // move character west
                        std::cin >> direction;

                        switch (direction) {
                            case 'e':
                                // character moves north fully
                                game.move("we");
                                break;
                        }
                        game.update();
                        cout << game;
                        break;

                    case 'u': // USE POTION

                   
                        /*
                        std::cin >> cmd2;

                        switch(cmd2) {

                            case 'n':
                                        
                            std::cin >> direction;

                            switch (direction) {
                                case 'o':
                                    // use potion north fully
                                    game.usePotion("no");
                                    break;
                                case 'w':
                                    // use portion north west
                                    game.usePotion("nw");
                                    break;
                                case 'e':
                                    // use potion northwest
                                    game.usePotion("ne");
                                    break;
                            }
                            game.update();
                            cout << game;
                            break;
                        case 's':
                            // use potion south
                            std::cin >> direction;
                            
                            switch (direction) {
                                case 'o':
                                    // use potion south fully
                                    game.usePotion("so");
                                    break;
                                case 'w':
                                    // use potion north west
                                    game.usePotion("sw");
                                    break;
                                case 'e':
                                    // use potion north east
                                    game.usePotion("se");
                                    break;
                            }
                            game.update();
                            cout << game;
                            break;
                        case 'e':
                            // use potion east
                            std::cin >> direction;

                            switch (direction) {
                                case 'a':
                                    // use potion east
                                    game.usePotion("ea");
                                    break;
                            }
                            game.update();
                            cout << game;
                            break;
                        case 'w':
                            // use potion west
                            std::cin >> direction;

                            switch (direction) {
                                case 'e':
                                    // use potion west
                                    game.usePotion("we");
                                    break;
                            }
                            game.update();
                            cout << game;
                            break;
                        }*/


                        std::cin >> dir;
                        try {
                            game.usePotion(dir);
                            game.update();
                        } catch (...) {}
                        cout << game;
                        break;
                    case 'a':
                        // attack enemy
                        std::cin >> dir;
                        game.attack(dir);
                        game.update();
                        cout << game;
                        break;
                    case 'r':
                        // restart
                        break;
                    case 'q':
                        // quit
                        quit = true; 
                        break;
                    default:
                        break;
                }
           

            } catch(int err) {
		    cout << "invalid move" << endl;;
	    }
            catch (...) {cout << "i like dudes";}
}
}

