#include<iostream>
using namespace std;

class FitnessTracker {
protected:
	int stepCount;
	float heartRate;
public:
	FitnessTracker(int s, float rate) :stepCount(s), heartRate(rate) {

	}
	void addSteps(int steps) {
		stepCount += steps;
	}
	void displayFitness() const{
		cout << "=== Fitness Tracker Details ===" << endl;
		cout << "Step Count: " << stepCount << endl;
		cout << "Heart Rate: " << heartRate << endl << endl;

	}
	

};

class Communicator {
protected:
	string pairedNum;
	int numUnreadMsgs;
public:
	Communicator(string n,int msgs):pairedNum(n),numUnreadMsgs(msgs) {

	}
	void newMsgs(int n) {
		numUnreadMsgs += n;
	}
	void displayCommunicator()const {
		cout << "=== Communicator Details ===" << endl;
		cout << "Paired Number: " << pairedNum << endl;
		cout << "Unread Messages: " << numUnreadMsgs << endl<<endl;
	}
};

class SmartWatch :public FitnessTracker, public Communicator {
private:
	string modelName;
	int batteryPer;
public:
	SmartWatch(int s, float rate, string n, int msgs, string model, int b) :FitnessTracker(s, rate), Communicator(n, msgs), modelName(model), batteryPer(b) {
     };
	void dashboard()const {
		cout << "=== DashBoard ===" << endl;
		displayFitness();
		displayCommunicator();
		cout << "Model Name: " << modelName << endl;
		cout << "Battery Percentage: " << batteryPer << endl << endl;
	}
	void simulateDay(int steps,int msgs,int batteryUsed) {
		addSteps(steps);
		newMsgs(msgs);
		batteryPer -= batteryUsed;


	}
};

int main() {

	SmartWatch watch(5000, 75.5, "03001234567", 2,"Galaxy Watch",75);
	cout << "Before one day:" << endl; 
	watch.dashboard(); cout << endl;
	watch.simulateDay(3000, 4, 20);
	cout << "After one day:" << endl; watch.dashboard();

	return 0;
}
