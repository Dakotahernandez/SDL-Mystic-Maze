//
//  Container.h
//  Booths Brigade Project
//
//  Created by Cameron Hardin on 4/4/24.
//

#ifndef Container_h
#define Container_h

#include "SDL_Plotter.h"

/*
 Description:
    A container just holds any object that belongs in maze;
 */

class Container {   //Pure Abstract Class
public:
    /*
          * Description: Draws the Container object with specified color on the SDL_Plotter
          *              screen at the given offset.
          * Parameters:
          *     - x_offset: Horizontal offset for drawing.
          *     - y_offset: Vertical offset for drawing.
          *     - R, G, B: Color components (Red, Green, Blue) for drawing.
          *     - g: Reference to an initialized SDL_Plotter object for drawing.
          * Return:
          *     - void
          * Precondition: The SDL_Plotter object 'g' must be initialized and ready for
          *               drawing.
          * Postcondition: The Container object is displayed on the screen at the specified
          *                location with the given color within the maze.
          */
    virtual void draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g,int)       const = 0; //Drawing should not change the object
/*
        |isOccupied() const|
        *******************************************************************************
        * Description: Checks if the Container is occupied.
        * Return:
        *     - bool: True if there is a constructed object (including empty), otherwise false.
        *******************************************************************************
        */
    virtual bool isOccupied() const = 0; //Returns true if there is a constructed object (including empty)
};

#endif /* Container_h */
