/*
Authors: Briel Finley
Assignment Title: Group project: Mystic Maze
Assignment Description:
Due Date:
Date Created: 2/27/24
Date Last Modified: 3/7/24
 */
#ifndef GROUPPROJECT_LETTERS_H
#define GROUPPROJECT_LETTERS_H
#include "SDL_Plotter.h"
#include <fstream>
#include <vector>
#include <map>
using namespace std;

/*
 * grabs a string, deciphers what each UPPER CASE letter is and plots it to the screen depending on the 0's and 1's
provided in the 2d vector
 * posX refers to where on the X axis the string prints on the screen
 * posY refers to where on the Y axis the string prints on the screen
 * pixelSize is the size of the font. VERY sensitive. even changing it by .5 is a drastic change.
 * spacingX refers to how spread out the letters are on the X axis  // BOTH DEPENDANT ON PIXELSIZE
 * spacingY refers to how spread out the letters are onn the Y axis // BOTH DEPENDANT ON PIXELSIZE
*/
void writeString(const string& text, int posX, int posY, double pixelSize, int spacingX, int spacingY, SDL_Plotter& g) {
    int col = 0;
    int row = 0;

    // iterates through the text until the newLine then increments the row and restarts the count for column
    for (char c : text) {
        if (c == '\n') {
            col = 0;
            row++;
        }
        const vector<vector<int>> letterDot = {
                {0,0,0},
                {0,0,0},
                {0,0,0},
                {0,0,0},
                {0,0,0},
                {0,0,0},
                {0,0,1}
        };
        const vector<vector<int>> letterComma = {
                {0,0,0},
                {0,0,0},
                {0,0,0},
                {0,0,0},
                {0,0,1},
                {0,0,1},
                {0,1,1},
                {1,1,0}
        };
        const vector<vector<int>> letterA = {
                {0,0,1,1,0,0},
                {0,1,0,0,1,0},
                {1,0,0,0,0,1},
                {1,1,1,1,1,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1}
        };
        const vector<vector<int>> letterB = {
                {1,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,1,1,1,1,0}
        };

        const vector<vector<int>> letterC = {
                {0,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,1,1,1,0}
        };
        const vector<vector<int>> letterD = {
                {1,1,1,1,0,0},
                {1,0,0,0,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,1,0},
                {1,1,1,1,0,0}
        };
        const vector<vector<int>> letterE = {
                {1,1,1,1,1,1},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,1,1,1,0,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,1,1,1,1,1}
        };
        const vector<vector<int>> letterF = {
                {1,1,1,1,1,1},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,1,1,1,1,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0}
        };
        const vector<vector<int>> letterG = {
                {0,1,1,1,1,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,0},
                {1,0,0,1,1,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,1,1,1,0}
        };
        const vector<vector<int>> letterH = {
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,1,1,1,1,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1}
        };
        const vector<vector<int>> letterI = {
                {1,1,1,1,1},
                {0,0,1,0,0},
                {0,0,1,0,0},
                {0,0,1,0,0},
                {0,0,1,0,0},
                {0,0,1,0,0},
                {1,1,1,1,1}
        };
        const vector<vector<int>> letterJ = {
                {0,0,0,0,0,1},
                {0,0,0,0,0,1},
                {0,0,0,0,0,1},
                {0,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,1,1,1,0}
        };
        const vector<vector<int>> letterK = {
                {1,0,0,0,1,0},
                {1,0,0,1,0,0},
                {1,0,1,0,0,0},
                {1,1,0,0,0,0},
                {1,0,1,0,0,0},
                {1,0,0,1,0,0},
                {1,0,0,0,1,0}
        };
        const vector<vector<int>> letterL = {
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,1,1,1,1,1}
        };
        const vector<vector<int>> letterM = {
                {1,0,0,0,0,1},
                {1,1,0,0,1,1},
                {1,0,1,1,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1}
        };
        const vector<vector<int>> letterN = {
                {1,0,0,0,0,1},
                {1,1,0,0,0,1},
                {1,0,1,0,0,1},
                {1,0,0,1,0,1},
                {1,0,0,0,1,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1}
        };
        const vector<vector<int>> letterO = {
                {0,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,1,1,1,0},
        };
        const vector<vector<int>> letterP = {
                {1,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,1,1,1,1,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0}
        };

        const vector<vector<int>> letterQ = {
                {0,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,1,0,0,1},
                {1,0,0,1,1,0},
                {0,1,1,0,1,0}
        };
        const vector<vector<int>> letterR = {
                {1,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,1,1,1,1,0},
                {1,0,0,0,1,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
        };
        const vector<vector<int>> letterS = {
                {0,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,0},
                {0,1,1,1,1,0},
                {0,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,1,1,1,0},
        };
        const vector<vector<int>> letterT = {
                {1,1,1,1,1,1},
                {0,0,1,0,0,0},
                {0,0,1,0,0,0},
                {0,0,1,0,0,0},
                {0,0,1,0,0,0},
                {0,0,1,0,0,0},
                {0,0,1,0,0,0}
        };

        const vector<vector<int>> letterU = {
                {1,0,0,0,1,0},
                {1,0,0,0,1,0},
                {1,0,0,0,1,0},
                {1,0,0,0,1,0},
                {1,0,0,0,1,0},
                {1,0,0,0,1,0},
                {0,1,1,1,0,0}
        };

        const vector<vector<int>> letterV = {
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,0,0,1,0},
                {0,0,1,1,0,0}
        };

        const vector<vector<int>> letterW = {
                {1,0,0,0,0,0,1},
                {1,0,0,0,0,0,1},
                {1,0,0,0,0,0,1},
                {1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1},
                {1,0,0,1,0,0,1},
                {0,1,0,0,0,1,0}
        };
        const vector<vector<int>> letterX = {
                {1,0,0,0,0,1},
                {0,1,0,0,1,0},
                {0,0,1,0,0,0},
                {0,0,0,1,0,0},
                {0,0,1,0,0,0},
                {0,1,0,0,1,0},
                {1,0,0,0,0,1}
        };

        const vector<vector<int>> letterY = {
                {1,0,0,0,0,1},
                {0,1,0,0,1,0},
                {0,0,1,1,0,0},
                {0,0,0,1,0,0},
                {0,0,0,1,0,0},
                {0,0,0,1,0,0},
                {0,0,0,1,0,0},
        };
        const vector<vector<int>> letterZ = {
                {1,1,1,1,1,1},
                {0,0,0,0,0,1},
                {0,0,0,0,1,0},
                {0,0,0,1,0,0},
                {0,0,1,0,0,0},
                {0,1,0,0,0,0},
                {1,1,1,1,1,1}
        };
        const vector<vector<int>> letter0 = {
                {0,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,1,1,1,0}
        };

        const vector<vector<int>> letter1 = {
                {0,0,0,1,0,0},
                {0,0,1,1,0,0},
                {0,1,0,1,0,0},
                {1,0,0,1,0,0},
                {0,0,0,1,0,0},
                {0,0,0,1,0,0},
                {1,1,1,1,1,1}
        };

        const vector<vector<int>> letter2 = {
                {0,1,1,1,1,0},
                {1,0,0,0,0,1},
                {0,0,0,0,0,1},
                {0,0,0,0,1,0},
                {0,0,0,1,0,0},
                {0,0,1,0,0,0},
                {1,1,1,1,1,1}
        };
        const vector<vector<int>> letter3 = {
                {1,1,1,1,1,1},
                {0,0,0,0,0,1},
                {0,0,0,0,1,0},
                {0,0,0,1,0,0},
                {0,0,0,0,1,0},
                {0,0,0,0,0,1},
                {1,1,1,1,1,0}
        };

        const vector<vector<int>> letter4 = {
                {0,0,0,0,1,0},
                {0,0,0,1,1,0},
                {0,0,1,0,1,0},
                {0,1,0,0,1,0},
                {1,1,1,1,1,1},
                {0,0,0,0,1,0},
                {0,0,0,0,1,0}
        };

        const vector<vector<int>> letter5 = {
                {1,1,1,1,1,1},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,1,1,1,1,0},
                {0,0,0,0,0,1},
                {0,0,0,0,0,1},
                {1,1,1,1,1,0}
        };
        const vector<vector<int>> letter6 = {
                {0,1,1,1,1,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,1,1,1,0}
        };

        const vector<vector<int>> letter7 = {
                {1,1,1,1,1,1},
                {0,0,0,0,0,1},
                {0,0,0,0,1,0},
                {0,0,0,1,0,0},
                {0,0,1,0,0,0},
                {0,1,0,0,0,0},
                {1,0,0,0,0,0}
        };

        const vector<vector<int>> letter8 = {
                {0,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,1,1,1,0}
        };

        const vector<vector<int>> letter9 = {
                {0,1,1,1,1,0},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {0,1,1,1,1,1},
                {0,0,0,0,0,1},
                {0,0,0,0,0,1},
                {0,1,1,1,1,0}
        };
    // store in a 2d vector
        vector<vector<int>> alphabet;
        switch (c) {
            case 'A':
                alphabet = letterA;
                break;
            case 'B':
                alphabet = letterB;
                break;
            case 'C':
                alphabet = letterC;
                break;
            case 'D':
                alphabet = letterD;
                break;
            case 'E':
                alphabet = letterE;
                break;
            case 'F':
                alphabet = letterF;
                break;
            case 'G':
                alphabet = letterG;
                break;
            case 'H':
                alphabet = letterH;
                break;
            case 'I':
                alphabet = letterI;
                break;
            case 'J':
                alphabet = letterJ;
                break;
            case 'K':
                alphabet = letterK;
                break;
            case 'L':
                alphabet = letterL;
                break;
            case 'M':
                alphabet = letterM;
                break;
            case 'N':
                alphabet = letterN;
                break;
            case 'O':
                alphabet = letterO;
                break;
            case 'P':
                alphabet = letterP;
                break;
            case 'Q':
                alphabet = letterQ;
                break;
            case 'R':
                alphabet = letterR;
                break;
            case 'S':
                alphabet = letterS;
                break;
            case 'T':
                alphabet = letterT;
                break;
            case 'U':
                alphabet = letterU;
                break;
            case 'V':
                alphabet = letterV;
                break;
            case 'W':
                alphabet = letterW;
                break;
            case 'X':
                alphabet = letterX;
                break;
            case 'Y':
                alphabet = letterY;
                break;
            case 'Z':
                alphabet = letterZ;
                break;
            case '.':
                alphabet = letterDot;
                break;
            case ',':
                alphabet = letterComma;
                break;
            case '0':
                alphabet = letter0;
                break;
            case '1':
                alphabet = letter1;
                break;
            case '2':
                alphabet = letter2;
                break;
            case '3':
                alphabet = letter3;
                break;
            case '4':
                alphabet = letter4;
                break;
            case '5':
                alphabet = letter5;
                break;
            case '6':
                alphabet = letter6;
                break;
            case '7':
                alphabet = letter7;
                break;
            case '8':
                alphabet = letter8;
                break;
            case '9':
                alphabet = letter9;
                break;

                // Add the rest of the letters DONE
                // Also add the numbers
            default:
                break;
        }

        // Plot the letter
        for (int i = 0; i < alphabet.size(); i++) {
            for (int j = 0; j < alphabet[i].size(); j++) {
                if (alphabet[i][j] == 1 ) {

                    int plotPosX = posX + col * (pixelSize + spacingX) + j * pixelSize;
                    int plotPosY = posY + row * (pixelSize + spacingY) + i * pixelSize;

                    // Plot the pixel
                    for (int k = 0; k < pixelSize; k++) {
                        for (int l = 0; l < pixelSize; l++) {
                            g.plotPixel(plotPosX + k, plotPosY + l, {255, 255, 255});
                        }
                    }
                }
            }
        }

        col++; // Move to the next column since I put it to 0 earlier
    }
}


/*
 * reads the data from a file and uses the writeString function to print the words to the screen
 */
void readStoryFromFile(const string& filename, int posX, int posY, double size, int spacingX, int spacingY, SDL_Plotter& g) {
    ifstream infile(filename);
    assert(infile.is_open());

    string line, upperCase;
    while (getline(infile, line)) {
        // code for the words to be upper and lower case. MESSES WITH THE OUTPUT, DON'T UNCOMMENT PLS
        //for(char c : line){ upperCase += toupper(c);}

        writeString(line, posX, posY, size, spacingX, spacingY, g);
        posY += (size + spacingY);
    }

    infile.close();
}

#endif //GROUPPROJECT_LETTERS_H
