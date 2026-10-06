#include<iostream>
using namespace std;

class MarketplaceUser {
protected:
	string id;
	string name;
	string city;
public:
	MarketplaceUser() {
		id = "";
		name = "";
		city = "";
	}
	void displayDetails()const {
		cout << "=== User Details ===" << endl;
		cout << "Id: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "City: " << city << endl;

	}
	void setId(string i) {
		id = i;
	}
	void setName(string n) {
		name = n;
	}
	void setCity(string c) {
		city = c;
	}

};

class Buyer:public MarketplaceUser {
private:
	int walletBalance;
public:
	void Purchase(int price) {
		if (walletBalance < price) {
			cout << "Insufficient Balance!" << endl;
		}
		else {
			cout << "Purchase Successfull!" << endl;
		}
	}

	void setBalance(int balance) {
		walletBalance = balance;
	}

};

class Seller :public MarketplaceUser {
private:
	float commissionRate;
	int totalSales;
public:

	void setCommissionRate(float rate) {
		commissionRate = rate;
	}

	void setTotalSales(int sale) {
		totalSales = sale;
	}

	void RecSale() {
		totalSales++;
	}
	float Earning(int profit) {
		return (profit - (commissionRate/100) * profit);
	}



};

class deliveryRider:public MarketplaceUser {
private:
	int noDelivery;
	int feePerdelivery;
public:

	void setnoOfdelivery(int n) {
		noDelivery = n;
	}
	void setfeePerDeliv(int fee) {
		feePerdelivery = fee;
	}

	void recDelivery() {
		noDelivery++;
	}
	int RiderEarning() {
		return noDelivery * feePerdelivery;
	}


};

int main() {

	Buyer b;
	b.setId("101");
	b.setName("Wariha");
	b.setCity("Karachi");
	b.setBalance(5000);

	b.displayDetails();
	b.Purchase(6000);

	cout << endl;

	Seller s;
	s.setId("102");
	s.setName("Ali");
	s.setCity("Lahore");
	s.setCommissionRate(10);
	s.setTotalSales(5);

	s.RecSale();

	s.displayDetails();
	cout << "Earnings: " << s.Earning(10000) << endl;

	cout << endl;

	deliveryRider r;
	r.setId("103");
	r.setName("Haris");
	r.setCity("Islamabad");
	r.setnoOfdelivery(10);
	r.setfeePerDeliv(500);

	r.recDelivery();

	r.displayDetails();
	cout << "Rider Earnings: " << r.RiderEarning() << endl;

	return 0;
}
