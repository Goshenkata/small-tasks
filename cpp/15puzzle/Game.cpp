//
// Created by cirno on 07/09/23.
//

#include "Game.h"
#include "iostream"
#include "Random.h"

bool Game::isSolved() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (boardArr[i][j] != solvedBoardArr[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void Game::printBoard() {
    for (const auto &item: boardArr) {
        for (const auto &n: item) {
            if (n < 10) {
                if (n == 0) {
                    std::cout << "    ";
                } else {
                    std::cout << "  " << n << " ";
                }
            } else {
                std::cout << " " << n << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool Game::move(Game::MoveDirection direction) {
    switch (direction) {
        case UP:
            if (cords.row <= 0) {
                return false;
            } else {
                boardArr[cords.row][cords.col] = boardArr[cords.row - 1][cords.col];
                boardArr[cords.row - 1][cords.col] = 0;
                cords.row--;
                return true;
            }
        case DOWN:
            if (cords.row >= 3) {
                return false;
            } else {
                boardArr[cords.row][cords.col] = boardArr[cords.row + 1][cords.col];
                boardArr[cords.row + 1][cords.col] = 0;
                cords.row++;
                return true;
            }
        case LEFT:
            if (cords.col <= 0) {
                return false;
            } else {
                boardArr[cords.row][cords.col] = boardArr[cords.row][cords.col - 1];
                boardArr[cords.row][cords.col - 1] = 0;
                cords.col--;
                return true;
            }
        case RIGHT:
            if (cords.col >= 3) {
                return false;
            } else {
                boardArr[cords.row][cords.col] = boardArr[cords.row][cords.col + 1];
                boardArr[cords.row][cords.col + 1] = 0;
                cords.col++;
                return true;
            }
    }
}

Game::Game() {
    for (int i = 0; i < 1000; ++i) {
        auto direction = static_cast<MoveDirection>(Random::get(0,3));
        move(direction);
    }
}

