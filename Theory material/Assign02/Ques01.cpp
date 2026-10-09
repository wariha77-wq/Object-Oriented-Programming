//Aggregeation And Composition

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

class Registration {
private:
	string regNo;
	string status;
public:
	Registration() {
		regNo = generateRegNo();
		status = "Pending";
	}

	void setStatus(string s) {
		if (s == "Pending" || s == "Registered" || s == "Expired") {
			status = s;
		}
	}

	string generateRegNo() {
		string letters = "";
		string num = "";
		for (int i = 0;i < 3;i++) {
			letters += char('A' + rand() % 26);
		}
		for (int j = 0;j < 4;j++) {
			num += char('0' + rand() % 10);
		}

		return letters + num;
	}


	void display() {
		cout << "Registration No: " << regNo << endl;
		cout << "Registration Status: " << status << endl;
	}

	string getRegNo() {
		return regNo;
	}


};



class Vehicle {
private:
	string model;
	float mileage;
	string make;

	Registration Reg;

public:

	Vehicle(string ma,string mo,float mi) {
		model = mo;
		make = ma;
		mileage = mi;
	}
	
	void updateMileage(float newMil) {
		mileage = newMil;
	}

	void display() {
		
		cout << "Make: " << make << endl;
		cout<< "Model: " << model << endl;
		cout << "Mileage: " << mileage << endl;
		cout << "Vehicle Condition: " << CheckVehicleAge() << endl;

		cout << "Estimated Resale Value: " << calResaleValue() << endl;

		Reg.display();

	}

	void changeRegStatus(string s) {
		Reg.setStatus(s);
	}

	double calResaleValue() {
		double basePrice = 400000;
		double reduction = 2 * mileage;
		return basePrice - reduction;
	}

	string CheckVehicleAge() {

		string number = Reg.getRegNo();

		char digit = number[3];

		if (digit >= '0' && digit <= '4') {
			return "Old";
		}
		else {
			return "New";
		}

	}

};

class Owner {
private:
	string Name;
	string CNIC;
	Vehicle* vehicle[3];
	int count;
public:
	Owner(string n) {
		Name = n;
		count = 0;
	}
	
	void AddVehicle(Vehicle* v) {
		if (count < 3) {
			vehicle[count] = v;
			count++;
		}
		else {
			cout << "Vehicle Limit Reached!" << endl;
		}
		
	}

	void setCnic(string num) {
		CNIC = num;
	}

	void display() {
		cout << "Owner Name: " << Name << endl;
		cout << "CNIC: " << CNIC << endl;
		cout << "Vehicles Owned: " << count << endl;
		for (int i = 0;i < count;i++) {
			cout << "=== Vehicle " << i + 1 << " Details ===" << endl;
			vehicle[i]->display();

		}

	}


};



int main(){

	srand(time(0));

	Vehicle v1("Toyota", "Corolla", 25000);
	Vehicle v2("Honda", "Civic", 18000);
	Vehicle v3("Suzuki", "Alto", 30000);

	Owner o1("Ali");
	o1.setCnic("4210112345671");

	Owner o2("Ahmed");
	o2.setCnic("4220112345672");

	o1.AddVehicle(&v1);
	o1.AddVehicle(&v2);

	o2.AddVehicle(&v3);

	v1.updateMileage(27000);
	v1.changeRegStatus("Registered");

	o1.display();

	cout << "\n========================\n";

	o2.display();



	return 0;
}
