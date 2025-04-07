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
		: make(m), model(mo), color(c), license(l), timeParked(time) {}

	int getTimeParked() const { return timeParked; }
	string getLicense() const { return license; }
	string getMake() const { return make; }
	string getModel() const { return model; }
	string getColor() const { return color; }
};

//stores the amount of minutes parked at current location
class ParkingMeter {
private:
	int purchasedTime;

public:
	ParkingMeter(int time) : purchasedTime(time) {}

	int getPurchasedTime() const { return purchasedTime; }
};

//details for the parking ticket called if car is illegally parked
class ParkingTicket {
private:
	string officerName, badgeNumber;
	string carMake, carModel, carColor, carLicense;
	int violationTime;
	double fine;

public:
	ParkingTicket(string officer, string badge, string make, string model, string color, string license, int violation, double fineAmount)
		: officerName(officer), badgeNumber(badge), carMake(make), carModel(model), carColor(color), carLicense(license), violationTime(violation), fine(fineAmount) {}

	void displayTicket() const {
		cout << "*** Parking Ticket ***\n";
	    cout << "officer " << officerName << " badge number " << badgeNumber << endl;
		cout << "Vehicle License Number: " << carLicense << endl;
		cout << "Make: " << carMake << " Model: " << carModel << " Color: " << carColor << endl;
		cout << "Meter Minutes: " << violationTime + 60 << " Minutes Parked: " << violationTime + 60 << endl;
		cout << "Parking Fee: $" << fine << endl;
	}
};

//policeOfficer class for comparing the alotted time to the time used and issueing tickets
class PoliceOfficer {
private:
	string officerName, badgeNumber;

public:
	PoliceOfficer(string name, string badge) {}

	void inspectCar(ParkedCar car, ParkingMeter meter) {
		int parkedTime = car.getTimeParked();
		int purchasedTime = meter.getPurchasedTime();

		if (parkedTime > purchasedTime) {
			int violationTime = parkedTime - purchasedTime;
			double fine = 25.0;
				if (violationTime > 60) {
					fine += (violationTime - 60) / 60 * 10;
			}
			ParkingTicket ticket(officerName, badgeNumber, car.getMake(), car.getModel(), car.getColor(), car.getLicense(), violationTime, fine);

			ticket.displayTicket();
		} else {
			cout << "Parking time not exceeded with the car with license number " << car.getLicense() << endl;
		}
	}
};

//test programs for classes based on given scenarios
int main() {
	// Scenario 1 A car is parked legally
	cout << "Scenario 1: A Car Is Parked Legally\n";
	ParkedCar car1("Toyota", "Camry", "Red", "XYZ123", 30); 
	ParkingMeter meter1(40);  
	PoliceOfficer officer1("John Doe", "5678");
	officer1.inspectCar(car1, meter1);  

	// Scenario 2 A car is parked illegally 10 minutes
	cout << "\nScenario 2: A Car Is Parked Illegally (Less Than an Hour Over Time)\n";
	ParkedCar car2("Honda", "Accord", "Blue", "ABC987", 70);  
	ParkingMeter meter2(60);  
	PoliceOfficer officer2("Jane Smith", "1234");
	officer2.inspectCar(car2, meter2); 

	// Scenario 3 A car is parked illegally Multiple Hours
	cout << "\nScenario 3: A Car Is Parked Illegally (Multiple Hours Over Time)\n";
	ParkedCar car3("Ford", "Mustang", "Black", "LMN456", 190); 
	ParkingMeter meter3(60);  
	PoliceOfficer officer3("James Brown", "4321");
	officer3.inspectCar(car3, meter3);  

	// Scenario 4 Multiple Cars in a Parking Lot
	cout << "\nScenario 4: Multiple Cars in a Parking Lot\n";

	//different cars
	vector<ParkedCar> cars = {
		ParkedCar("Toyota", "Corolla", "White", "XYZ111", 30),
		ParkedCar("Honda", "Civic", "Blue", "XYZ222", 120),
		ParkedCar("Ford", "Fusion", "Red", "XYZ333", 150),
		ParkedCar("Chevrolet", "Malibu", "Black", "XYZ444", 45)
	};

	//minutes parked
	vector<ParkingMeter> meters = {
		ParkingMeter(40), 
		ParkingMeter(100), 
		ParkingMeter(120), 
		ParkingMeter(50)   
	};

	//multiple cars
	PoliceOfficer officer4("Olivia Green", "9876");

	for (size_t i = 0; i < cars.size(); ++i) {
		cout << "\nInspecting car with license " << cars[i].getLicense() << ":\n";
		officer4.inspectCar(cars[i], meters[i]);
	}

	return 0;
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
