//Thomas Cubsyead
//3/17/25
//Intro to Classes
//Date
//this program take the user input of a day month and year, stores it in a class, and displays it in three different ways

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Date {
private:
        int month, day, year;
        vector<string> months;

        bool validateDate(int m, int d, int y) {
            if (m < 1 || m > 12) return false; //month
            if (d < 1 || d > getNumDays(m, y)) return false; //day

            return true;
        }
        int getNumDays(int m, int y){
            vector<int> numDays = {31, 28, 31, 30, 31, 30, 31 , 31, 30, 31 , 30, 31};

            if (m == 2 && isLeapYear(y)) {
                return 29;
            }
            return numDays[m - 1];
        }

        bool isLeapYear(int y) {
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
                return true;
            }
            return false;
        }

public:
    Date(int m, int d, int y) {
        months = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

        if (validateDate(m, d, y)) {
            month = m;
            day = d;
            year = y;
        }
        else {
            month = 1;
            day = 1;
            year = 1000;
            cout << "invalid entry defaulting to date 1/1/1000" << endl;
        }
    
    }

    void displayDate() {
        cout << month << " /" << day << " /" << year << endl;
    }

    void displayDate2() {
        cout << months[month - 1] << " " << day << ", " << year << endl;
    }

    void displayDate3() {
        cout << day << " " << months[month - 1] << " " << year << endl;
    }

};

int main() {
    int month, day, year;

    cout << "enter desired month(1...12)" << endl;
    cin >> month;
    cout << "enter day(28...31" << endl;
    cin >> day;
    cout << "enter year" << endl;
    cin >> year;
    cout << endl;

    Date inputtedDate(month, day, year);

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
