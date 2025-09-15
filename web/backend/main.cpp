#include <iostream>

#include "cpp-httplib/httplib.h"
#include "../../include/json.hpp"

using json = nlohmann::json;

int main() {
    httplib::Server svr;

    svr.Get("/api/data", [](const httplib::Request&, httplib::Response& res) {
        json j;
        j["message"] = "Ahoj z C++ backendu!";

        res.set_header("Access-Control-Allow-Origin", "*"); // CORS pre React
        res.set_content(j.dump(), "application/json");
    });

    std::cout << "Backend beží na http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);

    return 0;
}