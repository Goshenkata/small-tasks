#include <iostream>
#include "Game.h"

Game::MoveDirection getInput();

int main() {
    Game game{};
    game.printBoard();
    int turns{0};
    while (!game.isSolved()) {
        auto direction = getInput();
        if (!game.move(direction)) {
            std::cout << "Cannot move in this direction!\n";
        } else {
            game.printBoard();
            turns++;
        }
        std::cout << std::endl;
    }
    std::cout << "Game completed in " << turns << " turns!\n";
    return 0;
}

Game::MoveDirection getInput() {
    std::cout << "Where would you like to move (wasd): ";
    char c{};
    std::cin >> c;
    c = (char) tolower(c);
    switch (c) {
        case 'w':
            return Game::UP;
        case 's':
            return Game::DOWN;
        case 'a':
            return Game::LEFT;
        case 'd':
            return Game::RIGHT;
        default:
            std::cout << "Invalid input!\n";
            getInput();
    }

}
