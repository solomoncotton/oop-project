#include "TileList.h"
#include "Controller.h"
#include "Globals.h"
#include "Menu.h"


int main() {

    while (true) {
        // reset external counters
        resetCounters();
        displayTitleScreen(0);
        char input = getValidInput(SCREEN::TITLE);
        while (input != 'N') {
            // newgame has not been selected
            if (input == 'O') {
                optionsMenu();
            } else {
                // input == 'Q' - show quit screen
                displayTitleScreen(3);
                exit(1);
            }
            displayTitleScreen(0);
            input = getValidInput(SCREEN::TITLE);
        }
        // get the desired number of players
        int players = getNumberOfPlayers();
        // initialise a board and the controller
        TileList gameboard(amountOfBoxes);
        Controller controller(gameboard);
        try {controller.createPlayers(players);}
        catch (const char* errorMessage) {std::cerr << errorMessage; exit(1);}
        loadingScreen();
        // perform rounds until game has ended
        while (!controller.gameHasEnded()) {
            controller.performRound();
        }
    }

}
