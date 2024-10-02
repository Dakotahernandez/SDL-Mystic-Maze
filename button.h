/*
 * Authors: Briel F., Jonathan H., Cameron H., Dakota H., Ben C., Griffin R.
 * Assignment Title: Group Project: Mystic Maze
 * Assignment Description:
 * Due Date: 6/ /24
 * Date Created: 4/3/24
 * Date Last Modified: 5/27/24
*/
#ifndef BOOTHSSBRIGADE_BUTTON_H
#define BOOTHSSBRIGADE_BUTTON_H
#include "SDL_Plotter.h"
class button{
private:
    int x, y, width, height;
    color c;
    bool clickable;

public:
    button();
    button(int, int, int, int, color);
    bool isClicked(point) const;
    void draw(SDL_Plotter&) const;
    void erase(SDL_Plotter&);
    void setIsClickable(bool);
    bool isClickable() const;
    void remove();
};
#endif //BOOTHSSBRIGADE_BUTTON_H
