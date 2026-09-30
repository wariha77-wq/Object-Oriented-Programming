#include<iostream>
using namespace std;

class Person {
protected:	
	int id;
	string name;
public:
 Person(int i,string n):id(i),name(n){
 }	
};

class Doctor:public Person{
protected:	
	string specialization;
	int fee;
public:
  Doctor(int i,string n,string s,int f):Person(i,n),specialization(s),fee(f){
  }	
 void displayDoctorPerson() {
    cout << "Doctor's Person Name: " << name << endl;
 }	
};

class Researcher:public Person{
	string researchArea;
	int no_of_publications;
public:
	Researcher(int i,string n,string area,int no):Person(i,n),researchArea(area),no_of_publications(no){
		
	}
	void displayResearcherPerson() {
    cout << "Researcher's Person Name: " << name << endl;
}
};

class ClinicalResearcher: public Doctor , public Researcher{
public:	
	ClinicalResearcher(int id1, string name1,string specialization, int fee,int id2, string name2,
    string researchArea, int publications): Doctor(id1, name1, specialization, fee),
      Researcher(id2, name2, researchArea, publications){
		
	}
	
};

int main(){
	
	ClinicalResearcher cr(
        101, "Ali",
        "Cardiology", 5000,
        202, "Ahmed",
        "Cancer Research", 15
    );

    cr.displayDoctorPerson();
    cr.displayResearcherPerson();

    // cr.name;
    // ERROR: name is ambiguous because ClinicalResearcher contains two separate Person base-class objects.

	
	
	return 0;
}
