#include <iostream>
#include <fstream>
#include "include/json.hpp"

using json = nlohmann::json;
using namespace std;

struct MainData
{
    string firstname;
    string lastname;
    int age;

    MainData(const json& j) {
        firstname = j["firstname"].get<string>();
        lastname = j["lastname"].get<string>();
        age = j["age"].get<int>();
    }

    json ToJSON() const {
        return json {
            { "firstname", firstname },
            { "lastname", lastname },
            { "age", age }
        };
    }
};


int main() {
    ifstream file("data.json");

    json j = json::parse(file);
    file.close();

    MainData data(j);
    json outJSON = data.ToJSON();
    
    cout << "Hey, " << data.firstname << " " << data.lastname
        << ". You're " << data.age << " years old." << endl;

    string hobby;
    cout << "What is your hobby? ";
    getline(cin, hobby);
    outJSON["hobby"] = hobby;

    ofstream outfile("data.json");
    outfile << outJSON.dump(4);
    outfile.close();

    return 0;
}