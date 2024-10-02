//
//  Maze.cpp
//  Booths Brigade Project
//
//  Created by Cameron Hardin on 4/4/24.
// 4/5/24
// Added Dakota's maze genration functions using SDL

#include <iostream>
#include "Maze.h"
#include "Constants.h"
#include "EmptyContainer.h"
#include "Wall.h"
#include "SDL_Plotter.h"
using namespace std;

/*
 |initializeMaze|
 *******************************************************************************
 * description:fills maze with * so i can carve it out
 * return:void
 * precondition:there is a maze
 * postcondition:maze is now all '1'
 *******************************************************************************
*/
Maze::Maze(int numContainers) {
    data = new char*[numContainers];
    for(int i=0; i < numContainers; i++)
    {
        data[i] = new char[numContainers];
    }
    for(int i=0; i < numContainers; i++)
    {
        for(int j=0; j < numContainers; j++)
        {
            data[i][j] = '1';
            //cout << data[i][j];
        }
        //cout << endl;
    } //Visualize maze in console

}
/*
 |setEntranceExit|
 *******************************************************************************
 * description:sets entrance and exit
 * return:void
 * precondition:gievn cordinates of enternace and exit
 * postcondition:sets space for enterance and exit
 *******************************************************************************
*/
void Maze::setEntranceExit(int entranceX, int entranceY, int exitX, int exitY) {
    //data[entranceX-1][entranceY] = '1';
    data[entranceX][entranceY] = ' ';
    data[exitX][exitY] = ' ';
    this->entranceX = entranceX;
    this->entranceY = entranceY;
    this->exitX = exitX;
    this->exitY = exitY;
}

/*
 |isValidStep|
 *******************************************************************************
 * description:checks if the next space is a valid move
 * return:bool
 * precondition:given a location on the maze that isnt the border
 * postcondition:returns bool based on if it can move
 *******************************************************************************
*/

bool Maze::isValidStep(int x, int y, int numContainers) {
    if (x <= 0 || x >= numContainers - 1 || y <= 0 || y >= numContainers - 1 || data[x][y] == '-') {
        return false;
    }
    int paths = 0;
    if (data[x-1][y] == ' ')
    {paths++;}
    if (data[x+1][y] == ' ')
    {paths++;}
    if (data[x][y-1] == ' ')
    {paths++;}
    if (data[x][y+1] == ' ')
    {paths++;}
    return paths <= 1;
}

void Maze::generate(int numContainers)
{
    int entranceX, entranceY, exitX, exitY;
    //set entrance at top middle and exit at bottom middle
    entranceX = 1;
    entranceY = numContainers / 2;
    exitX = numContainers - 1;
    exitY = numContainers / 2;
    setEntranceExit(entranceX, entranceY, exitX, exitY);
    int startX = entranceX;
    int startY = entranceY;
    generateMaze(startX, startY, numContainers);
    //Display Data for debugging
    data[exitX-1][exitY] = ' ';
    /*for (int i = 0; i < NUM_CONTAINERS; i++) {
        for (int j = 0; j < NUM_CONTAINERS; j++) {
            cout << data[j][i];
        }
        cout << endl;
    }*/
    //'C' is properly in data
    print(numContainers);
}
/*
 |generateMaze|
 *******************************************************************************
 * description:recursivvely creates maze
 * return:void
 * precondition:there is a maze and its given x y locations
 * postcondition:the maze is now changed
 *******************************************************************************
*/

//THIS IS RECURSIVE
void Maze::generateMaze(int x, int y, int numContainers) {
    int xDirection[] = {-1, 0, 1, 0};
    int yDirection[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
        int r = rand() % 4;
        swap(xDirection[i], xDirection[r]);
        swap(yDirection[i], yDirection[r]);
    }
    for (int i = 0; i < 4; ++i) {
        int newX = x + xDirection[i];
        int newY = y + yDirection[i];
        if (isValidStep(newX, newY, numContainers)) {
            data[newX][newY] = ' ';
            generateMaze(newX, newY, numContainers);
        }
    }
}

void Maze::display(SDL_Plotter& g,string wallFile, string containerFile, int numContainers, int containerSize)
{ //default maze
    for (int i = 0; i < numContainers; i++) {
        for (int j = 0; j < numContainers; j++) {
            int x_offset = (i * containerSize) + BORDER_SIZE;
            int y_offset = (j * containerSize) + BORDER_SIZE;

            if (data[i][j] == '1') {
                Wall wall;
                wall.draw(wallFile,x_offset, y_offset, 0, 0, 0, g,containerSize); // Wall color is black
            } else {
                // Fill the rest with EmptyContainers
                if(data[i][j] != 'C') {
                    EmptyContainer EmptyContainer;
                    EmptyContainer.draw(containerFile,x_offset, y_offset, 180, 50, 50, g,containerSize); // EmptyContainer color (optional)
                }
            }
        }
    }
}
void Maze::PartialDisplay(SDL_Plotter& g, point p,string containerFile,int containerSize)
{
    if(data[p.x][p.y] != '1'){
        EmptyContainer emptyContainer;
        emptyContainer.draw(containerFile,(p.x * containerSize) + BORDER_SIZE, (p.y * containerSize) + BORDER_SIZE, 180, 50, 50, g,containerSize); // EmptyContainer color (optional)
    }
}

char** Maze::getData() {
    return data;
}

void Maze::setData(int x, int y, char c) {
    data[x][y] = c;
}
void Maze::print(int numContainers)
{
//    for (int i = 0; i < numContainers; i++) {
//        for (int j = 0; j < numContainers; j++) {
//            cout << data[j][i];
//        }
//        cout << endl;
//    }
}
