#include <iostream>

using namespace std;

int main() {
    struct {
        string firstname;
        string lastname;
        int age;
    } data;
    

    cout << "Enter your first name: ";
    cin >> data.firstname;

    cout << "Enter your last name: ";
    cin >> data.lastname;

    cout << "Enter your age: ";
    cin >> data.age;

    cout << "Hey, " << data.firstname << " " << data.lastname << ". You are " << data.age << " years old.";

    return 0;
}