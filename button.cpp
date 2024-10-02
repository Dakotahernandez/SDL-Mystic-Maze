/*
 * Authors: Briel F., Jonathan H., Cameron H., Dakota H., Ben C., Griffin R.
 * Assignment Title: Group Project: Mystic Maze
 * Assignment Description:
 * Due Date: 5/ /24
 * Date Created: 4/3/24
 * Date Last Modified: 4/11/24
*/
#include "button.h"

button::button(){
    x = y = width = height = 0;
    c = {255, 255, 255};
    clickable = true;
}
button::button(int xVal, int yVal, int width, int height, color col){
    this->x      = xVal;
    this->y      = yVal;
    this->width  = width;
    this->height = height;
    this->c      = col;
    clickable    = true;
}
bool button::isClicked(point p) const{
    //cout << p.x << " " << p.y << endl;
    return (p.x >= x && p.x <= x + width && p.y >= y && p.y <= y + height);
}
void button::draw(SDL_Plotter& g) const{
    // draw ONLY if the button is active
    for(int i = x; i < x + width; i++){
        for(int j = y; j < y + height; j++){
            g.plotPixel(i, j, c); // White
        }
    }
}
// huh. What was I thinking...
// OH I rember. Don't need this since the button is always gonna be white... probably
void button::erase(SDL_Plotter& g){
    x = y = width = height = 0;
    clickable = false;
}
void button::setIsClickable(bool clickable){
    this->clickable = clickable;
}
bool button::isClickable() const {
    return clickable;
}
void button::remove(){
    x = y = width = height = 0;
    clickable = false;
}
