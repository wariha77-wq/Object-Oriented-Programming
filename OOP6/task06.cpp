#include<iostream>
using namespace std;

class SchoolStaff {
protected:
	string staffId;
	string staffname;
	int basicSalary;
public: 
	SchoolStaff(string id,string name,int b):staffId(id),staffname(name),basicSalary(b) {

	}
	void displayDetails()const {
		cout << "=== Staff Details ===" << endl;
		cout << "Id: " << staffId << endl;
		cout << "Name: " << staffname << endl;
	}

};

class Teacher:public SchoolStaff {
private:
   int noExtraClass;
   int allowance;
public:
	Teacher(string id, string name, int b,int e,int allow):SchoolStaff(id,name,b),noExtraClass(e),allowance(allow) {

	}

	int TeacherSalary() {
		return (basicSalary + noExtraClass * allowance);
	}
};

class Clerk:public SchoolStaff {
private:
	int overtimeHrs;
	int overtimeRate;
public:
	Clerk(string id, string name, int b,int overtime,int rate):SchoolStaff(id, name, b),overtimeHrs(overtime),overtimeRate(rate){

	}
	int ClerkSalary() {
		return (basicSalary + overtimeHrs * overtimeRate);
	}
};


class SecurityGuard :public SchoolStaff {
private:
	int noNightShifts;
	int allowancePerShift;
public:
	SecurityGuard(string id, string name, int b, int n, int allow) :SchoolStaff(id, name, b), noNightShifts(n), allowancePerShift(allow) {
	}
	int GuardSalary() {
			return(basicSalary + noNightShifts * allowancePerShift);
	}
};

int main() {

	Teacher t("100", "Wariha", 50000, 2, 5000);
	t.displayDetails();
	cout << "Salary: " << t.TeacherSalary() << endl<<endl;
	Clerk c("120", "Ali", 15000, 3, 1000);
	c.displayDetails();
	cout << "Salary: " << c.ClerkSalary() << endl << endl;
	SecurityGuard s("200", "Haris",25000,4, 1500);
	s.displayDetails();
	cout << "Salary: " << s.GuardSalary() << endl << endl;

	return 0;
}
