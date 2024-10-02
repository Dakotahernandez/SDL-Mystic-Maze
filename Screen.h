/*
 * Authors: Briel F., Jonathan H., Cameron H., Dakota H., Ben C., Griffin
 * Assignment Title: Group Project: Mystic Maze
 * Assignment Description:
 * Due Date: 5/ /24
 * Date Created: 4/5/24
 * Date Last Modified: 4/7/24
*/
#ifndef BOOTHSSBRIGADE_SCREEN_H
#define BOOTHSSBRIGADE_SCREEN_H
#include <fstream>
#include <sstream>
#include <string>
#include "SDL_Plotter.h"
#include "button.h"
#include <iostream>
#include "Themes.h"

using namespace std;
// I will go back through and add the full comments later. Just adding the functionality comments for now
//make it OBJECT oriented u cvnt
//class Screen: public button{
//private:
//public:
/*
// |writeToScreenn|
// *******************************************************************************
// * description: reads the file containing 0's and 1's and plots the pixel to the screen
// * return:void
// * precondition:receives the file name, location for printing,
// ************** the sdl plotter and the size of the font
// * postcondition:
// *******************************************************************************
//*/
void writeToScreen(const string&, int, int, int, SDL_Plotter&);

// draws the title screen including the buttons, background, and words
void drawStartScreen(SDL_Plotter&);

// includes functionality of buttons and directs to new pages
void screenOperations(SDL_Plotter& g, bool& gameStarted);

// starts the actual maze.
// include declarations of mazes, players, etc...
void startGame(SDL_Plotter&);

// Starts the story for the game
void startStory(SDL_Plotter&);

void endScreen(SDL_Plotter &);

/*
// *******************************************************************************
void endScreen(SDL_Plotter &);
// *******************************************************************************
*/
/* Wishful thinking function(s)
// the pause page which would hold the status of the game until resumed
void pause(SDL_Plotter&);
 */
#endif //BOOTHSSBRIGADE_SCREEN_H
