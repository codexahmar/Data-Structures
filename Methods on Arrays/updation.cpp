#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int marks[size];

    // Input marks for students
    for (int k = 0; k < size; k++) {
        cout << "Enter marks of student " << k + 1 << ": ";
        cin >> marks[k];
    }

    // Output the original marks
    cout << "Original marks: ";
    for (int i = 0; i < size; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    // Update elements of the array
    int index, newValue;
    cout << "Enter the index of the element you want to update: ";
    cin >> index;

    if (index >= 0 && index < size) {
        cout << "Enter the new value: ";
        cin >> newValue;
        marks[index] = newValue;
        cout << "Element at index " << index << " updated successfully." << endl;
    } else {
        cout << "Invalid index! Index should be between 0 and " << size - 1 << "." << endl;
    }

    // Output the updated marks
    cout << "Updated marks: ";
    for (int i = 0; i < size; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    return 0;
}