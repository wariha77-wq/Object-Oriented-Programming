#include<iostream>

using namespace std;

class Consumer{
 private:
   string name;
   int meterNo;
   int PreviousReading;
 public:
 	Consumer(string n){
 	 name = n;
	}
	Consumer(string n,int no){
		name = n;
		meterNo = no;
	}
	Consumer(string n,int no,int reading){
		name = n;
		meterNo = no;
		PreviousReading = reading;
	}	
 	
  float CalculateBill(float units){
  	float fixedRate = 10.0;
  	return units*fixedRate;
  }
  float CalculateBill(float units,float rate){
  	return units*rate;
  }
  float CalculateBill(float units,float rate,int charge){
  	return units*rate+charge;
  }
  float CalculateBill(string code,float units){
  	
  	float amount = CalculateBill(units);
  	
  	if(code == "SAVES"){
  		amount -=amount*0.05;
	  }
  	return 0;
  }
   string getName() {
      return name;
   }

   int getMeterNumber() {
      return meterNo;
    }

   int getPreviousReading() {
      return PreviousReading;
    }
    
    void ShowBill(float amount){
    	cout<<"Amount: "<<amount<<endl;
	}
	void ShowBill(float amount,int tax){
		cout<<"Amount: "<<amount<<endl;
		cout<<"Tax: "<<tax<<"%"<<endl;
	}
	void ShowBill(string n,float amount){
		cout<<"Consumer Name: "<<n<<endl;
		cout<<"Amount: "<<amount<<endl;
	}
    
    
};


int main(){
    string name;
    int meter, type;
    float previous, current, units, rate, load;
    float amount;
    string code;


    cout << "Enter consumer name: ";
    cin>>name;

    cout << "\nSelect Consumer Type:\n";
    cout << "1. Domestic"<<endl;
    cout << "2. Commercial"<<endl;
    cout << "3. Industrial"<<endl;
    cout << "4. Domestic with Promotional Code"<<endl;
    cout << "Enter choice: ";
    cin >> type;

    cout << "Enter meter number: ";
    cin >> meter;

    cout << "Enter previous meter reading: ";
    cin >> previous;

    cout << "Enter current meter reading: ";
    cin >> current;

    units = current - previous;

    if (units < 0) {
        cout << "Error: Current reading cannot be less than "
             << "previous reading.\n";
        return 1;
    }

    Consumer c(name, meter, previous);
    cout << "\n===== ELECTRICITY BILL ====="<<endl;
    cout << "Consumer: " << c.getName() << endl;
    cout << "Meter Number: " << c.getMeterNumber() << endl;
    cout << "Units Consumed: " << units << endl;

    switch (type) {
        case 1:
            amount = c.CalculateBill(units);
            c.ShowBill(amount);
            break;

        case 2:
            cout << "Enter rate per unit: ";
            cin >> rate;
            amount = c.CalculateBill(units, rate);
            c.ShowBill(name, amount);
            break;

        case 3:
            cout << "Enter rate per unit: ";
            cin >> rate;
            cout << "Enter fixed monthly load charge: ";
            cin >> load;

            amount = c.CalculateBill(units, rate, load);
            c.ShowBill(amount, 5.0);
            break;

        case 4:
            cout << "Enter promotional code: ";
            cin >> code;

            amount = c.CalculateBill(code, units);
            c.ShowBill(name, amount);
            break;

        default:
            cout << "Invalid consumer type!\n";
            return 1;
    }
/*
Ambiguous Call:
c.ShowBill(100, 5);

Explanation:
The compiler may get confused when choosing
between overloaded functions.

Fix:
c.ShowBill(100.0, 5.0);
*/
 
 return 0;	
	
}
