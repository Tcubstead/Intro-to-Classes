//Thomas Cubsyead
//3/17/25
//Intro to Classes
//Date
//this program take the user input of a day month and year, stores it in a class, and displays it in three different ways

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//defines the date class type
class Date {
private:
        int month, day, year;
        vector<string> months;

        //makes sure the user input of the month and day is valid and is less than the maximum number of days for the given month
        bool validateDate(int m, int d, int y) {
            if (m < 1 || m > 12) return false; //month
            if (d < 1 || d > getNumDays(m, y)) return false; //day

            return true;
        }

        //sets the max number of days for each month and sets second value for feburary for leap years
        int getNumDays(int m, int y){
            vector<int> numDays = {31, 28, 31, 30, 31, 30, 31 , 31, 30, 31 , 30, 31};

            if (m == 2 && isLeapYear(y)) {
                return 29;
            }
            return numDays[m - 1];
        }

        //determines if it is a leap year and if so allows for feurary to have up to 29 days
        bool isLeapYear(int y) {
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
                return true;
            }
            return false;
        }

public:
    Date(int m = 1, int d = 1, int y = 1900) {
        months = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

        setDate(m, d, y);
    }
        //sets a default response if user inputs an invalid date
        void setDate(int m, int d, int y) {
            if (validateDate(m, d, y)) {
                month = m;
                day = d;
                year = y;
            }
            else {
                month = 1;
                day = 1;
                year = 1900;
                cout << "invalid entry defaulting to date 1/1/1900" << endl;
            }
        }
        //accessor functions
        int getMonth() { return month; }
        int getDay() { return day; }
        int getYear() { return year; }

        // Overloaded function to check if the year is a leap year
        bool isLeapYear() {
            return isLeapYear(year);
        }
   
        // Overloaded function to get the last day of the month for any month and year
        int lastDay() {
            return lastDay(month, year);
        }

        int lastDay(int m, int y) {
            return lastDay(m, y);
        }
    //uses user input to display date as m/d/yyyy
    void displayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }

    //uses user input to display date as m d, yyyy
    void displayDate2() {
        cout << months[month - 1] << " " << day << ", " << year << endl;
    }

    //uses user input to display date as d m yyyy
    void displayDate3() {
        cout << day << " " << months[month - 1] << " " << year << endl;
    }

};

int main() {
    int month, day, year;

    //gets user input
    cout << "enter desired month(1...12)" << endl;
    cin >> month;
    cout << "enter day(28...31" << endl;
    cin >> day;
    cout << "enter year" << endl;
    cin >> year;
    cout << endl;

    Date inputtedDate(month, day, year);

    //display info
    inputtedDate.displayDate();
    cout << endl;
    inputtedDate.displayDate2();
    cout << endl;
    inputtedDate.displayDate3();
    cout << endl;

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
