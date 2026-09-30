#include<iostream>
using namespace std;

class Meter{
protected:	
	string meter_no;
	string consumer_name;
	int units_consumed;
public:
    Meter(string no,string c,int u):meter_no(no),consumer_name(c),units_consumed(u){
    	
	};
	void display()const {
		cout<<"=== Details ==="<<endl;
		cout<<"Meter No: "<<meter_no<<endl;
		cout<<"Consumer Name: "<<consumer_name<<endl;
		cout<<"Units Consumed: "<<units_consumed<<endl;
	}		 
};

class SmartMeter: public Meter{
private:	
	int tariff_rate;
public:
    SmartMeter(string no,string c,int u,int r):Meter(no, c, u),tariff_rate(r){
    	
	}
	int total_bill(){
		return units_consumed*tariff_rate;
	}
};


int main() {

 SmartMeter m1("101","Ali",320,35);
 SmartMeter m2("292","Humna",250,35);
 
 m1.display();
 
 cout<<"Total Bill: "<<m1.total_bill()<<endl<<endl;
 
 m2.display();
 
 cout<<"Total Bill: "<<m2.total_bill()<<endl<<endl;


	return 0;
}
