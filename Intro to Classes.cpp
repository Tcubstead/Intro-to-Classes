//Thomas Cubsyead
//4/7/25
//More about classes
//Parking_Simulator
//This program compares the information provided from separate classes and determines wether the selected car needs a ticket or not

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//stores the information about the car
class ParkedCar {
private:
	string make, model, color, license;
	int timeParked;

public:
	ParkedCar(string m, string mo, string c, string l, int time)
		: make(m), model(mo), color(c), license(l), timeParked(t) {}

	int getTimeParked() const { return timeParked; }
	string getLicense() const { return license; }
	string getMake() const { return make; }
	string getModel() const { return model; }
	string getColor() const { return color; }
};

//stores the amount of minutes parked at current location



int main() {

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
