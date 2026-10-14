#include <iostream>

using namespace std;

class Account{
private:
	string name;
	int balance;
public:	
	void setName(string n){
		name = n;
	}
	void setBalance(int b){
		balance = b;
	}
	
	friend void generateAuditReport(const Account &a);	
};

void generateAuditReport(const Account &a){
	cout<<"---- Audit Report ----"<<endl;
	cout<<"Name: "<<a.name<<endl;
	cout<<"Balance: "<<a.balance<<endl;
	if(a.balance<1000){
		cout<<"Warning! Balance too low"<<endl;
	}
}

int main() {

Account a1;
a1.setName("Ayesha");
a1.setBalance(250000);

generateAuditReport(a1);

Account a2;
a2.setName("Bilal");
a2.setBalance(800);

generateAuditReport(a2);


    return 0;
}
