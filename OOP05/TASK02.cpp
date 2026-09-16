#include<iostream>
using namespace std;

class Reservation {
private:
	const int roomNo;
	static string hotelName;
	static int totalRes;
	string guestName;
public:
	Reservation(int no) :roomNo(no) {
		totalRes++;
	};
	void setGuestName(string name) {
		guestName = name;
	};
	void display() const {
		cout << "=== Reservation Details ===" << endl;
		cout << "Hotel Name: " << hotelName << endl;
		cout << "Room No: " << roomNo <<endl;
		cout << "Guest Name: " << guestName << endl;
		cout << "Total Reservations: " <<totalRes<< endl;
	}
	~Reservation() {
		cout << "Reservation Cancelled!" << endl;
	};
};
string Reservation::hotelName = "OceanBlue";
int Reservation::totalRes = 0;

int main() {
	int num;
	string guest;
	cout << "Enter Room no: ";
	cin >> num;
	Reservation r1(num);
	cout << "Enter Guest Name: ";
	cin >> guest;
	r1.setGuestName(guest);
	r1.display();
	return 0;
}




