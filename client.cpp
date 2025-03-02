#include "data_access.h"
#include "logic.h"

int main() {
    setlocale(LC_ALL, "RUS");
    BusinessLogic logic;
    while (true) {
        string choice;
        cout << "доступные команды:" << endl
            << "1. показать все маршруты" << endl
            << "2. показать все корабли" << endl
            << "3. выбрать маршрут" << endl
            << "4. выбрать судно" << endl
            << "5. рассчитать среднюю глубину на маршруте" << endl
            << "6. добавить маршрут" << endl;
        cout << "команда> ";
        cin >> choice;

        if (choice == "1") {
            logic.show_routes();
        }
        else if (choice == "2") {
            logic.show_ships();
        }
        else if (choice == "3") {
            int id;
            cout << "Введите ID маршрута: ";
            cin >> id;
            logic.select_route(id);
        }
        else if (choice == "4") {
            int id;
            cout << "Введите ID судна: ";
            cin >> id;
            logic.select_ship(id);
        }
        else if (choice == "5") {
            int id;
            cout << "Введите ID маршрута: ";
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
            cout << "Ошибка ввода команды" << endl;
        }
    }
    return 0;
}