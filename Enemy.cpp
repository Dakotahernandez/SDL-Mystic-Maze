#include "Enemy.h"
Enemy::Enemy():avail(true),loc(0,0){};
void Enemy::setLoc()
{
    loc.x = maze_ptr->exitX-1;
    loc.y = maze_ptr->exitY;
}
void Enemy::resetLevel()
{
    //maze_ptr->setData(loc.x, loc.y, ' ');
    setLoc();
}
void Enemy::resetEnemy(Maze*& m)
{
    maze_ptr = m;
    setLoc();
    avail=true;
    createEnemy();
}
void Enemy::createEnemy()
{
    setLoc();
    //maze_ptr->setData(loc.x,loc.y,'E');
    //cout << "Enemy created" << endl;
}
void Enemy::pat(SDL_Plotter& g,string containerFile,int containerSize)
{
    maze_ptr->PartialDisplay(g,loc,containerFile,containerSize);
    maze_ptr->setData(loc.x,loc.y,' ');
    bool moved = false;
    if(loc.x == maze_ptr->exitX -1 && loc.y == maze_ptr->exitY)
    {
        loc.x--;
    }
    while(!moved){
        int dir = rand()%4;
        if(maze_ptr->getData()[loc.x-1][loc.y] == ' ' && dir == 0)
        {
            loc.x--;
            moved = true;
        }
        else if(maze_ptr->getData()[loc.x+1][loc.y] == ' '&& dir == 1)
        {
            loc.x++;
            moved = true;
        }
        else if(maze_ptr->getData()[loc.x][loc.y-1] == ' '&& dir == 2)
        {
            loc.y--;
            moved = true;
        }
        else if(maze_ptr->getData()[loc.x][loc.y+1] == ' '&& dir == 3)
        {
            loc.y++;
            moved = true;
        }
    }
    //cout << loc.x << " " << loc.y << endl;
    //maze_ptr->setData(loc.x,loc.y,'E');
    //maze_ptr->print();
}
void Enemy::display(SDL_Plotter& g,string eFile, int containerSize) const {
    if(avail)
    {
        int x_offset = BORDER_SIZE + (loc.x * containerSize);
        int y_offset = BORDER_SIZE + (loc.y * containerSize);

        drawTexture(x_offset,y_offset,containerSize,containerSize,eFile,g);
    }
}
bool Enemy::checkCollision(point p)
{
    if(loc.x == p.x && loc.y == p.y)
    {
        //maze_ptr->setData(loc.x, loc.y, ' ');
        return true;
    }
    return false;
}
