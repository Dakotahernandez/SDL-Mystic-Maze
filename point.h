#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <cmath>
using namespace std;

struct point_t{
   double x,y;
    // if point is declared and its arguement is another point the point
    //is equal to that point
    point_t(const point_t& p){
       *this = p;
   }
    /*
     constructor
     if passed values are passed in they change x and y
     if not x and y are automatically 0
     */
    point_t(double x = 0, double y = 0){
        this->x = x;
        this->y = y;
    }

    //overload equal sign so it effects points
    point_t& operator= (const point_t& p){
       x = p.x;
       y = p.y;
       return *this;
   }
    /*
     caluclated distance between two points
     VERY IMPORTANT FOR COLLIIONS!!!
     */
   double distance(point_t p) const{
       return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
   }
};

#endif // POINT_H_INCLUDED
