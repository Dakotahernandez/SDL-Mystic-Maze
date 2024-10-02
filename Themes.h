/*
 * Authors: Dakota Hernandez, Briel Finley, Cameron Hardin
 *          Jonathan Humphries, Griffin Roe, Ben Colet
 * Assignment Title: Mystic Maze
 * Assignment Description: CSI 1440 Final Project
 * File Name: Themes.h
 * Due Date: 5/2/24
 * Date Created: 4/5/24
 * Date Last Modified: 4/25/24
*/

#ifndef Themes_h
#define Themes_h

#include <vector>
#include "Container.h"
#include "Maze.h"
#include "Constants.h"
#include "SDL_Plotter.h"

class DesertMaze : public Maze {
public:
    DesertMaze(){};
    DesertMaze(int numContainers) {
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


    ~DesertMaze(){
        for(int i=0; i< DESERT_NUM_CONTAINERS; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

//    bool isValidStep(int x, int y, int numContainers) override{
//        Maze::isValidStep(x,y,DESERT_NUM_CONTAINERS);
//    }

    string characterFile = desChar;
    string tileFile = desTile;
    string wallFile = desWall;
    string bgFile = desBg;
    string eFile = desEnemy;
    string getBg() const override
    {
        return bgFile;
    }
    string getTile() const override
    {
        return tileFile;
    }
    string getWall() const override
    {
        return wallFile;
    }
    string getChar() const override
    {
        return characterFile;
    }
    string getEnemy() const override
    {
        return eFile;
    }

/*
 |display(SDL_Plotter& g) const|
 *******************************************************************************
 * description: Displays the desert-themed maze on an SDL_Plotter screen with
 *              walls drawn as black DesertWalls and empty spaces drawn with a
 *              custom color gradient using EmptyContainers.
 * return: void
 * precondition: The SDL_Plotter object 'g' is initialized and ready for drawing.
 * postcondition: The desert-themed maze is displayed on the SDL_Plotter screen
 *                with walls and empty spaces rendered according to the maze grid.
 *                Empty spaces represented by 'C' (Character) are not filled.
 *******************************************************************************
*/
};

class UnderwaterMaze : public Maze {
public:
    UnderwaterMaze(){};
    UnderwaterMaze(int numContainers) {
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

    ~UnderwaterMaze(){
        for(int i=0; i< UNDERWATER_NUM_CONTAINERS; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

//    bool isValidStep(int x, int y, int numContainers) override{
//        Maze::isValidStep(x,y,UNDERWATER_NUM_CONTAINERS);
//    }

    string characterFile = waterChar;
    string tileFile = waterTile;
    string wallFile = waterWall;
    string bgFile = waterBg;
    string eFile = waterEnemy;
    string getBg() const override
    {
        return bgFile;
    }
    string getTile() const override
    {
        return tileFile;
    }
    string getWall() const override
    {
        return wallFile;
    }
    string getChar() const override
    {
        return characterFile;
    }
    string getEnemy() const override
    {
        return eFile;
    }
/*
 |display(SDL_Plotter& g) const|
 *******************************************************************************
 * description: Displays the underwater-themed maze on an SDL_Plotter screen with
 *              walls drawn as black waterWalls and empty spaces drawn with a
 *              custom color gradient using EmptyContainers.
 * return: void
 * precondition: The SDL_Plotter object 'g' is initialized and ready for drawing.
 * postcondition: The desert-themed maze is displayed on the SDL_Plotter screen
 *                with walls and empty spaces rendered according to the maze grid.
 *                Empty spaces represented by 'C' (Character) are not filled.
 *******************************************************************************
*/
};

class ForestMaze : public Maze {
public:
    ForestMaze(){};
    ForestMaze(int numContainers) {
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

    ~ForestMaze(){
        for(int i=0; i< FOREST_NUM_CONTAINERS; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

//    bool isValidStep(int x, int y, int numContainers) override{
//        Maze::isValidStep(x,y,numContainers);
//    }

    string characterFile = fstChar;
    string tileFile = fstTile;
    string wallFile = fstWall;
    string bgFile = fstBg;
    string eFile = fstEnemy;
    string getBg() const override
    {
        return bgFile;
    }
    string getTile() const override
    {
        return tileFile;
    }
    string getWall() const override
    {
        return wallFile;
    }
    string getChar() const override
    {
        return characterFile;
    }
    string getEnemy() const override
    {
        return eFile;
    }
/*
 |display(SDL_Plotter& g) const|
 *******************************************************************************
 * description: Displays the forest-themed maze on an SDL_Plotter screen with
 *              walls drawn as black forestwalls and empty spaces drawn with a
 *              custom color gradient using EmptyContainers.
 * return: void
 * precondition: The SDL_Plotter object 'g' is initialized and ready for drawing.
 * postcondition: The desert-themed maze is displayed on the SDL_Plotter screen
 *                with walls and empty spaces rendered according to the maze grid.
 *                Empty spaces represented by 'C' (Character) are not filled.
 *******************************************************************************
*/
};


#endif /* Themes_h */

