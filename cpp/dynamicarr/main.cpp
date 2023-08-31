#include <iostream>
#include "algorithm"
#include <limits>
#include <iterator>

int getNumberFromUser();

int main() {
    int numNames{getNumberFromUser()};
    std::string* arr {new std::string[numNames]{}};

    for (int i = 0; i < numNames; ++i) {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, arr[i]);
    }

    std::sort(arr, arr + numNames);

    std::cout << "\n";
    std::cout << "Here is your sorted list: \n";

    for (int i = 0; i < numNames; ++i) {
        std::cout << "Name #" << i + 1 << ": " << arr[i] << "\n";
    }
    delete[] arr;
    arr = nullptr;
    return 0;
}

int getNumberFromUser() {
    std::cout << "How many names would you like to enter? ";
    int n{};
    while (!(std::cin >> n)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();  // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
    }
    return n;
}
