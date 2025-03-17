//Thomas Cubsyead
//3/17/25
//Intro to Classes
//Number_Array_Class
//creates an array with 10 values and tests its bounds in a program using rnadom numbers and 0's

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class NumberArray {
private:
    double* arr;       // Pointer to the dynamically allocated array
    int size;          // Size of the array
    static const int MAX_SIZE = 10;  // Default size
    static const int DEFAULT_VALUE = 10000.0;  // Default value for out of bounds retrieval

public:
    // Constructor that initializes the array with zeros
    NumberArray(int size = MAX_SIZE) {
        this->size = size;
        arr = new double[size];

        for (int i = 0; i < size; ++i) {
            arr[i] = 0.0;
        }
        cout << "Array of size " << size << " created." << endl;
    }

    // Destructor that frees the allocated memory
    ~NumberArray() {
        delete[] arr;
        cout << "The destructor is running." << endl;
    }

    // Store a number in the array at a specified index
    void setNumber(int index, double value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
        else {
            cout << "The index is out of the bounds of the array, number not stored" << endl;
        }
    }

    // Retrieve a number from the array at a specified index
    double getNumber(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        else {
            cout << "The index is out of the bounds of the array, returning default" << endl;
            return DEFAULT_VALUE;
        }
    }

    // Find and return the minimum value in the array
    double getMinValue() {
        double min = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    // Find and return the maximum value in the array
    double getMaxValue() {
        double max = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    // Calculate and return the average of the values in the array
    double getAverage() {
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return sum / size;
    }

    // Print the array
    void printArray() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Get the size of the array (for testing)
    int getSize() const {
        return size;
    }
};

int main() {
    // Test the default constructor
    cout << "----- Test constructors -----" << endl;
    NumberArray arr1;  // Default size is 10
    cout << "From default constructor: ";
    arr1.printArray();

    // Test the constructor with a custom size
    int custom_size = 15;
    NumberArray arr2(custom_size);  // Custom size 15
    cout << "From constructor with parameters: ";
    arr2.printArray();

    // Test mutator: Fill array with random numbers
    cout << "\n----- Test mutator -----" << endl;
    srand(time(0)); // Initialize random seed
    cout << "Array filled with numbers:" << endl;

    // Fill the array with random floating point numbers between 1.0 and 100.0
    for (int i = 0; i < arr2.getSize(); ++i) {
        double num = 1.0 + (rand() % 10000) / 100.0;  // Random number between 1.0 and 100.0
        arr2.setNumber(i, num);
    }
    arr2.printArray();

    // Test out of bounds access for mutator
    cout << "\nTrying to set a number with an out of bounds index (20):" << endl;
    arr2.setNumber(20, 42.0);

    // Test accessors
    cout << "\n----- Test accessors -----" << endl;
    cout << "Access item at index 5: " << fixed << setprecision(1) << arr2.getNumber(5) << endl;
    cout << "Access item at index 20 (out of bounds): " << fixed << setprecision(1) << arr2.getNumber(20) << endl;

    // Test getting minimum, maximum, and average values
    cout << "\nThe minimum value in the array is: " << fixed << setprecision(1) << arr2.getMinValue() << endl;
    cout << "The maximum value in the array is: " << fixed << setprecision(1) << arr2.getMaxValue() << endl;
    cout << "The average of the values in the array is: " << fixed << setprecision(1) << arr2.getAverage() << endl;

    // Destructor will be called here when the program exits
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
