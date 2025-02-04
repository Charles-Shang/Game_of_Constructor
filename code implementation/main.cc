/*
 * Name: Yifan Qu and Jiaqi Shang
 * Course: CS 246
 * Term: Spring 2021
 * Final Project: Game of Constructor
 */

#include <stdio.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include "game.h"

int main(int argc, char* argv[]) {
    bool load = false, board = false, randomBoard = false;
    bool systemBasedTime = false;
    std::string loadedFile, boardFile, finalFile = "layout.txt";
    int decision = 4;

    unsigned seed = 1000;

    for (int i = 1; i < argc; i++) {
        std::string flags{argv[i]};
        if (flags == "-seed") {
            try {
                seed = std::stoi(std::string{argv[++i]});
            } catch (std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
                return 1;
            } catch (std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
                return -1;
            }
        } else if (flags == "-load") {
            load = true;
            decision = 1;
            loadedFile = std::string{argv[++i]};
        } else if (flags == "-board") {
            board = true;
            decision = 2;
            boardFile = std::string{argv[++i]};
        } else if (flags == "-random-board") {
            decision = 3;
            randomBoard = true;
        } else if (flags == "-random-seed") {
            systemBasedTime = true;
        }
    }

    if (systemBasedTime)
        seed = std::chrono::system_clock::now().time_since_epoch().count();

    if (load && board) {
        while (true) {
            std::cout << "Only 'load' or 'board', choose again." << std::endl;
            std::string temp;

            try {
                std::cin >> temp;
            } catch (std::ios::failure& e) {
                if (std::cin.eof()) break;
                std::cin.clear();
                std::cin.ignore();
            }

            if (temp == "load") {
                finalFile = loadedFile;
                randomBoard = false;
                decision = 1;
                board = false;
                break;
            } else if (temp == "board") {
                finalFile = boardFile;
                randomBoard = false;
                decision = 2;
                load = false;
                break;
            }
        }
    }

    std::ifstream defaultFile{finalFile};

    if (defaultFile.fail() && !board && !load && !randomBoard) {
        std::cout << finalFile << " does not exists!" << std::endl;
        std::cout << "Do you want to use a random board? (Y/N)" << std::endl;
        std::string answer;
        while (true) {
            std::cout << "¿ ";
            std::cin >> answer;
            if (answer == "y" || answer == "Y") {
                randomBoard = true;
                decision = 3;
            } else if (answer == "n" || answer == "N") {
                std::cout << "Alright! Good Bye!!" << std::endl;
                return 0;
            } else {
                std::cout << "Invalid command! Try with Y or N!" << std::endl;
            }
        }
    }

    std::default_random_engine rng{seed};

    if (decision == 1) {
        finalFile = loadedFile;
    } else if (decision == 2) {
        finalFile = boardFile;
    }

    Game g{rng};
    g.initializeGame(decision, finalFile);
    if (load) {
        std::cout << "Loaded Game starts!" << std::endl;
    } else {
        std::cout << "New Game starts!" << std::endl;
    }
    int firstResult = g.play(load);
    if (firstResult) {
        std::cout << "New Game starts!" << std::endl;
        while (g.play()) {
            std::cout << "New Game starts!" << std::endl;
            g.initializeGame(decision, finalFile);
        }
    }

    std::cout << " Bye!" << std::endl;
}
