#include<iostream>
using namespace std;

class flight {
private:
	const int flightNum;
	static string airlineName;
	static int totalFlights;
public:
	flight(int flightNumber) :flightNum(flightNumber) {
		totalFlights++;
	};
	static int ShowtotalFlights() {
		return totalFlights;
	};
	static void setAirlineName(string n) {
		airlineName = n;

	};
	void display() const {
		cout << "=== Flight Details ===" << endl;
		cout << "Flight Number: " << flightNum << endl;
		cout << "Airline Name: " << airlineName << endl;
		cout << "Total Flights: " << ShowtotalFlights() << endl;
	};

	~flight() {
		cout << "Flight Data Removed!" << endl;
	}
};
int flight::totalFlights = 0;
string flight::airlineName = "";

int main() {
	int flightnum;
	string airline;
	cout << "Enter Flight Number: ";
	cin >> flightnum;
	flight f(flightnum);
	cout << "Enter Airline Name: ";
	cin >> airline;
    f.setAirlineName(airline);

	f.display();


	return 0;
}

