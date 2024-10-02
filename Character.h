//
//  Character.h
//  Booths Brigade Project
//
//  Created by Cameron Hardin on 4/11/24.
//

#ifndef Character_h
#define Character_h

#include "Container.h"
#include "SDL_Plotter.h"
#include "Maze.h"
#include "Container.h"
#include "SDL_Plotter.h"
#include "Constants.h"
#include "drawTexture.h"

class Character {
private:
    //Keeps track of any maze it's a part of as well as location
    Maze* maze_ptr;
    point loc;

public:
    point getLoc();
/*
 |Character()|
 *******************************************************************************
 * description: Throws an exception indicating that a Character object cannot
 *              be created without specifying a Maze object.
 * return: void
 * precondition: None
 * postcondition: None
 *******************************************************************************
*/
    Character();
/*
 |display(SDL_Plotter& g) const|
 *******************************************************************************
 * description: Displays the Character on the SDL_Plotter screen as a green
 *              square.
 * return: void
 * precondition: The SDL_Plotter object 'g' must be initialized and ready for
 *               drawing.
 * postcondition: The Character is displayed on the screen at its current
 *                location within the Maze.
 *******************************************************************************
*/
    //Character();
    void draw(int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g) const;
    virtual void display(string fileName, SDL_Plotter& g, int containerSize) const;

    /*IMPORTANT:
     Move To takes a new location in the maze data** and tests to see if it's available. if so it moves the player (character in data**) and returns true.
     Must return boolean to play animations
     */
    void resetLevel();
    void setLoc(int, int);
    void resetChar(Maze*& m);
/*
 |move(bool& did_move, char keyPress, SDL_Plotter& g)|
 *******************************************************************************
 * description: Moves the Character within the Maze based on a specified key
 *              press ('w', 'a', 's', 'd').
 * return: void
 * precondition: The boolean reference 'did_move' must be provided for tracking
 *               the success of the movement. The character 'keyPress' specifies
 *               the direction of movement. The SDL_Plotter object 'g' must be
 *               initialized and ready for drawing.
 * postcondition: The Character's position (x_loc, y_loc) is updated according
 *                to the key press, and the Maze data is updated if the movement
 *                is valid.
 *******************************************************************************
*/

    void move(bool& did_move, char keyPress, SDL_Plotter& g,string containerFile,int containerSize, int numContainers);
    void moveOutsideOfMaze(int newX, int newY);
/*
 |isAvailable(const char& c)|
 *******************************************************************************
 * description: Checks if the given character from the Maze is available for
 *              movement (i.e., not a wall character '1').
 * return: bool - True if the character is available for movement, false if it
 *                represents a wall.
 * precondition: A valid character 'c' from the Maze must be provided.
 * postcondition: None
 *******************************************************************************
*/
    bool isAvailable(const char& c);
/*
 |isInMaze(int x, int y) const|
 *******************************************************************************
 * description: Checks if the given coordinates (x, y) are within the bounds
 *              of the Maze.
 * return: bool - True if the coordinates are within the Maze bounds, false
 *                otherwise.
 * precondition: None
 * postcondition: Displays a debug message if the coordinates are outside the
 *                Maze bounds.
 *******************************************************************************
*/
    bool isInMaze   (int newX, int newY, int) const;
/*
 |outOfBounds(int newX, int newY) const|
 *******************************************************************************
 * description: Checks if the specified coordinates (newX, newY) are out of
 *              screen bounds.
 * return: bool - True if the coordinates are out of screen bounds, false
 *                otherwise.
 * precondition: None
 * postcondition: Displays a debug message if the attempted movement is out of
 *                the screen bounds.
 *******************************************************************************
*/
    bool outOfBounds(int newX, int newY,int,int) const;

    //NOTE: deleted the moveUp() etc functions to avoid duplicate code
};

//class ForestCharacter:public Character{
//public:
//    void display(string fileName, SDL_Plotter& g, int containerSize) const override{
//        Character::display(fileName,g,containerSize);
//    }
//};
//
//class DesertCharacter:public Character{
//public:
//    void display(string fileName, SDL_Plotter& g, int containerSize) const override{
//        Character::display(fileName,g,containerSize);
//    }
//};
//
//class UnderwaterCharacter:public Character{
//public:
//    void display(string fileName, SDL_Plotter& g, int containerSize) const override{
//        Character::display(fileName,g,containerSize);
//    }
//};
#endif /* Character_h */
