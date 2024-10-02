//
//  EmptyContainer.h
//  Booths Brigade Project
//
//  Created by Cameron Hardin on 4/4/24.
//

#ifndef EmptyContainer_h
#define EmptyContainer_h

#include "Container.h"
#include "SDL_Plotter.h"
#include "Constants.h"
#include "drawTexture.h"

class EmptyContainer : public Container {
private:
    bool occupied;
public:
/*
     |EmptyContainer()|
     *******************************************************************************
     * description: Default constructor for an EmptyContainer object.
     * return: void
     * precondition: None
     * postcondition: An EmptyContainer object is created with the 'occupied' flag
     *                set to false.
     *******************************************************************************
    */
    EmptyContainer();
    /*
        |draw(int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g) const|
        *******************************************************************************
        * description: Draws an empty container on the SDL_Plotter screen at the
        *              specified location with a gray gradient effect.
        * return: void
        * precondition: The SDL_Plotter object 'g' must be initialized and ready for
        *               drawing. Parameters 'x_offset' and 'y_offset' specify the
        *               location to start drawing the container. 'R', 'G', 'B'
        *               represent the base RGB color values for the container.
        * postcondition: An empty container is drawn on the screen at the specified
        *                location with a gray gradient effect based on the x and y
        *                positions within the container size.
        *******************************************************************************
       */
    void draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g,int)   const override;
    /*
     |isOccupied() const|
     *******************************************************************************
     * description: Checks if the EmptyContainer is occupied.
     * return: bool - True if the container is occupied, false otherwise.
     * precondition: None
     * postcondition: Returns the value of the 'occupied' flag.
     *******************************************************************************
    */
    bool isOccupied() const override;
    /*
     |testDraw(int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g) const|
     *******************************************************************************
     * description: Helper function to draw an empty container with a gray gradient
     *              effect on the SDL_Plotter screen.
     * return: void
     * precondition: The SDL_Plotter object 'g' must be initialized and ready for
     *               drawing. Parameters 'x_offset' and 'y_offset' specify the
     *               location to start drawing the container. 'R', 'G', 'B'
     *               represent the base RGB color values for the container.
     * postcondition: Draws an empty container with a gray gradient effect at the
     *                specified location on the screen.
     *******************************************************************************
    */
    void testDraw(int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g) const;
};

/*class ForestEmptyContainer:public EmptyContainer{
public:
    void draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g)   const override{
        drawTexture(x_offset,y_offset,FOREST_CONTAINER_SIZE,FOREST_CONTAINER_SIZE,fileName,g);
    }
};
class DesertEmptyContainer:public EmptyContainer{
public:
    void draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g)   const override{
        drawTexture(x_offset,y_offset,DESERT_CONTAINER_SIZE,DESERT_CONTAINER_SIZE,fileName,g);
    }
};
class UnderwaterEmptyContainer:public EmptyContainer{
public:
    void draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g)   const override{
        drawTexture(x_offset,y_offset,UNDERWATER_CONTAINER_SIZE,UNDERWATER_CONTAINER_SIZE,fileName,g);
    }
};*/
#endif /* EmptyContainer_h */
