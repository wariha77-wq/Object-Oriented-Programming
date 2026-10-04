#include<iostream>
using namespace std;

class Course {
protected:
	string title;
	float durationHr;
	string Insructor;
public:
	Course(string t,float d,string Inst):title(t),durationHr(d),Insructor(Inst) {

	}
};
class PaidCourse :public Course {
protected:	
	int courseFee;
public:
	PaidCourse(string t, float d, string Inst, int fee) :Course(t, d, Inst), courseFee(fee) {

	}

};
class CertificationCourse:public PaidCourse {
private:
	int examFee;
	float passingMarks;
public:
	CertificationCourse(string t, float d, string Inst, int fee,int exfee,float marks):PaidCourse(t,d,Inst,fee),examFee(exfee),passingMarks(marks){

	}
	int getTotalFee() {
		return examFee + courseFee;
	}
	void getResult(float m) {
		if (m >= passingMarks) {
			cout << "Student Passed!" << endl;
		}
		else {
			cout << "Student Failed!" << endl;
		}
	}
	void display() { 
		cout << "Course Title: " << title << endl;
		cout << "Duration: " << durationHr << " hours" << endl; 
		cout << "Instructor: " << Insructor << endl; 
		cout << "Course Fee: " << courseFee << endl; 
		cout << "Exam Fee: " << examFee << endl; 
	    cout << "Passing Marks: " << passingMarks << endl; 
		cout << "Total Fee: " << getTotalFee() << endl; 
	}
};

int main() {

	CertificationCourse c1("C++ Programming", 40, "Ali", 5000, 1000, 50); 
	CertificationCourse c2("Python Programming", 35, "Ahmed", 4000, 800, 60); 
	cout << "Course 1:" << endl; 
	c1.display();
	c1.getResult(75); 
	cout << endl; 
	cout << "Course 2:" << endl; 
	c2.display(); 
	c2.getResult(45);

	return 0;
}
