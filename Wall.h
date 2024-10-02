//
//  Wall.h
//  Booths Brigade Project
//
//  Created by Cameron Hardin on 4/4/24.
//

#ifndef Wall_h
#define Wall_h

#include "Container.h"
#include "SDL_Plotter.h"
#include "Constants.h"
#include "drawTexture.h"

class Wall : public Container {
private:
    bool occupied;
public:
/*
     |Wall()|
     *******************************************************************************
     * description: Default constructor for a Wall object.
     * return: void
     * precondition: None
     * postcondition: Initializes a Wall object with the 'occupied' flag set to true.
     *******************************************************************************
    */
    Wall();
/*
     |isOccupied() const|
     *******************************************************************************
     * description: Checks if the Wall object is occupied (always returns true for a wall).
     * return: bool - Always true indicating the wall is occupied.
     * precondition: None
     * postcondition: Returns true to indicate the wall is occupied.
     *******************************************************************************
    */
    bool isOccupied() const override;
/*
     |draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g) const|
     *******************************************************************************
     * description: Draws a wall on the SDL_Plotter screen at the specified location
     *              with a red inner color and a white border.
     * return: void
     * precondition: The SDL_Plotter object 'g' is initialized and ready for drawing.
     *               Parameters 'x_offset' and 'y_offset' specify the location to start
     *               drawing the wall. 'R', 'G', 'B' represent RGB color values (not used
     *               in this implementation).
     * postcondition: A wall is drawn on the screen at the specified location with a
     *                red inner color and a white border.
     *******************************************************************************
    */
    virtual void draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g,int)       const override;
    void testDraw(int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g) const;
};

//class ForestWall:public Wall{
//public:
//    void draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g)       const override{
//        drawTexture(x_offset,y_offset,FOREST_CONTAINER_SIZE,FOREST_CONTAINER_SIZE,fileName,g);
//    }
//};
//
//class DesertWall:public Wall{
//public:
//    void draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g)       const override{
//        drawTexture(x_offset,y_offset,DESERT_CONTAINER_SIZE,DESERT_CONTAINER_SIZE,fileName,g);
//    }
//};
//
//class UnderwaterWall:public Wall{
//public:
//    void draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g)       const override{
//        drawTexture(x_offset,y_offset,UNDERWATER_CONTAINER_SIZE,UNDERWATER_CONTAINER_SIZE,fileName,g);
//    }
//};

#endif /* Wall_h */
