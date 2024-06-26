#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // return the index if key is found
        }
    }
    return -1; // return -1 if key is not found
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int marks[size];
    cout << "Enter the marks of the students:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];
    }

    int key;
    cout << "Enter the mark you want to search: ";
    cin >> key;

    int index = linearSearch(marks, size, key);
    if (index != -1) {
        cout << "Mark " << key << " found at index " << index << endl;
    } else {
        cout << "Mark " << key << " not found in the array" << endl;
    }

    return 0;
}