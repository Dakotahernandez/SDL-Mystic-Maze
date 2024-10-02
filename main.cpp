#include <iostream>
//#include <string>
#include <SDL2/SDL_mixer.h>
#include "Character.h"
#include "Constants.h"
#include "drawTexture.h"
#include "EmptyContainer.h"
#include "Enemy.h"
#include "Maze.h"
#include "SDL_Plotter.h"
#include "Themes.h"
#include "Wall.h"
#include "interactable.h"
#include "Screen.h"
#include <ctime>
using namespace std;

static bool displayed = false;

//Initialize sounds once but play constantly
//Can only have one initialized at once

int main(int argc, char ** argv){
    
    //data abstraction
    int count =0;
    bool day = true;
    int level= 0;
    long long Time = 0;
    srand(time(0) % 69);
    SDL_Plotter g(WINDOW_SIZE, WINDOW_SIZE, true);
    
    ForestMaze m1(FOREST_NUM_CONTAINERS);
    DesertMaze m2(DESERT_NUM_CONTAINERS);
    UnderwaterMaze m3(UNDERWATER_NUM_CONTAINERS);
    vector<int> containerSizes;
    containerSizes.push_back(FOREST_CONTAINER_SIZE);
    containerSizes.push_back(DESERT_CONTAINER_SIZE);
    containerSizes.push_back(UNDERWATER_CONTAINER_SIZE);

    vector<int> numContainers = {FOREST_NUM_CONTAINERS,DESERT_NUM_CONTAINERS,UNDERWATER_NUM_CONTAINERS};

    vector<Maze*> m;
    m.push_back(&m1);
    m.push_back(&m2);
    m.push_back(&m3);
    Maze* m_ptr =m[level];
    //LEvel 1 is generated here before loop;
    m_ptr->generate(numContainers[level]);
    //m_ptr->print();
    drawTexture(0,0,750,750,m_ptr->getBg(),g);
    Key k;
    k.resetKey(m_ptr);
    //m_ptr->display(g,m_ptr->getWall(),m_ptr->getTile(),numContainers[level],containerSizes[level]);
    Character player1;
    trapDoor T(&player1);
    T.resetTrap(m_ptr);
    player1.resetChar(m_ptr);
    Enemy e;
    e.resetEnemy(m_ptr);
    

    bool did_move;
    bool start = false;
    bool soundPlaying = false;
    bool startScreen = true;
    
    //SCreen operations done before main gaimplay loop
    
    //Start menu music
    g.initSound(menuSoundtrack);
    drawStartScreen(g);
    while (!g.getQuit() && !start) {
        if(!soundPlaying) {
            g.playSound(menuSoundtrack);
            soundPlaying = true;
        }
       
        screenOperations(g,start);
        g.update();
    }
    g.quitSound(menuSoundtrack);
    soundPlaying = false;
    
    while(!g.getQuit() && startScreen){
        drawTexture(0,0, 750, 750, "newStory750x750.txt", g);
        g.update();
        if(g.kbhit()){
            startScreen = false;
        }
    }
    
    while (!g.getQuit() && level < 3) {
        
        
            if(!soundPlaying) {
                g.initSound(forrestSoundtrack);
                g.Sleep(15);
                soundPlaying = true;
            }
            g.playSound(forrestSoundtrack); //CANT BE IN IF
            
            
            //Handles initial display bugs after start is clicked
            //---------------------------------------------------------------
            if(displayed == false){
                drawTexture(0,0,750,750,"forestBkg750x750.txt",g);
                m_ptr->display(g,m_ptr->getWall(),m_ptr->getTile(),numContainers[level],containerSizes[level]);
                displayed = true;
                did_move = true;
            }
            
            did_move = false;
            //------------------------------------------------------------------------
            // this if statement checks for new level
            //It also creates and starts the 2nd level;
            //--------------------------------------------------------------------------
            if(player1.getLoc().x == m_ptr->exitX and player1.getLoc().y == m_ptr->exitY)
            {
                
                level++;
                if(level < 3){
                    m_ptr = m[level];
                    m_ptr->generate(numContainers[level]);
                    //m_ptr->print();
                    drawTexture(0,0,750,750,m_ptr->getBg(),g);
                    k.resetKey(m_ptr);
                    
                    if (level==1){
                        T.resetTrap(m_ptr);
                    }
                    
                    m_ptr->display(g,m_ptr->getWall(),m_ptr->getTile(),numContainers[level],containerSizes[level]);
                    player1.resetChar(m_ptr);
                    player1.display(m_ptr->getChar(),g,containerSizes[level]);
                    k.display(g,containerSizes[level]);
                    e.resetEnemy(m_ptr);
                    did_move = true;
                }
            }
                //--------------------------------------------------------------------------------
                //did_move = false; //check
                if (g.kbhit() && Time%5==0) {
                    count++;
                    char key = tolower(g.getKey());  //Capture the key press once
                    //UNDERWATER MECHANIC
                    if(count>=5 && level == 2)
                    {
                        player1.move(did_move, 'a', g,m_ptr->getTile(),containerSizes[level],numContainers[level]);
                        player1.move(did_move, 'a', g,m_ptr->getTile(),containerSizes[level],numContainers[level]);
                        count=0;
                    }
                    //-----------------------------------------------------------
                    //NIghtTIME mechanic------------------------------------
                    if(count>= 50 && level == 0 && day == true) //Nighttime
                    {
                        drawTexture(0,0,750,750,"forestBkgNight750x750.txt",g);
                        m_ptr->display(g,m_ptr->getWall(),m_ptr->getWall(),numContainers[level],containerSizes[level]);
                        day = false;
                        did_move=true;
                        count = 0;
                    }
                    if(count>= 15 && level == 0 && day == false)
                    {
                        drawTexture(0,0,750,750,m_ptr->getBg(),g);
                        m_ptr->display(g,m_ptr->getWall(),m_ptr->getTile(),numContainers[level],containerSizes[level]);
                        day = true;
                        did_move = true;
                        count = 0;
                    }
                    //---------------------------------------------
                    //player movement-------------------------------
                    if (key == 'w' || key == 'a' || key == 's' || key == 'd') {
                        player1.move(did_move, key, g,m_ptr->getTile(),containerSizes[level],numContainers[level]);
                        k.checkCollision(player1.getLoc());
                        if(level==1){
                            T.checkCollision(player1.getLoc());
                        }
                    }
                    //----------------------------------------
                }//this code properly detects keypresses;
                if(g.mouseClick()){
                    // Handle mouse click
                }
                
                //diplayBackground(g);
                //Enemy collision check----------------------------------------
                if(e.checkCollision(player1.getLoc()))
                {
                    //m_ptr->PartialDisplay(g,exit,m_ptr->getTile());
                    //m_ptr->PartialDisplay(g,exit,m_ptr->getTile());
                    //m_ptr->PartialDisplay(g,exit,m_ptr->getTile());
                    player1.resetLevel();
                    k.resetLevel();
                    e.resetLevel();
                    m_ptr->setData(m_ptr->exitX,m_ptr->exitY,'1');
                    m_ptr->display(g,m_ptr->getWall(),m_ptr->getTile(),numContainers[level],containerSizes[level]);
                    did_move = true;
                }
                //------------------------------------------------------------------
                //display player,enemey,key and does partial displays
                //----------------------------------------------------------------------
                if(did_move || (&time == 0 && displayed)) {
                    //g.clear();
                    player1.display(m_ptr->getChar(),g,containerSizes[level]);
                    k.display(g,containerSizes[level]);
                    
                    if (level==1){
                        T.display(g,containerSizes[level]);
                    }
                    
                    e.pat(g,m_ptr->getTile(),containerSizes[level]);
                    e.display(g,m_ptr->getEnemy(),containerSizes[level]);
                    point exit;
                    exit.x=m_ptr->exitX;
                    exit.y=m_ptr->exitY;
                    m_ptr->PartialDisplay(g,exit,m_ptr->getTile(),containerSizes[level]);
                }
                
                
                if(level == 1) {
                    g.quitSound(forrestSoundtrack);
                    g.initSound(desertSoundtrack);
                    g.playSound(desertSoundtrack);
                } else if (level == 2) {
                    g.quitSound(desertSoundtrack);
                    g.initSound(waterSoundtrack);
                    g.playSound(waterSoundtrack);
                }
                
                
                g.update();
                Time++;
        
        }
    while(!g.getQuit()){
        drawTexture(0, 0, 750, 750, ENDSCREENBG, g);
        g.update();
    }
        //g.Sleep(25); //Introduce intentional latency to slow refresh rate
        //---------------------------------------------------------------------------

    return 0;
}
