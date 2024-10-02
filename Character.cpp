//
//  Character.h
//  Booths Brigade Project
//
//  Created by Cameron Hardin on 4/11/24.

//if maze has a character then character cant get out of maze
// Make character its own separate object not controlled by maze,
// in main have its own display and update

#include "Character.h"
Character::Character() {
    cout << ("Character created without a given maze") << endl;
}
void Character::resetChar(Maze*& m)
{
    maze_ptr = m;
    loc.x = maze_ptr->entranceX;
    loc.y = maze_ptr->entranceY;
    //maze_ptr->setData(loc.x, loc.y, 'C');
}
void Character::resetLevel()
{
    //maze_ptr->setData(loc.x, loc.y, ' ');
    loc.x = maze_ptr->entranceX;
    loc.y = maze_ptr->entranceY;
    //maze_ptr->setData(loc.x, loc.y, 'C');

}
point Character::getLoc()
{
    return loc;
}
/*void Character::draw(int x_offset, int y_offset, int R, int G, int B, SDL_Plotter& g) const {
    for(int x=0; x < CONTAINER_SIZE; x++) {
        for(int y=0; y < CONTAINER_SIZE; y++) {
            g.plotPixel(x + x_offset, y + y_offset, 0, 255, 0);
        }
    }
    //Displays as a green square for now
}*/

void Character::display(string fileName, SDL_Plotter& g, int containerSize) const {

    // Calculate the pixel offsets taking into account the border size directly
    int x_offset = BORDER_SIZE + (loc.x * containerSize);
    int y_offset = BORDER_SIZE + (loc.y * containerSize);

    drawTexture(x_offset,y_offset,containerSize,containerSize,fileName,g);

}

void Character::move(bool& did_move, char keyPress, SDL_Plotter& g,string containerFile,int containerSize, int numContainers) {
    //cout << "Move() called" << endl;
    int newX = loc.x;
    int newY = loc.y;

    switch (keyPress) {
        case 'w': newY--; break;
        case 'a': newX--; break;
        case 's': newY++; break;
        case 'd': newX++; break;
    }
    if (!outOfBounds(newX, newY,containerSize,numContainers)) {  // Check if not out of screen
        //cout << "current X,Y: " << loc.x << ", " << loc.y << endl;
        //cout << "new X,Y: " << newX << ", " << newY << endl;
        if (isInMaze(newX, newY,numContainers)) {  // Check if within maze bounds
            char new_char = maze_ptr->getData()[newX][newY];
            if (isAvailable(new_char)) {
                if(isInMaze(loc.x, loc.y,numContainers)) { //not if reentering maze
                    //maze_ptr->setData(loc.x, loc.y, ' ');  // Clear old position
                    maze_ptr->PartialDisplay(g,loc,containerFile,containerSize);
                }
                //maze_ptr->setData(newX, newY, 'C');    // Move to new position
                loc.x = newX;
                loc.y = newY;
                did_move = true;
            }
        }
        else {
            //cout << "Out of maze but in bounds" << endl;
            loc.x = newX;
            loc.y = newY;
            did_move = true;
        }
    }
    //maze_ptr->print();
}

bool Character::isInMaze(int x, int y, int numContainers) const {
    bool inMaze = (x >= 0 && x < numContainers && y >= 0 && y < numContainers);
    if(!inMaze) {
        //cout << "Character is not in maze" << endl;
    }
    return x >= 0 && x < numContainers && y >= 0 && y < numContainers;
}

bool Character::isAvailable(const char& c) { //Given a character from the maze
    bool available = false;

    if(c != '1') { //if its not a wall
        available = true;
    }
    return available;
}

bool Character::outOfBounds(int newX, int newY,int containerSize, int numContainers) const {
    // Calculate total size including borders
    int spacer = BORDER_SIZE/containerSize;
    int totalSize = numContainers + 2 * spacer;
    if (newX < (-1*spacer) || newX > totalSize || newY < (-1*spacer) || newY > totalSize) {
        //cout << "Tried to move out of bounds" << endl;
        return true;
    }
    return false;
}

void Character::setLoc(int newX, int newY ){
    loc.x = newX;
    loc.y = newY;
}
