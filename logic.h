#include "data_access.h"
#include <string>

class BusinessLogic {
private:
    ShipTable shipTable;
    RouteTable routeTable;

public:
    BusinessLogic() : shipTable(), routeTable() {};
    void show_routes() {
        routeTable.selectall();
    }

    void show_ships() {
        shipTable.selectall();
    }

    void select_route(int id) {
        Route route = routeTable.select(id);
        if (route.id == 0) {
            cout << "Маршрут не существует" << endl;
            return;
        }
        cout << "ID: " << route.id << ", Точка отправления: " << route.pointA
            << " Точка прибытия: " << route.pointB << ", Дистанция: " << route.distance << " метров" << endl;

    }

    void select_ship(int id) {
        Ship ship = shipTable.select(id);
        if (ship.id == 0) {
            cout << "Судна не существует" << endl;
            return;
        }
        cout << "ID: " << ship.id << ", Тип: " << ship.type << " Топливный бак: " << ship.tank << endl;
    }

    void add_route() {
        string pointA, pointB;
        string distance;
        bool flag = false;
        cout << "Точка отправления существует? Y/N: ";
        string Achoice; cin >> Achoice;

        if (Achoice == "Y") {
            cout << "Выберите точку из списка ниже:\n";
            for (int i = 0; i < routeTable.points.size(); i++) {
                cout << i << '.' << routeTable.points[i] << endl;
            }
            cout << "Номер: ";
            string num; cin >> num;
            pointA = routeTable.points[stoi(num)];
        }
        else {
            flag = true;
            cout << "Введите название точки отправления: ";
            cin >> pointA;
            cout << "Введите глубину точки отправления: ";
            int depth; cin >> depth;

            routeTable.points.push_back(pointA);
            routeTable.depth[pointA] = depth;
        }

        cout << "Точка прибытия существует? Y/N: ";
        string Bchoice; cin >> Bchoice;

        if (Bchoice == "Y") {
            cout << "Выберите точку из списка ниже:\n";
            for (int i = 0; i < routeTable.points.size(); i++) {
                cout << i << '.' << routeTable.points[i] << endl;
            }
            cout << "Номер: ";
            string num; cin >> num;
            pointB = routeTable.points[stoi(num)];
        }
        else {
            flag = true;
            cout << "Введите название точки прибытия: ";
            cin >> pointB;
            cout << "Введите глубину точки прибытия: ";
            int depth; cin >> depth;

            routeTable.points.push_back(pointB);
            routeTable.depth[pointB] = depth;

        }
        pair<string, string> chk = { pointA, pointB };
        if (routeTable.distances.contains(chk)) {
            cout << "Такой маршрут уже существует." << endl;
            return;
        }
        cout << "Дистанция между точками?: ";
        cin >> distance;
        routeTable.distances[{pointA, pointB}] = stoi(distance);
        Route newRoute{ int(routeTable.routes.size()) + 1, pointA, pointB, stoi(distance) };
        routeTable.routes[routeTable.routes.size() + 1] = newRoute;
    }

    void calculate_depth(int id) {
        Route route = routeTable.select(id);
        int d1 = routeTable.depth[route.pointA];
        int d2 = routeTable.depth[route.pointB];
        float avg = (d1 + d2) / 2;
        cout << "Средняя глубина на маршруте №" << id << " - " << avg << " метров" << endl;
    }
};