#include<iostream>
using namespace std;

class Vehicle {
protected:
    string registration_no;
    string driver_name;
public:
    Vehicle(string r, string d) {
        registration_no = r;
        driver_name = d;
    }
    void displayVehicle() {
        cout <<"Registration No: " <<registration_no << endl;
        cout <<"Driver Name: " <<driver_name <<endl;
    }
};

class MotorVehicle : public Vehicle {
protected:
    int fuel_capacity;
    int mileage;
public:
    MotorVehicle(string r, string d, int f, int m)
        : Vehicle(r, d) {
        fuel_capacity = f;
        mileage = m;
    }
    int maxRange() {
        return fuel_capacity*mileage;
    }
    void displayMotorVehicle() {
        cout <<"Fuel Capacity: " << fuel_capacity <<" liters"<<endl;
        cout <<"Mileage: " << mileage <<" km/l"<<endl;
        cout <<"Maximum Range: "<<maxRange() <<" km"<<endl;
    }
};

class CoolingUnit {
private:
    int temperature;
public:
    CoolingUnit(int t) {
        temperature =t;
    }
    void changeTemperature(int t) {
        temperature = t;
    }
    void displayTemperature() {
        cout << "Target Temperature: "<<temperature << " C" << endl;
    }
};
class RefrigeratedTruck : public MotorVehicle {
private:
    CoolingUnit coolingUnit;
    int cargo_capacity;

public:
    RefrigeratedTruck(string r, string d, int f, int m,
                      int t, int cargo)
        : MotorVehicle(r, d, f, m),coolingUnit(t) {
        cargo_capacity = cargo;
    }
    void display() {
        cout << "=== Refrigerated Truck ===" << endl;
        displayVehicle();
        displayMotorVehicle();

        cout << "Cargo Capacity: "
             << cargo_capacity << " tons" << endl;

        coolingUnit.displayTemperature();
    }
    void testTrip(int distance, int requiredTemperature) {

        coolingUnit.changeTemperature(requiredTemperature);
        if (distance<= maxRange()) {
            cout << "Trip can be completed without refuelling."
                 << endl;
        }
        else {
            cout <<"Trip cannot be completed without refuelling."
                 << endl;
        }

        cout << "Temperature set to: "
             << requiredTemperature << " C" << endl;
    }
};

int main() {

    RefrigeratedTruck t1(
        "TR-101", "Ali", 200, 5, -5, 20
    );

    RefrigeratedTruck t2(
        "TR-202", "Ahmed", 100, 4, -10, 15
    );

    cout <<"Truck 1 Details"<< endl;
    t1.display();

    cout << endl<<"Testing Short Trip"<< endl;
    t1.testTrip(500, -8);

    cout << endl << "Truck 2 Details" << endl;
    t2.display();

    cout << endl << "Testing Long Trip" << endl;
    t2.testTrip(500, -15);

    return 0;
}
