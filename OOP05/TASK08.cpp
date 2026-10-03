#include<iostream>
using namespace std;

class SimCard {
private:
	const string simNumber;
	static string netProvider;
	static int counter;
	string custName;
public:
	SimCard(string s):simNumber(s) {
		counter++;
	}
	void SetCustName(string n) {
		custName = n;
	}
	string getCustName() {
		return custName;
	}
	void display()const {
		cout << "=== Sim Details ===" << endl;
		cout << "Sim #: " << simNumber << endl;
		cout << "Network Provider: " << netProvider << endl;
		cout << "Customer Name: " << custName << endl << endl;
	}
	~SimCard() {
		cout << "Sim Deactivated!" << endl;
	}

};
string SimCard::netProvider = "Telenor";
int SimCard::counter = 0;
int main() {

	SimCard s("03323948385");
	s.SetCustName("Wariha");
	s.display();

	return 0;
}
