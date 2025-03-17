//Thomas Cubsyead
//3/17/25
//Intro to Classes
//Number_Array_Class
//

#include <iostream>
#include <limits>
using namespace std;

//defines class for an array of numbers with variable size and input based on user input
class NumberArray {
private:
    float* arr;
    int size;

public:
    NumberArray(int n) {
        size = n;
        arr = new float[size];
    }

    //destructor to deallocate memory
    ~NumberArray() {
        delete[] arr;
    }

    //stores the user inputed numbers into the array and sends error code if it is out of bounds
    void storeNumber(int index, float value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        } else {
            cout << "out of bounds" << endl;
        }
    }

    //gets the numbers from the array to display one at a time and sends error code if it is out of bounds
    float retrieveNumber(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            cout << "out of bounds" << endl;
            return -1;
        }
    }

    //function to determine the highest value in the array by comparing eac value to one another
    float highestValue() {
        float highest = arr[0];
            for (int i = 0; i < size; ++i) {
                if (arr[i] > highest) {
                    highest = arr[i];
                }
        }
        return highest;
    }

    //function to determine the lowest value in the array by comparing each value to one another
    float lowestValue() {
        float lowest = arr[0];
        for (int i = 0; i < size; ++i) {
            if (arr[i] < lowest) {
                lowest = arr[i];
            }
        }
        return lowest;
    }

    //function that gets the average of the array by adding each inputted number then dividing by the size of the array
    float average() {
        float sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return sum / size;
    }
};

int main() {
    int n;

    //user inputs size of the array
    cout << "enter the size of the array" << endl;
    cin >> n;

    NumberArray numArray(n);

    //user inputs all of the numbers held in  the array
    for (int i = 0; i < n; ++i) {
        float value;
        cout << "enter the value of number " << i + 1 << ": " << endl;
        cin >> value;
        numArray.storeNumber(i, value);
    }

    //displays the array
    cout << "\nHere is your inputted array: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "element " << i + 1 << ": " << numArray.retrieveNumber(i) << endl;
    }

    //displays the highest and lowest values and the average with functions defined in the class
    cout << "\nThe highest value in the array is: " << numArray.highestValue() << endl;

    cout << "The lowest value in the array is: " << numArray.lowestValue() << endl;

    cout << "The average of the total values in the array is: " << numArray.average() << endl;

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
