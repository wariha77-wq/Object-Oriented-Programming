#include<iostream>
using namespace std;

class ParkedVehicle {
private:
	const string plateNum;
	static int totalVehicles;
	string entryTime;
public:
	ParkedVehicle(string num):plateNum(num) {
		totalVehicles++;
	}
	~ParkedVehicle() {
		totalVehicles--;
		cout << "Vehicle Removed!" << endl;
	}
	static int getTotal() {
		return totalVehicles;
	}
	void setEntryTime(string t) {
		entryTime = t;
	}
	string getEntryTime() {
		return entryTime;
	}

};

int ParkedVehicle::totalVehicles = 0;

int main() {

	ParkedVehicle v1("ABC-123");
	v1.setEntryTime("10:00 AM");
	ParkedVehicle v2("XYZ-456");
	v2.setEntryTime("10:15 AM");

	cout << "Total parked vehicles: " << ParkedVehicle::getTotal() << endl;
	cout << "Vehicle 1 entry time: " << v1.getEntryTime() << endl;
	cout << "Vehicle 2 entry time: " << v2.getEntryTime() << endl;


	return 0;
}
