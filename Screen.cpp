/*
 * Authors: Briel F., Jonathan H., Cameron H., Dakota H., Ben C., Griffin R.
 * Assignment Title: Group Project: Mystic Maze
 * Assignment Description:
 * Due Date: 6/ /24
 * Date Created: 4/5/24
 * Date Last Modified: 5/27/24
*/
#include "Screen.h"
#include "Character.h"
#include "Constants.h"
#include "drawTexture.h"
#include "EmptyContainer.h"
#include "Enemy.h"
#include "interactable.h"
#include "Letter.h"
#include "Maze.h"
#include "Themes.h"
#include "Wall.h"
using namespace std;

void writeToScreen(const string& filename, int posX, int posY, int SizeOfFont, SDL_Plotter& homeScreen) {
    ifstream infile;
    string line, value;
    int col, r, g, b, row;
    col = r = g = b = row = 0;

    infile.open(filename);
    while (getline(infile, line)) {
        stringstream ss(line);
        col = 0;
        while (getline(ss, value, ',')) {
            int pixelValue = stoi(value);
            int pixelSize = SizeOfFont;
            if(pixelValue == 0){
                col++;
                continue;
            }
            r = 15;
            g = 15;
            b = 255;

            for (int i = 0; i <= row; i++) {
                r += 10;
                g += 12;
            }

            // Draw the pixel
            for (int x = 0; x < pixelSize; x++) {
                for (int y = 0; y < pixelSize; y++) {
                    homeScreen.plotPixel(posX + col * pixelSize + x, posY + row * pixelSize + y, r, g, b);
                }
            }
            col++;
        }
        row++;
    }
}

void drawStartScreen(SDL_Plotter& g) {
    button startButton(293, 281, 156, 55, {255, 0, 0});
    button leaderboardButton(215, 370, 315, 55, {0, 255, 0});
    button optionButton(278, 460, 199, 55, {99, 80, 0});
    button creditsButton(280, 550, 195, 55, {0, 0, 0});
    button backButton(30, 30, 30, 30, {0, 100, 0});
    button pauseButton(500, 500, 30, 30, {255, 0, 0});
    button closeGameButton(500, 700, 30, 30, {255, 0, 0});
    button adjustVolumeButton(400, 700, 30, 30, {0, 255, 0});
    button resumeGameButton(300, 700, 30, 30, {99, 80, 0});
    button continueButton(570, 690, 80, 30, {255, 0, 0});

    // draw the buttons
    startButton.draw(g);
    leaderboardButton.draw(g);
    optionButton.draw(g);
    creditsButton.draw(g);

    // print the words on the buttons
    drawTexture(0, 0, 750, 750, "Homescreen.txt", g);
    writeToScreen("MsticMza.csv", 180, 50, 8, g);
    writeToScreen("Start.csv", 215, 280, 3, g);
}

void startGame(SDL_Plotter& g) {
    drawTexture(0, 0, 750, 750, "Story750x750.txt", g);
    button continueButton(565, 690, 135, 30, {255, 0, 0});
    continueButton.draw(g);

    // file name, posX, posY, size, spacing (x-axis), spacing (y-axis), SDL screen
    readStoryFromFile("story.txt", 50, 200, 1.8, 14, 45, g);
    writeString("CONTINUE", 575, 700, 1.8, 13, 0, g);


    button pauseButton(565, 690, 135, 30, {0, 255, 0});
    pauseButton.draw(g);

}
void startStory(SDL_Plotter& g) {
    drawTexture(0, 0, 750, 750, "Story750x750.txt", g);
    button continueButton(565, 690, 135, 30, {255, 0, 0});
    continueButton.draw(g);

    // file name, posX, posY, size, spacing (x-axis), spacing (y-axis), SDL screen
    readStoryFromFile("story.txt", 50, 200, 1.8, 14, 45, g);
    writeString("CONTINUE", 575, 700, 1.8, 13, 0, g);

}

//The button still works despite going to a new page. Fix it
// Check button.cpp to see the code
void screenOperations(SDL_Plotter& g, bool& gameStarted) {
    button startButton(293, 281, 156, 55, {255, 0, 0});
    button leaderboardButton(215, 370, 315, 55, {0, 255, 0});
    button optionButton(278, 460, 199, 55, {99, 80, 0});
    button creditsButton(280, 550, 195, 55, {0, 0, 0});
    button backButton(30, 30, 30, 30, {0, 100, 0});
    button pauseButton(500, 500, 30, 30, {255, 0, 0});
    button closeGameButton(500, 700, 30, 30, {255, 0, 0});
    button adjustVolumeButton(400, 700, 30, 30, {0, 255, 0});
    button resumeGameButton(300, 700, 30, 30, {99, 80, 0});
    button continueButton(570, 690, 80, 30, {255, 0, 0});
//    button soundONButton();
//    button soundOffButton();
//    button musicOnButtonn();
//    button musicOffButton();

//    drawStartScreen(g);
//    cout << "poop" << endl;
    point x = g.getMouseClick();
    if (startButton.isClicked(x) && startButton.isClickable()) {
        g.clear();
        leaderboardButton.erase(g);
        optionButton.erase(g);
        creditsButton.erase(g);
        startButton.erase(g);
//        backButton.draw(g);
        //pauseButton.draw(g);
        gameStarted = true;
        return;
    }
    if (creditsButton.isClicked(x) && creditsButton.isClickable()) {
        g.clear();
        drawTexture(0, 0, 750, 750, "blueBkg750x750.txt", g);
        writeToScreen("credits.csv", 60, 100, 4, g);
        leaderboardButton.erase(g);
        optionButton.erase(g);
        creditsButton.erase(g);
        startButton.erase(g);
        backButton.draw(g);
    }
    if (leaderboardButton.isClicked(x) && leaderboardButton.isClickable()) {
        g.clear();
        drawTexture(0, 0, 750, 750, "blueBkg750x750.txt", g);
        writeToScreen("highscore.csv", 170, 60, 5, g);
        readStoryFromFile("highscore.txt", 140, 200, 4, 24, 44, g);
        startButton.erase(g);
        creditsButton.erase(g);
        leaderboardButton.erase(g);
        optionButton.erase(g);
        backButton.draw(g);
    }
    if (optionButton.isClicked(x) && optionButton.isClickable()) {
        g.clear();
        drawTexture(0, 0, 750, 750, "blueBkg750x750.txt", g);
        startButton.erase(g);
        creditsButton.erase(g);
        leaderboardButton.erase(g);
        optionButton.erase(g);
        backButton.draw(g);
        writeToScreen("options.csv", 70, 100, 4, g);
    }

    if (backButton.isClicked(x) && backButton.isClickable()) {
        g.clear();
        drawStartScreen(g);
        creditsButton.setIsClickable(true);
        leaderboardButton.setIsClickable(true);
        optionButton.setIsClickable(true);
        startButton.setIsClickable(true);
        backButton.erase(g);
    }
}

void endScreen(SDL_Plotter& g){
    button restartButton(265, 420, 215, 50, {255, 0, 255});
    button endButton(320, 550, 100, 50, {0, 0, 255});
    endButton.draw(g);
    restartButton.draw(g);
    drawTexture(0, 0, 750, 750, "Story750x750.txt", g);
    //writeToScreen("gameOver.csv", 130, 130, 10, g);
//    endButton.draw(g);
//    restartButton.draw(g);
//    writeString("RESTART", 275, 430, 4, 25, 0, g);
//    writeString("END", 330, 560, 4, 25, 0, g);
    writeString("PRESS ANY KEY TO CONTINUE...", 150, 460, 2.5, 15, 0, g);
    point x = g.getMouseClick();
    if(endButton.isClicked(x) && endButton.isClickable()){
        // erase buttons
        g.clear();
        drawStartScreen(g);
    }
    if(restartButton.isClicked(x) && restartButton.isClickable()){
        // erase buttons
        g.clear();
    }
}
/*
****************************************************************************

void Screen::endScreen(SDL_Plotter& g){
    button restartButton(265, 420, 215, 50, {255, 0, 255});
    button endButton(320, 550, 100, 50, {0, 0, 255});
    endButton.draw(g);
    restartButton.draw(g);
    drawTexture(0, 0, 750, 750, "txt/Story750x750.txt", g);
    writeToScreen("Letters/CSV sheets/gameOver.csv", 130, 130, 10, g);
//    endButton.draw(g);
//    restartButton.draw(g);
//    writeString("RESTART", 275, 430, 4, 25, 0, g);
//    writeString("END", 330, 560, 4, 25, 0, g);
    writeString("PRESS ANY KEY TO CONTINUE...", 150, 460, 2.5, 15, 0, g);
    point x = g.getMouseClick();
    if(endButton.isClicked(x) && endButton.isClickable()){
        // erase buttons
        g.clear();
        drawStartScreen(g);
        cout << "end";
    }
    if(restartButton.isClicked(x) && restartButton.isClickable()){
        // erase buttons
        g.clear();
        cout << "restart";
    }
}
****************************************************************************
*/
