#include<iostream>
using namespace std;

class Athlete {
protected:
    string name;
    string country;
public:
    Athlete(string n, string c) {
        name = n;
        country = c;
    }
};

class Swimmer : virtual public Athlete {
protected:
    float best_time;

public:
    Swimmer(string n, string c, float time)
        : Athlete(n, c) {
        best_time = time;
    }
};

class Cyclist : virtual public Athlete {
protected:
    float best_speed;

public:
    Cyclist(string n, string c, float speed)
        : Athlete(n, c) {
        best_speed = speed;
    }
};

class Triathlete : public Swimmer, public Cyclist {
public:
    Triathlete(string n, string c, float time, float speed)
        : Athlete(n, c),
          Swimmer(n, c, time),
          Cyclist(n, c, speed) {
    }

    void display() {
        cout << "=== Triathlete Details ===" << endl;
        cout << "Name: " << name << endl;
        cout << "Country: " << country << endl;
        cout << "Best 100m Swimming Time: " << best_time << " seconds" << endl;
        cout << "Best Cycling Speed: "<< best_speed << " km/h" << endl;
    }
};

int main() {

    Triathlete t1("Ali", "Pakistan", 58.5, 42.5);
    Triathlete t2("Ahmed", "Pakistan", 61.2, 39.8);

    t1.display();
    cout << endl;
    t2.display();

    return 0;
}
