// Globals.h
// Header file defining functions and data required globally
// Author: Sol Cotton 19/04/19

#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

// globally accessible data: extern allows any file sourcing Globals.h to use these
extern int rowsize;
extern int columnsize;
extern int amountOfBoxes;
extern int totalActions;
extern int numActionsForSuddenDeath;
extern int bombDropPercentage;
extern std::string infoText;
extern std::string pickupText;
extern int numberOfDeadPlayers;
enum SCREEN {TITLE, GAME, PAUSE};

// global functions also accessible to any file including Globals.h
std::string getStringOfLength(int length);
void rangeCheck(int x, int y);
bool checkValidInput(std::string myInput, SCREEN thisScreen = GAME);
char getValidInput(SCREEN thisScreen = GAME);
void clearScreen();

#endif