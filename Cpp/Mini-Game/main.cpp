#include <iostream>
#include <string>

#include "player.h"
#include "Game.h"
#include "item.h"
using namespace std;

int main() {
    Player p1;
    Game game;
    game.initializeWorld(&p1);

    bool keep_playing = true;
    do {
        game.menu();
        int choice;
        cout << "Make a choice: ";
        cin >> choice;
        cout << "------------------------------------\n";

        switch (choice) {
            case 1: {
                game.look();
                break;
            }
            case 2: {
                game.pickUp();
                break;
            }
            case 3: {
                game.inventory();
                break;
            }
            case 4: {
                p1.stats();
                string id = "";
                while (id == "") {
                    cout << "Enter an ID: ";
                    cin >> id;
                }
                cout << "-------------------\n";
                game.equip(id);
                p1.stats();
                break;
            }
            case 5: {
                string id = "";
                    cout << "Enter an ID: ";
                    cin >> id;
                cout << "-------------------\n";
                game.use(id);
                break;
            }
            case 6: {
                char dir;
                cout << "Enter an direction to exit: ";
                cin >> dir;
                cout << "-------------------\n";
                game.go(dir);
                break;
            }
            case 7: {
                cout << "\nHere's the menu again." << endl;
                break;
            }
            case 8: {
                game.exit(&keep_playing);
                break;
            }
            default: cout << "\nEnter a valid choice.\n";
        }
    }while (keep_playing);

    return 0;
}
