#include<iostream>
using namespace std;

class Patient{
protected:	
	string id;
	string name;
	int age;
public:
    Patient(string i,string n,int a):id(i),name(n),age(a){
    	
	}
	
	void display() const{
     cout<<"=== Patient Details ==="<<endl;
     cout<<"ID: "<<id<<endl;
     cout<<"Name: "<<name<<endl;
     cout<<"Age: "<<age<<endl;
     
	}	
	
};

class AdmittedPatient : public Patient {
private:	
	string room_no;
	int no_of_days;
	int charge;
public:
    AdmittedPatient(string i,string n,int a,string room,int days,int c):Patient(i,n,a),room_no(room),no_of_days(days),charge(c){
    	
	}
	
	int totalCharges(){
	  return no_of_days*charge;	
	}
	void admissionSummary() const {
        display();

        cout << "=== Ward Details ===" << endl;
        cout << "Room No: " << room_no << endl;
        cout << "No of Days: " << no_of_days << endl;
        cout << "Charge Per Day: " << charge << endl;
    }
	void extendDays(int n){
		no_of_days+=n;
	}
	
};

int main(){
	
	AdmittedPatient p1("100","Ali",20,"22",7,1000);
	p1.extendDays(3);
	p1.admissionSummary();
	

	cout<<"Total Bill: "<<p1.totalCharges()<<endl<<endl;
	
	AdmittedPatient p2("101","Anus",15,"25",10,2000);
	p2.admissionSummary();
	
	cout<<"Total Bill: "<<p2.totalCharges()<<endl;
	return 0;
}
