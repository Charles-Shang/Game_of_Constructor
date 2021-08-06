/*
 * Name: Yifan Qu and Jiaqi Shang
 * Course: CS 246
 * Term: Spring 2021
 * Final Project: Game of Constructor
 */

#include <stdio.h>
#include <fstream>
#include <iostream>
#include "game.h"

using std::cin;
using std::string;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " needs a layout.txt file."
                  << std::endl;
        return 1;
    }

    Game g;
    g.initializeGame(4, argv[1]);
    g.play();
}
