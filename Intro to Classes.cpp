//Thomas Cubsyead
//3/17/25
//Intro to Classes
//Number_Array_Class
//

#include <iostream>
#include <limits>
using namespace std;

class NumberArray {
private:
    float* arr;
    int size;

public:
    NumberArray(int n) {
        size = n;
        arr = new float[size];
    }

    ~NumberArray() {
        delete[] arr;
    }

    void storeNumber(int index, float value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        } else {
            cout << "out of bounds" << endl;
        }
    }

    float retrieveNumber(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            cout << "out of bounds" << endl;
            return -1;
        }
    }

    float highestValue() {
        float highest = arr[0];
            for (int i = 0; i < size; ++i) {
                if (arr[i] > highest) {
                    highest = arr[i];
                }
        }
        return highest;
    }

    float lowestValue() {
        float lowest = arr[0];
        for (int i = 0; i < size; ++i) {
            if (arr[i] < lowest) {
                lowest = arr[i];
            }
        }
        return lowest;
    }

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

    cout << "enter the size of the array" << endl;
    cin >> n;

    NumberArray numArray(n);

    for (int i = 0; i < n; ++i) {
        float value;
        cout << "enter the value of number " << i + 1 << ": " << endl;
        cin >> value;
        numArray.storeNumber(i, value);
    }

    cout << "\nHere is your inputted array: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "element " << i + 1 << ": " << numArray.retrieveNumber(i) << endl;
    }

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
