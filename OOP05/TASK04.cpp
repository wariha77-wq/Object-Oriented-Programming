#include<iostream>
using namespace std;
class Product {
private:
	const int ProductCode;
	static int capacity;
	string productName;
	int productQuantity;
public:
	Product(int code):ProductCode(code) {
	}
	static int showCurrCapacity() {
		return capacity;
	}
	void setProdName(string name) {
		productName = name;
	}
	void setProdQuantity(int q) {
		productQuantity = q;
	}
	void display() const {
		cout << "=== Product Details ===" << endl;
		cout << "Product Code: " << ProductCode << endl;
		cout << "Product Name: " << productName << endl;
		cout << "Product Quantity: " << productQuantity << endl;
	}
	~Product() {
		cout << "Product Removed!" << endl;
	}
};
int Product::capacity = 5;

int main() {
	string pName;
	int pQuant;
	Product p(111);
	cout << "Enter Product Name: ";
	cin >> pName;
	p.setProdName(pName);
	cout << "Enter Product Quantity: ";
	cin >> pQuant;
	p.setProdQuantity(pQuant);

	p.display();
	cout << "Current Capacity: " << Product::showCurrCapacity() << endl;

	return 0;
}


