//
// Created by cirno on 07/09/23.
//

#ifndef INC_15PUZZLE_GAME_H
#define INC_15PUZZLE_GAME_H

#include "array"

struct Cords {
    int row;
    int col;
};

class Game {
private:
    using BoardArr = std::array<std::array<int, 4>, 4>;
    BoardArr solvedBoardArr = {{
                                       {1, 2, 3, 4},
                                       {5, 6, 7, 8},
                                       {9, 10, 11, 12},
                                       {13, 14, 15, 0}
                               }};
    BoardArr boardArr{solvedBoardArr};
    Cords cords = {3, 3};
public:
    enum MoveDirection {
        UP, DOWN, LEFT, RIGHT
    };

    bool isSolved();

    void printBoard();

    bool move(MoveDirection direction);
    Game();
};


#endif //INC_15PUZZLE_GAME_H
