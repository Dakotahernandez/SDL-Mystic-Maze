#include <stdio.h>
#include "interactable.h"
Key::Key():avail(true),loc(0,0){};
point Key::setLoc()
{
    loc.x=0;
    loc.y =0;
    int i=0, j=0;
    while(maze_ptr->getData()[i][j] != ' ')
    {
        i = rand()%NUM_CONTAINERS;
        j = rand()%NUM_CONTAINERS;
    }
    loc.x = i;
    loc.y =j;
    //cout << i << " " << j << endl;
    return loc;
}
void Key::resetLevel()
{
    //maze_ptr->setData(loc.x, loc.y, ' ');
    avail = true;
    createKey();

}
void Key::resetKey(Maze*& m)
{
    maze_ptr = m;
    loc.x =0;
    loc.y =0;
    avail=true;
    createKey();
}
void Key::createKey()
{
    loc = setLoc();
    //maze_ptr->setData(loc.x,loc.y,'K');
    maze_ptr->setData(maze_ptr->exitX,maze_ptr->exitY, '1');
    //cout << "key Created" << endl;
    maze_ptr->print(25); //TEMP 25
}
void Key::display(SDL_Plotter& g, int containerSize) const {
    if(avail)
    {
        // Calculate the pixel offsets taking into account the border size directly
        int x_offset = BORDER_SIZE + (loc.x * containerSize);
        int y_offset = BORDER_SIZE + (loc.y * containerSize);

        if(containerSize==FOREST_CONTAINER_SIZE){
            drawTexture(x_offset,y_offset,25,25,"forestKey25x25.txt",g);
        }
        else if(containerSize==DESERT_CONTAINER_SIZE){
            drawTexture(x_offset,y_offset,20,20,"desertKey20x20.txt",g);
        }
        else{ //UNDERWATER
            drawTexture(x_offset,y_offset,15,15,"underwaterKey15x15.txt",g);
        }

    }
}
void Key::checkCollision(point p)
{
    if(loc.x == p.x && loc.y == p.y)
    {
        avail = false;
        //maze_ptr->setData(loc.x, loc.y, ' ');
        maze_ptr->setData(maze_ptr->exitX,maze_ptr->exitY, ' ');
    }
}




trapDoor::trapDoor(Character* playa):avail(true),loc(0,0),character_ptr(playa){};

point trapDoor::setLoc(){
    loc.x=0;
    loc.y =0;
    int i=0, j=0;
    while(maze_ptr->getData()[i][j] != ' ')
    {
        i = rand()%NUM_CONTAINERS;
        j = rand()%NUM_CONTAINERS;
    }
    loc.x = i;
    loc.y = j;
    cout << i << " " << j << endl;

    return loc;
}
void trapDoor::resetTrap(Maze*& m){
    maze_ptr = m;
    loc.x =0;
    loc.y =0;
    avail=true;
    createTrap();
}
void trapDoor::createTrap(){
    loc = setLoc();
    maze_ptr->setData(loc.x,loc.y,'K');
    maze_ptr->setData(maze_ptr->exitX,maze_ptr->exitY, '1');
    cout << "Trap Created" << endl;
    maze_ptr->print(25);
}
void trapDoor::display(SDL_Plotter& g,int containerSize) const {
    if(avail){
        int x_offset = BORDER_SIZE + (loc.x * containerSize);
        int y_offset = BORDER_SIZE + (loc.y * containerSize);
        drawTexture(x_offset, y_offset, containerSize, containerSize, "underwaterWall25x25.txt",g);
    }

}
void trapDoor::checkCollision(point p){
    //cout << "collision!!! WITH TRAP" << endl;
    if(loc.x == p.x && loc.y == p.y){
        avail = false;
        maze_ptr->setData(loc.x, loc.y, ' ');
        int i=0, j=0;
        while(maze_ptr->getData()[i][j] != ' ')
        {
            i = rand()%NUM_CONTAINERS;
            j = rand()%NUM_CONTAINERS;
        }
        character_ptr->setLoc(i, j);
    }
}
