#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "Container.h"
#include "SDL_Plotter.h"
#include "Maze.h"
#include "Constants.h"
#include "Themes.h"
#include "drawTexture.h"
#include <iostream>
class Enemy
{
private:
    //Keeps track of any maze it's a part of as well as location
    Maze* maze_ptr;
    bool avail;
    point loc;
public:
    Enemy();
    void setLoc();
    void resetLevel();
    void resetEnemy(Maze*& m);
    void createEnemy();
    virtual void display(SDL_Plotter& g,string eFile, int containerSize) const;
    bool checkCollision(point p);
    void pat(SDL_Plotter& g,string,int containerSize);


};

//class ForestEnemy:public Enemy{
//public:
//    virtual void display(SDL_Plotter& g,string eFile, int containerSize) const override{
//        Enemy::display(g,eFile,FOREST_CONTAINER_SIZE);
//    }
//};
//
//class DesertEnemy:public Enemy{
//public:
//    virtual void display(SDL_Plotter& g,string eFile, int containerSize) const override{
//        Enemy::display(g,eFile,DESERT_CONTAINER_SIZE);
//    }
//};
//
//class UnderwaterEnemy:public Enemy{
//public:
//    virtual void display(SDL_Plotter& g,string eFile, int containerSize) const override{
//        Enemy::display(g,eFile,UNDERWATER_CONTAINER_SIZE);
//    }
//};

#endif // ENEMY_H_INCLUDED
