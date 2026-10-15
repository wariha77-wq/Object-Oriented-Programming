#include<iostream>
using namespace std;

class Calendar {
private:
	int year;
	string tasks[12][31];

public:
	Calendar(int y) :year(y) {
		for (int i = 0;i < 12;i++) {
			for (int j = 0;j < 31;j++) {
				tasks[i][j] = "";
			}
		}
	}

	bool isValidDate(int month,int day) {
		if (month > 0 && month <= 12) {
			int daysInMonth[12] = {
	           31, 28, 31, 30, 31, 30,
	           31, 31, 30, 31, 30, 31};
			if (day>0 && day <= daysInMonth[month - 1]) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	bool hasTask(int month, int day) {
		if (tasks[month - 1][day - 1] != "") {
			return true;
		}
		else {
			return false;
		}
	}

	void addTask(int month,int day) {
		if (isValidDate(month, day)) {
			if (!hasTask(month, day)) {
				cout << "Enter Task Description: ";
				cin >> tasks[month - 1][day - 1];
			}
			else {
				cout << "A task Already Exists! " << endl;
			}
		}
		else {
			cout << "Invalid Date!" << endl;
		}
	}

	void removeTask(int month, int day) {
		if (isValidDate(month, day)) {
			if (hasTask(month, day)) {
				tasks[month - 1][day - 1] = "";
				cout << "Task Removed!" << endl;
			}
			else {
				cout << "No Tasks Exist!" << endl;
			}
		}
		else {
			cout << "Invalid Date!" << endl;
		}
	}

	void displayTasks() {
		bool found = false;

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 31; j++) {
				if (tasks[i][j] != "") {
					cout << "Month: " << i + 1<< ", Day: " << j + 1<< ", Task: " << tasks[i][j] << endl;
					found = true;
				}
			}
		}

		if (!found) {
			cout << "No tasks scheduled!" << endl;
		}
	}
};

int main() {
	int y;

	cout << "Enter year: ";
	cin >> y;

	Calendar c(y);

	int choice;

	int month, day;

	do
	{
		cout << "\n1. Add Task";
		cout << "\n2. Remove Task";
		cout << "\n3. Display Tasks";
		cout << "\n4. Exit";
		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter Month: ";
			cin >> month;
			cout << "Enter Day: ";
			cin >> day;
			c.addTask(month,day);
			break;

		case 2:
			cout << "Enter Month: ";
			cin >> month;
			cout << "Enter Day: ";
			cin >> day;
			c.removeTask(month,day);
			break;

		case 3:
			c.displayTasks();
			break;

		case 4:
			cout << "Exiting..." << endl;
			break;

		default:
			cout << "Invalid choice!" << endl;
		}

	} while (choice != 4);
	
	return 0;
}
