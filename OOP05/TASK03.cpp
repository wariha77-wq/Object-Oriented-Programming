#include<iostream>
using namespace std;

class Member {
private:
	const int membershipID;
	static string gymName;
	static int totalMembers;
	string memberName;
	string contactNo;
public:
	Member(int id) :membershipID(id) {
		totalMembers++;
	};
	void setName(string name) {
		memberName = name;
	}
	void setContact(string c) {
		contactNo = c;
	}
	string getName() {
		return memberName;
	}
	string getContact() {
		return contactNo;
	}
	void display() const {
		cout << "=== Member Details ===" << endl;
		cout << "GYM Name: "<< gymName << endl;
		cout << "Membership id: " << membershipID << endl;
		cout << "Member Name: " << memberName << endl;
		cout << "Contact No: " << contactNo << endl;
	}


};
string Member::gymName = "Build";
int Member::totalMembers = 0;

int main() {
	Member m(101);
	string name,no;
	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter Contact no: ";
	cin >> no;
	m.setName(name);
	m.setContact(no);

	m.display();
	return 0;
}
