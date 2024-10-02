#ifndef interactable_h
#define interactable_h
#include "Container.h"
#include "SDL_Plotter.h"
#include "Maze.h"
#include "Constants.h"
#include "Character.h"
#include <iostream>

class Key
{
private:
    //Keeps track of any maze it's a part of as well as location
    Maze* maze_ptr;
    bool avail;
    point loc;
public:
    Key();
    void resetKey(Maze*& m);
    void resetLevel();
    point setLoc();
    void createKey();
    void display(SDL_Plotter& g,int) const;
    void checkCollision(point p);

};

class trapDoor
{
private:
    Maze* maze_ptr;
    bool avail;
    point loc;
    Character* character_ptr;
public:
    trapDoor(Character*);
    void resetTrap(Maze*& m);
    point setLoc();
    void createTrap();
    void display(SDL_Plotter& g,int containerSize) const;
    void checkCollision(point p);
};
#endif /* interactable_h */
