//
//  Maze.h
//  Booths Brigade Project
//
//  Created by Cameron Hardin on 4/4/24.
// 4/5/24
// Added Dakotas functions to maze using SDL
#include <cstdlib>
#include <string>
#include "Container.h"
#include "SDL_Plotter.h"
#include <vector>
#include "Character.h"
#include <iostream>

#ifndef Maze_h
#define Maze_h

using namespace std;

class Maze { // Pure Abstract class
protected:
    /*Key:
     '1' is a wall
     ' ' is an empty container
     'P' is a Player
     */

    char** data;
    
public:
    virtual string getBg() const =0;
    virtual string getTile() const =0;
    virtual string getWall() const =0;
    virtual string getChar() const =0;
    virtual string getEnemy() const =0;
    Maze(int numcontainers = 25); //Instantiates a maze of * (walls)
    void generate(int );
    void generateMaze(int, int, int);
    virtual void display(SDL_Plotter& g, string, string,int,int);
    virtual void PartialDisplay(SDL_Plotter& g, point p,string containerFile, int containerSize);
    bool isValidStep(int x, int y, int  containers);

    /*
     Sets maze entrance and exit AS WELL AS character starting location
     */
    void setEntranceExit(int entranceX, int entranceY, int exitX, int exitY);

    char** getData();
    void setData(int x, int y, char c);
    void print(int);

    int entranceX;
    int entranceY;
    int exitX;
    int exitY;
};

#endif /* Maze_h */
