#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include "include/json.hpp"

using json = nlohmann::json;
using namespace std;

struct User {
    string username, password;
    vector<string> tasks;
};

User getUser(const string& username) {
    ifstream infile("to-do-list.json");
    json data;
    infile >> data;
    infile.close();

    User user;
    user.username = username;
    user.password = data[username]["password"];

    if (data[username].contains("tasks") && data[username]["tasks"].is_array()) {
        for (const auto& task : data[username]["tasks"]) {
            user.tasks.push_back(task);
        }
    } else {
        data[username]["tasks"] = json::array();

        ofstream outfile("to-do-list.json");
        outfile << data.dump(4);
        outfile.close();
    }

    return user;
}

void ShowTasks(User& user) {
    system("cls");

    if (user.tasks.empty()) {
        cout << "No tasks found!" << endl;
    } else {
        cout << "Your tasks: \n" << endl;
        for (size_t i = 0; i < user.tasks.size(); i++) {
            cout << i + 1 << ". " << user.tasks[i] << endl;
        }
        cout << endl;
    }

    system("pause");
}

void AddTask(User& user) {
    system("cls");

    cin.ignore();
    string task;

    cout << "Task" << endl;
    getline(cin, task);

    if (task.empty())
        return;

    user.tasks.push_back(task);

    ifstream infile("to-do-list.json");
    json data;
    infile >> data;
    infile.close();

    data[user.username]["tasks"] = user.tasks;

    ofstream outfile("to-do-list.json");
    outfile << data.dump(4);
    outfile.close();

    cout << "Task added!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

void UserMenu(User& user) {
    while (true) {
        system("cls");

        int choice;

        cout << "Logged as " << user.username << endl;
        cout << "1. Show tasks" << endl;
        cout << "2. Add task" << endl;
        cout << "3. Log out" << endl;

        cin >> choice;

        if (choice == 1) {
            system("cls");
            cout << "Loading tasks...";
            this_thread::sleep_for(chrono::seconds(3));
            ShowTasks(user);
        } else if (choice == 2) {
            AddTask(user);
        } else if (choice == 3) {
            system("cls");
            cout << "Logging out...";
            this_thread::sleep_for(chrono::seconds(3));
            break;
        }
    }
}

void Login() {
    system("cls");

    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    json data;
    ifstream infile("to-do-list.json");

    if (infile) {
        infile >> data;
        infile.close();
    }

    if (!data.contains(username)) {
        system("cls");
        cout << "A user with this username does not exists!";

        return;
    }

    if (data[username]["password"] != password) {
        system("cls");
        cout << "Wrong password!";

        return;
    }

    system("cls");

    cout << "Logged in successfully!" << endl;

    this_thread::sleep_for(chrono::seconds(3));

    User user = getUser(username);
    UserMenu(user);
}

void RegisterUser() {
    system("cls");

    string username, password, confirmedPassword;

    cout << "Enter your username: ";
    cin >> username;

    system("cls");

    cout << "Enter your password: ";
    cin >> password;

    cout << "Confirm your password: ";
    cin >> confirmedPassword;

    if (password != confirmedPassword) {
        system("cls");
        cout << "Password was not matching!";
        this_thread::sleep_for(chrono::seconds(3));

        return;
    }

    json data;
    ifstream infile("to-do-list.json");

    if (infile) {
        infile >> data;
        infile.close();
    }

    if (data.contains(username)) {
        system("cls");
        cout << "User with this username already exists!";
        this_thread::sleep_for(chrono::seconds(3));

        return;
    }

    data[username]["password"] = password;

    ofstream outfile("to-do-list.json");
    outfile << data.dump(4);
    outfile.close();

    system("cls");

    cout << "User registered successfully!" << endl;

    this_thread::sleep_for(chrono::seconds(2));
    
    User user = getUser(username);
    UserMenu(user);
}

int main() {
    while (true) {
        // Clear console
        system("cls");

        // Starting menu
        cout << "TO-DO LIST" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
            RegisterUser();
        else if (choice == 2)
            Login();
    }

    return 0;
}