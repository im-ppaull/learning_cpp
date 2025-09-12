#include <iostream>

using namespace std;

void Addition(int first, int second) {
    cout << "Result is: " << first + second;
}

void Subtraction(int first, int second) {
    cout << "Result is: " << first - second;
}

void Multiplication(int first, int second) {
    cout << "Result is: " << first * second;
}

void Division(int first, int second) {
    if (second != 0)
        cout << "Result is: " << first / second;
    else
        cout << "Division with zero is impossible!";
}

int main() {
    int first, second;
    char operation;

    cout << "Welcome to calculator!" << endl;

    cout << "Enter your first number: ";
    cin >> first;

    cout << "Enter your second number: ";
    cin >> second;

    cout << "Enter operation (+ | - | * | /): ";
    cin >> operation;

    if (operation == '+') {
        Addition(first, second);
    } else if (operation == '-') {
        Subtraction(first, second);
    } else if (operation == '*') {
        Multiplication(first, second);
    } else if (operation == '/') {
        Division(first, second);
    } else {
        cout << "Unknown operation!" << endl;
    }
    return 0;
}