//Thomas Cubsyead
//3/17/25
//Intro to Classes
//Date
//this program take the user input of a day month and year, stores it in a class, and displays it in three different ways

#include <iostream>
#include <vector>
#include <string>
#include <cmath>  // For absolute value calculation
using namespace std;

// defines the date class type
class Date {
private:
    int month, day, year;
    vector<string> months;

    // makes sure the user input of the month and day is valid and is less than the maximum number of days for the given month
    bool validateDate(int m, int d, int y) {
        if (m < 1 || m > 12) return false; // month
        if (d < 1 || d > getNumDays(m, y)) return false; // day
        return true;
    }

    // sets the max number of days for each month and sets second value for February for leap years
    int getNumDays(int m, int y) {
        vector<int> numDays = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (m == 2 && isLeapYear(y)) {
            return 29;
        }
        return numDays[m - 1];
    }

    // determines if it is a leap year and if so allows for February to have up to 29 days
    bool isLeapYear(int y) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            return true;
        }
        return false;
    }

    // Adjust the date if the day overflows or underflows
    void adjustDate() {
        while (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day = getNumDays(month, year);
        }
        while (day > getNumDays(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

public:
    Date(int m = 1, int d = 1, int y = 1900) {
        months = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        setDate(m, d, y);
    }

    // sets a default response if user inputs an invalid date
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
            cout << "Invalid entry, defaulting to date 1/1/1900" << endl;
        }
    }

    // accessors
    int getMonth() { return month; }
    int getDay() { return day; }
    int getYear() { return year; }

    // overloaded stream insertion (<<) operator to display date
    friend ostream& operator<<(ostream& os, const Date& d) {
        os << d.months[d.month - 1] << " " << d.day << ", " << d.year;
        return os;
    }

    // overloaded stream extraction (>>) operator to input date
    friend istream& operator>>(istream& is, Date& d) {
        int m, d_input, y;
        char ch; // to ignore '/' or other characters
        is >> m >> ch >> d_input >> ch >> y;
        d.setDate(m, d_input, y);
        return is;
    }

    // overloaded prefix increment (++) operator
    Date& operator++() {
        day++;
        adjustDate();
        return *this;
    }

    // overloaded postfix increment (++) operator
    Date operator++(int) {
        Date temp = *this;
        day++;
        adjustDate();
        return temp;
    }

    // overloaded prefix decrement (--) operator
    Date& operator--() {
        day--;
        adjustDate();
        return *this;
    }

    // overloaded postfix decrement (--) operator
    Date operator--(int) {
        Date temp = *this;
        day--;
        adjustDate();
        return temp;
    }

    // overloaded subtraction (-) operator to calculate difference in days
    int operator-(
        Date& other) {
        // Convert both dates to "days since 01/01/1900"
        int totalDays1 = totalDaysSinceEpoch();
        int totalDays2 = other.totalDaysSinceEpoch();
        return abs(totalDays1 - totalDays2);
    }

    // Calculate total days since 01/01/1900 (helps with subtraction)
    int totalDaysSinceEpoch()  {
        int days = year * 365 + day;
        for (int m = 1; m < month; m++) {
            days += getNumDays(m, year);
        }
        days += countLeapYears(year);
        return days;
    }

    // Count leap years up to the given year
    int countLeapYears(int y) const {
        return y / 4 - y / 100 + y / 400;
    }

    // Display date as m/d/yyyy
    void displayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }

    // Display date as "Month Day, Year"
    void displayDate2() {
        cout << months[month - 1] << " " << day << ", " << year << endl;
    }

    // Display date as "Day Month Year"
    void displayDate3() {
        cout << day << " " << months[month - 1] << " " << year << endl;
    }
};

int main() {
    // Test Plan

    Date date1;  // Default constructor

    cout << "Test 1 - Default Constructor (displayDate()): ";
    date1.displayDate();  // Should show 1/1/1900

    Date date2(4, 18, 2014);  // Parameterized constructor
    cout << "Test 2 - Parameterized Constructor (displayDate2()): ";
    date2.displayDate2();  // Should show "April 18, 2014"

    Date date3;
    date3.setDate(13, 45, 2018);  // Invalid date
    cout << "Test 3 - Invalid Date: ";
    date3.displayDate();  // Should default to 1/1/1900

    Date date4;
    date4.setDate(4, 31, 2000);  // Invalid date
    cout << "Test 4 - Invalid Date: ";
    date4.displayDate();  // Should default to 1/1/1900

    Date date5;
    date5.setDate(2, 29, 2009);  // Invalid leap year date
    cout << "Test 5 - Invalid Date: ";
    date5.displayDate();  // Should default to 1/1/1900

    Date date6(4, 10, 2014);
    Date date7(4, 18, 2014);
    cout << "Test 7 - Date subtraction (difference in days): ";
    cout << date7 - date6 << " days" << endl;  // Should print "8 days"

    Date date8(2, 2, 2006);
    Date date9(11, 10, 2003);
    cout << "Test 8 - Date subtraction (difference in days): ";
    cout << date8 - date9 << " days" << endl;  // Should print "815 days"

    Date date10(2, 29, 2008);
    cout << "Test 9 - Pre-decrement operator: ";
    --date10;
    date10.displayDate();  // Should print 1/31/2008

    Date date11(2, 29, 2008);
    cout << "Test 10 - Pre-increment operator: ";
    ++date11;
    date11.displayDate();  // Should print 2/29/2008

    Date date12(12, 31, 2024);
    cout << "Test 12 - Post-increment operator: ";
    date12++;
    date12.displayDate();  // Should print 1/1/2025

    Date date13(12, 31, 2024);
    cout << "Test 13 - Post-decrement operator: ";
    date13--;
    date13.displayDate();  // Should print 12/31/2024

    cout << "Test 15 - Using cin (>>) operator to input a date(format:1/1/1900): ";
    Date date14;
    cin >> date14;  // Input date from user
    cout << "Date entered: " << date14 << endl;  // Output the entered date
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
