#pragma once
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
            cout << "The root doesn't exist" << endl;
            return;
        }
        cout << "ID: " << route.id << ", PointA: " << route.pointA
            << " PointB: " << route.pointB << ", Distance: " << route.distance << " metres" << endl;

    }

    void select_ship(int id) {
        Ship ship = shipTable.select(id);
        if (ship.id == 0) {
            cout << "The ship doesn't exist" << endl;
            return;
        }
        cout << "ID: " << ship.id << ", Type: " << ship.type << " Tank size: " << ship.tank << endl;
    }

    void add_route() {
        string pointA, pointB;
        string distance;
        bool flag = false;
        cout << "Point A exists? Y/N: ";
        string Achoice; cin >> Achoice;

        if (Achoice == "Y") {
            cout << "Choose the Point A from the list below:\n";
            for (int i = 0; i < routeTable.points.size(); i++) {
                cout << i << '.' << routeTable.points[i] << endl;
            }
            cout << "Number: ";
            string num; cin >> num;
            pointA = routeTable.points[stoi(num)];
        }
        else {
            flag = true;
            cout << "Enter the name of Point A: ";
            cin >> pointA;
            cout << "Enter the depth of Point A: ";
            int depth; cin >> depth;

            routeTable.points.push_back(pointA);
            routeTable.depth[pointA] = depth;
        }

        cout << "Point B exists? Y/N: ";
        string Bchoice; cin >> Bchoice;

        if (Bchoice == "Y") {
            cout << "Choose the Point B from the list below:\n";
            for (int i = 0; i < routeTable.points.size(); i++) {
                cout << i << '.' << routeTable.points[i] << endl;
            }
            cout << "Number: ";
            string num; cin >> num;
            pointB = routeTable.points[stoi(num)];
        }
        else {
            flag = true;
            cout << "Enter the name of Point B: ";
            cin >> pointB;
            cout << "Enter the depth of Point B: ";
            int depth; cin >> depth;

            routeTable.points.push_back(pointB);
            routeTable.depth[pointB] = depth;

        }
        pair<string, string> chk = { pointA, pointB };
        if (routeTable.distances.contains(chk)) {
            cout << "The route already exists." << endl;
            return;
        }
        cout << "The distance between points?: ";
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
        cout << "Average depth at route - " << id << " is " << avg << " metres down" << endl;
    }
};
