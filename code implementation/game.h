#ifndef _GAME_H_
#define _GAME_H_

#include <vector>
#include "board.h"
//#include "builder.h"

class Game {
    Board thisBoard;  // the board in the game
    // std::vector<Builder> builderList;  // builder (players) list

   public:
    void initializeGame(int inputReadMode, std::string fileName = "");
    void play();  // start the Game of Constructor
};

#endif