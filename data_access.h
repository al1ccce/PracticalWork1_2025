#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
class DataBase {
public:
	virtual bool add(T& entity) = 0;
	virtual bool deletee(int id) = 0;
	virtual T select(int id) = 0;
	virtual void selectall() = 0;
};


class Ship {
public:
	int id;
	string type;
	int tank;
	Ship() : id(0), type(""), tank(0) {}
	Ship(int id, string type, int tank) : id(id), type(type), tank(tank) {};
};

class Route {
public:
	int id;
	string pointA;
	string pointB;
	int distance;
	Route() : id(0), pointA(""), pointB(""), distance(0) {}
	Route(int id, string pointA, string pointB, int distance) : id(id), pointA(pointA), pointB(pointB), distance(distance) {};
};

class ShipTable : public DataBase<Ship>{
private:
	map<int, Ship> ships;

	void generateDataBase() {
		vector<string> types{ "Cargo", "Speedboat", "Cruiser" };
		for (int i = 1; i < 10; i++) {
			Ship newship = Ship(i, types[i % 3], 50 + rand() % 100);
			ships[newship.id] = newship;
		}
	}

public:
	ShipTable() {
		generateDataBase();
	}

	bool add(Ship& ship) override {
		if (ships.contains(ship.id)) {
			return false; 
		}
		ships[ship.id] = ship;
		return true;
	}

	bool deletee(int id) override {
		if (ships.contains(id)) {
			ships.erase(id);
			return true;
		}
		return false;
	}

	void selectall() override {
		for (auto& pair : ships) {
			Ship& ship = pair.second; // Получаем объект Route
			cout << "ID: " << ship.id << ", Type: " << ship.type << ", Tank size: " << ship.tank << endl;
		}
	}

	Ship select(int id) override {
		if (ships.contains(id)) {
			Ship ship_returned = ships[id];
			return ship_returned;
		}
		Ship ship_returned = { 0, "0", 0 };
		return ship_returned;
	}

};



class RouteTable : public DataBase<Route>{
private:

    void generateDataBase() {
		int routeId = 1;
		for (int i = 0; i < points.size(); i++) {
			for (int j = 0; j < points.size(); j++) {
				if (i != j) { 
					string pointA = points[i];
					string pointB = points[j];

					int distance = 100 + rand() % 1000;
					distances[{pointA, pointB}] = distance;

					Route newRoute = Route(routeId++, pointA, pointB, distance);
					routes[newRoute.id] = newRoute;
				}
			}
		}
		for (auto& point : points) {
			depth[point] = 100 + rand() % 1000;
		}
    }

public:
	vector<string> points{ "PortA", "PortB", "PortC", "PortD" };
	map<string, int> depth;
	map<pair<string, string>, int> distances;
	map<int, Route> routes;


    RouteTable() {
        generateDataBase();
    }

    bool add(Route& route) override {
        if (routes.contains(route.id)) {
            return false; 
        }
        routes[route.id] = route;
        return true;
    }

    bool deletee(int id) override{
        if (routes.contains(id)) {
            routes.erase(id);
            return true;
        }
        return false; 
    }

	void selectall() override{
		for (auto& pair : routes) {
			Route& route = pair.second; 
			cout << "ID: " << route.id << ", PointA: " << route.pointA
				<< ", PointB: " << route.pointB << ", Distance: " << route.distance << " metres" << endl;
		}
	}

    Route select(int id) override {
        if (routes.contains(id)) {
            return routes[id];
        }
        return Route(0, "0", "0", 0); 
    }

};