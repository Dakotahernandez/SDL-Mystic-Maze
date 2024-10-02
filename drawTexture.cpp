//
// Created by jhump on 4/14/2024.
//

#include "drawTexture.h"

typedef vector<vector<vector<int>>> rgbV;

void drawTexture(int xloc, int yloc, int xPixels, int yPixels, const string& fileName, SDL_Plotter& g){

    int R, G, B;
    //Opening File
    fstream inputFile;
    inputFile.open(fileName);//opening .txt file called inputFile
    assert(inputFile);

    R = G = B = 120;
    for(int y = 0; y < yPixels; y++){   //prints from .txt file, top down
        for(int x = 0; x < xPixels; x++){
            inputFile >> R;
            inputFile >> G;
            inputFile >> B;
            //if(y < yPixels-1) inputFile >> delimiter;
            g.plotPixel(x + xloc, y + yloc, R, G, B);
        }
    }

    inputFile.close();

}
//Creates a 3D vector if integers using 25x25 or 750x750 file
void rgbArray(const string fileName, vector<vector<vector<int>>>& resultVector){
    int size = 0;
    if(fileName.substr(fileName.size() - 7, 3) == "750"){   //For 750 size
        size = 750;
    }
    else if(fileName.substr(fileName.size() - 6, 2) == "25"){ //For 25 size
        size = 25;
    }
    else{
        cout << "BAD FILE SIZE: " << fileName << endl;
    }

    resultVector.resize(size);  //A 3D vector of int
    ifstream inFile;
    int R, G, B;

    inFile.open(fileName);
    assert(inFile);

    for(int i = 0; i < size; i++){
        resultVector[i] = vector<vector<int>>(size);
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            resultVector[i][j] = vector<int>(3);
        }
    }

    R = G = B = 120;
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            inFile >> R;
            inFile >> G;
            inFile >> B;
            resultVector[x][y].at(0) = R;
            resultVector[x][y].at(1) = G;
            resultVector[x][y].at(2) = B;
        }
    }

    inFile.close();

}
