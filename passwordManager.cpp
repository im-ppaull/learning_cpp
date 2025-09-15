#include <iostream>

int main() {
    system("cls");

    std::cout << "Welcome to password manager!\n" << std::endl;
    std::cout << "1. Show passwords" << std::endl;
    std::cout << "2. Add password" << std::endl;
    std::cout << "3. Delete password" << std::endl;
    std::cout << "4. Exit\n" << std::endl;

    std::cout << "What do you want to do? ";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            // SHOW ALL PASSWORDS FROM JSON FILE
    }

    return 0;
}