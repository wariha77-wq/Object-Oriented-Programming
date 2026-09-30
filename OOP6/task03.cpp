#include<iostream>
using namespace std;

class Building {
protected: 
 string name;
 int sq_feet;
 int floors;	
public:
 Building(string n, int area, int f)
        : name(n), sq_feet(area), floors(f) {
    }

    void displayBuilding() const {
        cout << "=== Building Details ===" << endl;
        cout << "Name: " << name << endl;
        cout << "Covered Area: " << sq_feet << " sq ft" << endl;
        cout << "Floors: " << floors << endl;
    }
	
};

class Commercial:public Building{
protected:	
	int no_of_shops;
	int monthly_rent;
public: 
   	Commercial(string n, int area, int f, int shops, int rent): Building(n, area, f),
          no_of_shops(shops),
          monthly_rent(rent) {
    }

    void displayCommercial() const {
        cout << "=== Commercial Details ===" << endl;
        cout << "Number of Shops: " << no_of_shops << endl;
        cout << "Monthly Rent Per Shop: " << monthly_rent << endl;
    }
};
class ShoppingMall: public Commercial{
private:	
	int parking_capacity;
	int maintenance;
public:
     ShoppingMall(string n, int area, int f,
                 int shops, int rent,
                 int parking, int maintain)
        : Commercial(n, area, f, shops, rent),
          parking_capacity(parking),
          maintenance(maintain) {
    }

    void display() const {
        displayBuilding();
        displayCommercial();

        cout << "=== Mall Details ===" << endl;
        cout << "Parking Capacity: " << parking_capacity << endl;
        cout << "Monthly Maintenance: " << maintenance << endl;
    }

    int expectedIncome() const {
        return (no_of_shops * monthly_rent) - maintenance;
    }	
};


int main(){
	
	ShoppingMall m1("Lucky Mall", 50000, 4,
                    100, 50000, 500, 1000000);

    ShoppingMall m2("Ocean Mall", 75000, 5,
                    150, 60000, 800, 1500000);

    m1.display();
    cout << "Expected Monthly Income: "
         << m1.expectedIncome() << endl << endl;

    m2.display();
    cout << "Expected Monthly Income: "
         << m2.expectedIncome() << endl;

	
	
	return 0;
}
