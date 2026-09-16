#include<iostream>
using namespace std;

class Policy {
private:
	const int policyNumber;
	static int totalPolicies;
	string policyHolder;
	double premiumAmount;
public:
	Policy(int num) :policyNumber(num) {
		totalPolicies++;
	}
	static int gettotalPolicies() {
		return totalPolicies;
	}
	void setPolicyHolder(string n) {
		policyHolder = n;
	}
	void setAccount(double a) {
		premiumAmount = a;
	}
	string getPolicyHolder() {
		return policyHolder;
	}
	double getAccount() {
		return premiumAmount;
	}

	void display()const {
		cout << "=== Policy Details ===" << endl;
		cout << "Policy Number: " << policyNumber << endl;
		cout << "Holder Name: " << policyHolder << endl;
		cout << "Ammount: " << premiumAmount << endl;
	}
	~Policy() {
		cout << "Policy Closed!" << endl;
	}
};
int Policy::totalPolicies = 0;


int main() {
	string name;
	double amount;
	int PolicyNum;
	cout << "Enter Policy Number: ";
	cin >> PolicyNum;
	Policy p(PolicyNum);

	cout << "Enter Policy Holder Name: ";
	cin >> name;
	cout << "Enter Ammount: ";
	cin >> amount;
	p.setPolicyHolder(name);
	p.setAccount(amount);
	p.display();

	cout << "Total Policies: " << Policy::gettotalPolicies() << endl;


	return 0;
}

