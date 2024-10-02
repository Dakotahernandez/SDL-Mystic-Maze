//
// Created by jhump on 4/14/2024.
//

#ifndef GROUP_PROJECT_DRAWTEXTURE_H
#define GROUP_PROJECT_DRAWTEXTURE_H

#include "SDL_Plotter.h"
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
/*
 |drawTexture(int xloc, int yloc, int xPixels, int yPixels, const string& fileName, SDL_Plotter& g)|
 *******************************************************************************
 * description: Draws a texture from a specified .txt file onto the SDL_Plotter screen
 *              at the specified location with the given dimensions.
 * return: void
 * precondition: The SDL_Plotter object 'g' is initialized and ready for drawing.
 *               Parameters 'xloc' and 'yloc' specify the top-left corner location
 *               to start drawing the texture. 'xPixels' and 'yPixels' specify the
 *               dimensions (width and height) of the texture. 'fileName' is a string
 *               representing the name of the .txt file containing RGB color values.
 * postcondition: Draws the texture onto the screen using the color values read from
 *                the specified .txt file.
 *******************************************************************************
*/

void drawTexture(int xloc, int yloc, int xPixels, int yPixels, const string& fileName, SDL_Plotter& g);

//Description: Draws a texture from 3D vector onto screen
//Return: void
//Precondition: g is initialized, x and y are specified, rgbVector has rgb values
//Postcondition: Draws texture onto screen from specified file values

void newDrawTexture(int xloc, int yloc, int xPixels, int yPixels, vector<vector<vector<int>>>& rgbVector, SDL_Plotter& g);

//Description: Takes in rgb values from file and puts them in a vector
//Return: 3D vector of int
//Precondition: txt file of rgb values (file name ends with 25 or 750)
//Postcondition: An array is returned with rgb values for each pixel

void rgbArray(const string fileName,vector<vector<vector<int>>>& resultVector);


#endif //GROUP_PROJECT_DRAWTEXTURE_H
