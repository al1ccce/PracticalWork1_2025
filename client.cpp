#include "data_access.h"
#include "logic.h"

int main() {
    BusinessLogic logic;
    while (true) {
        string choice;
        cout << "commands:" << endl
            << "1. show all routes" << endl
            << "2. show all ships" << endl
            << "3. select route" << endl
            << "4. select ship" << endl
            << "5. calculate average depth at the route" << endl
            << "6. add route" << endl;
        cout << "cmd> ";
        cin >> choice;

        if (choice == "1") {
            logic.show_routes();
        }
        else if (choice == "2") {
            logic.show_ships();
        }
        else if (choice == "3") {
            int id;
            cout << "Enter route ID: ";
            cin >> id;
            logic.select_route(id);
        }
        else if (choice == "4") {
            int id;
            cout << "Enter ship ID: ";
            cin >> id;
            logic.select_ship(id);
        }
        else if (choice == "5") {
            int id;
            cout << "Enter route ID: ";
            cin >> id;
            logic.calculate_depth(id);
        }
        else if (choice == "6") {
            logic.add_route();
        }
        else if (choice == "7") {
            break;
        }
        else {
            cout << "Wrong command" << endl;
        }
    }
    return 0;
}