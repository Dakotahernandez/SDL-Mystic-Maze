//
//  EmptyContainer.cpp
//  Booths Brigade Project
//
//  Created by Cameron Hardin on 4/4/24.
//

#include "EmptyContainer.h"
#include "Constants.h"
#include "SDL_Plotter.h"
#include "drawTexture.h"

EmptyContainer::EmptyContainer():occupied(false) {}

void EmptyContainer::draw(string fileName, int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g,int containerSize) const {
    drawTexture(x_offset,y_offset,containerSize,containerSize,fileName,g);
}

bool EmptyContainer::isOccupied() const {
    return occupied;
}
