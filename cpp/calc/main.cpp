#include <iostream>

double getDouble();

char getChar();

void print(double n1, double n2, char c, double result);

int main() {
    double n1{getDouble()};
    double n2{getDouble()};
    char c{ getChar() };
    if (c == '+')
        print(n1,n2,c, n1 + n2);
    else if (c == '-')
        print(n1,n2,c, n1 - n2);
    else if (c == '*')
        print(n1,n2,c, n1 * n2);
    else if (c == '/')
        print(n1,n2,c, n1 / n2);
    return 0;
}

void print(double n1, double n2, char c, double result) {
    std::cout << n1 << " " << c << " " << n2 << " = " << result << "\n";
}

char getChar() {
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char c{};
    std::cin >> c;
    return c;
}

double getDouble() {
    std::cout << "Enter a number: ";
    double n{};
    std::cin >> n;
    return n;
}
