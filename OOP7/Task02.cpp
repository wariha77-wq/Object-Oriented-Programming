#include <iostream>
#include <string>
using namespace std;

class cardPrinter;

class Student {
private:
    string name;
    int rollno;
public:
    Student(string n, int roll):name(n),rollno(roll) {}

    friend class cardPrinter;
};

class GraduateStudent :public Student {
private:
    string thesisTitle;
public:
    GraduateStudent(string n, int roll, string t):Student(n, roll), thesisTitle(t) {}

    friend class cardPrinter;
};

class cardPrinter {
public:
    void printCard(Student &s) {
        cout << "Name: " << s.name << endl;
        cout << "Roll No: " << s.rollno << endl;
    }

    void printCard(GraduateStudent &g) {
        printCard(static_cast<Student&>(g));
        cout << "Thesis Title: " << g.thesisTitle << endl;
    }
};

int main() {
    Student s("Ali", 101);
    GraduateStudent g("Ahmed", 201,"Artificial Intelligence");

    cardPrinter p;
    cout << "--- Student Card ---" << endl;
    p.printCard(s);

    cout << "\n--- Graduate Student Card ---" << endl;
    p.printCard(g);

    return 0;
}
