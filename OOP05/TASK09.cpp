#include<iostream>
using namespace std;

class Ticket {
private:
	const int seatNumber;
	static int totalBookings;
	string buyerName;
public:
	Ticket(int n) :seatNumber(n) {
		totalBookings++;
	}
	void setBuyer(string n) {
		buyerName = n;
	}
	string getBuyer() {
		return buyerName;
	}
	void display()const {
		cout << "== BOOKING DETAILS ==" << endl;
		cout << "Seat No: " << seatNumber << endl;
		cout << "Buyer Name: " << buyerName << endl<<endl;

	}
	static int getTotal() {
		return totalBookings;
	}
	~Ticket() {
		cout << "Ticket is cancelled or refunded!" << endl;
	}
};

int Ticket::totalBookings = 0;

int main() {

	Ticket t(101);
	t.setBuyer("Wariha");
	t.display();

	int total = Ticket::getTotal();
	cout << "Total Bookings: " << total << endl;


	return 0;
}
