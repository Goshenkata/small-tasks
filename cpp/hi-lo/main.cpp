#include <iostream>
#include "Random.h"

int getNumberFromUser();

int main() {
    int number{Random::get(0, 100)};
    char yesNo{};
    bool hasWon{};

    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";

     do {
        for (int i = 1; i <= 7; ++i) {
            std::cout << "Guess #" << i << ": ";
            int guess{ getNumberFromUser()};
            if (guess < number) {
                std::cout << "Your guess is too low.\n";
            } else if (guess > number) {
                std::cout << "Your guess is too high.\n";
            } else {
                hasWon = true;
                break;
            }
        }
        if (hasWon) {
            std::cout << "Correct! You win!";
        } else {
            std::cout << "Sorry, you lose. The correct number was " << number << ".\n";
        }
        hasWon = false;
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> yesNo;
    } while (yesNo == 'y');
    return 0;
}

int getNumberFromUser() {
    int n{};
    std::cin >> n;
    while (!std::cin || n < 0 || n > 100) // has a previous extraction failed or overflowed?
    {
        if (std::cin.eof()) // if the stream was closed
        {
            exit(0); // shut down the program now
        }

        // yep, so let's handle the failure
        std::cin.clear(); // put us back in 'normal' operation mode
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
        std::cout << "Please enter a valid number: ";
        std::cin >> n;
    }
    return n;
}
