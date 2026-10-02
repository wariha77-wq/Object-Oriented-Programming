#include<iostream>
using namespace std;

class Parcel {
private:
	const int trackingId;
	static int counter;
	string sender;
	string receiver;
	float weight;
public:
	Parcel(int i):trackingId(i) {
		counter++;
	}
	static int getCounter() {
		return counter;
	}
	void setSender(string s) {
		sender = s;
	}
	void setReceiver(string r) {
		receiver = r;
	}
	void setWeight(float w) {
		weight = w;
	}
	float getWeight() {
		return weight;
	}
	string getSender() {
		return sender;
	}
	string getReceiver() {
		return receiver;
	}
	void display()const {
		cout << "=== Parcel Details ===" << endl;
		cout << "Tracking ID: " << trackingId << endl;
		cout << "Sender: " << sender << endl;
		cout << "Receiver: " << receiver << endl;
		cout << "Weight: " << weight << endl;
	}
	~Parcel() {
		cout << "Parcel Delivered!" << endl;
	}
};
int Parcel::counter = 0;

int main() {

	Parcel p(101);
	p.setSender("Taimoor");
	p.setReceiver("Wania");
	p.setWeight(10.2);
	p.display();


	int c = Parcel::getCounter();
	cout << "Total Parcels: " << c<<endl;
	return 0;
}
