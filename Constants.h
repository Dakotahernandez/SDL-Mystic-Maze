#ifndef Constants_h
#define Constants_h

#include "SDL_Plotter.h"
#include <string>

// Universal Sizes
const int BORDER_SIZE                  = 75;
const int MAZE_SIZE                    = 600;//in Pixels!
const int WINDOW_SIZE                  = MAZE_SIZE + (2 * BORDER_SIZE); //1200 x 1200 window
const int CONTAINER_SIZE               = 25;
const int FOREST_CONTAINER_SIZE        = 25; //25x25 box
const int DESERT_CONTAINER_SIZE        = 20; //20x20 box
const int UNDERWATER_CONTAINER_SIZE    = 15; //15x15 box
const int FOREST_NUM_CONTAINERS        = MAZE_SIZE/FOREST_CONTAINER_SIZE;
const int DESERT_NUM_CONTAINERS        = MAZE_SIZE/DESERT_CONTAINER_SIZE;
const int UNDERWATER_NUM_CONTAINERS    = MAZE_SIZE/UNDERWATER_CONTAINER_SIZE;
const int NUM_CONTAINERS               = MAZE_SIZE / 25;
const int SIZEODECO                    = 25;

// Color Codes
const color BROWN                      (165,42,42);
const color RED                        (255,0,0);
const color BLUE                       (0,0,255);
const color GREEN                      (0,255,0);
const color _WHITE                     (255,255,255);
const color DARKG                      (0,100,0);
const color BLACK                      (0,0,0);
const color LIGHTBLUE                  (139,172,225);
const color NAVY                       (17,20,137);
const color YELLOW                     (255,246,63);
const color ORANGE                     (255,102,33);
const color DRED                       (180,0,0);
const color TAN                        (247,199,172);
const color GRAY                       (116,116,116);
const color SAND1                      (251,245,209);
const color SAND2                      (237,228,161);
const color SAND3                      (250,239,156);

// Texture Files
const string desBg                     = "desertBkg750x750.txt";
const string desChar                   = "desertCharacter20x20.txt";
const string desTile                   = "desertSand25x25.txt";
const string desWall                   = "desertWall25x25.txt";
const string desEnemy                  = "desertEnemy20x20.txt";
const string fstBg                     = "forestBkg750x750.txt";
const string fstChar                   = "forestCharacter25x25.txt";
const string fstTile                   = "forestEmptyContainer25x25.txt";
const string fstWall                   = "forestWall25x25.txt";
const string fstEnemy                  = "forestEnemy25x25.txt";
const string waterBg                   = "underwaterBkg750x750.txt";
const string waterChar                 = "underwaterCharacter15x15.txt";
const string waterTile                 = "underwaterEmptyContainer25x25.txt";
const string waterWall                 = "underwaterWall25x25.txt";
const string waterEnemy                = "underwaterEnemy15x15.txt";
const string ENDSCREENBG               = "endScreen750x750.txt";

// Sound Files
const string menuSoundtrack            = "menuSoundtrack.mp3";
const string forrestSoundtrack         = "forrestSoundtrack.mp3";
const string desertSoundtrack          = "desertSoundtrack.mp3";
const string waterSoundtrack           = "waterSoundtrack.mp3";

const string interactionSound          = "interactionSound.mp3";
const string collisionSound            = "collisionSound.mp3";

#endif  /* Constants_h*/
