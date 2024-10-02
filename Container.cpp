//
//  Container.cpp
//  Booths Brigade Project
//
//  Created by Cameron Hardin on 4/4/24.
//

#include "Container.h"
#include "SDL_Plotter.h"

void Container::draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g,int containerSize) const {
    throw("Called draw() on a pure abstract class");
}     //Drawing should not change the object
bool Container::isOccupied() const {
    throw("Called isOccupied() on a pure abstract class");
}
