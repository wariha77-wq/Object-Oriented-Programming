#include <iostream>
using namespace std;

int calculateFine(int days) {
    return days * 10;
}

int calculateFine(int days, int rate) {
    return days *rate;
}

double calculateFine(int days, double rate) {
    return days *rate *0.5;
}

int main() {
    int type, days;
    double rate;

    cout << "Borrower Type:" << endl;
    cout << "1. Student (Rs. 10 per day)" << endl;
    cout << "2. Special Rate" << endl;
    cout << "3. Faculty (50% concession)" << endl;
    cout << "Enter borrower type: ";
    cin >> type;
    cout << "Enter number of days late: ";
    cin >> days;

    if (type == 1) {
        cout << "Total Fine: Rs. "<< calculateFine(days) << endl;
    }
    else if (type == 2) {
        cout << "Enter per-day rate: Rs. ";
        cin >>rate;

        cout << "Total Fine: Rs. "<<calculateFine(days, rate) << endl;
    }
    else if (type == 3) {
        cout <<"Enter per-day rate: Rs. ";
        cin >>rate;

        cout <<"Total Fine: Rs. "<<calculateFine(days, rate)<< endl;
    }
    else {
        cout <<"Invalid borrower type!"<< endl;
    }
    return 0;
}
