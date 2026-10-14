#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual int calculateToll() {
        return 100;
    }
};

class Car : public Vehicle {
public:
    int calculateToll() override {
        return Vehicle::calculateToll();
    }
};

class Motorbike : public Vehicle {
public:
    int calculateToll() override {
        return Vehicle::calculateToll() / 2;
    }
};

class Truck : public Vehicle {
private:
    int axles;

public:
    Truck(int a) {
        axles = a;
    }

    int calculateToll() override {
        return Vehicle::calculateToll() + (axles * 50);
    }
};

int main() {
    int type, axles;

    cout << "Vehicle Type:" << endl;
    cout << "1. Car" << endl;
    cout << "2. Motorbike" << endl;
    cout << "3. Truck" << endl;
    cout << "Enter vehicle type: ";
    cin >> type;

    if (type == 1) {
        Car car;
        cout << "Toll: Rs. " << car.calculateToll() << endl;
    }
    else if (type == 2) {
        Motorbike bike;
        cout << "Toll: Rs. " << bike.calculateToll() << endl;
    }
    else if (type == 3) {
        cout << "Enter number of axles: ";
        cin >> axles;

        Truck truck(axles);
        cout << "Toll: Rs. " << truck.calculateToll() << endl;
    }
    else {
        cout << "Invalid vehicle type!" << endl;
    }

    return 0;
}
