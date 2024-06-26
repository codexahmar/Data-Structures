#include<iostream>
using namespace std;

int main() {
    int maxSize;
    cout << "Enter the maximum size of the array: " << endl;
    cin >> maxSize;
    int arr[maxSize];
    cout << "Enter " << maxSize << " elements for the array:" << endl;
    for (int i = 0; i < maxSize; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Original Array:" << endl;
    for (int i = 0; i < maxSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int pos, num;
    cout << "Enter the position of the number you want to insert: " << endl;
    cin >> pos;
    cout << "Enter the number that you want to insert: " << endl;
    cin >> num;
    if (pos >= 1 && pos <= maxSize + 1) {
        for (int i = maxSize - 1; i >= pos - 1; i--) {
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = num;
        int newSize = maxSize + 1;
        cout << "New Array:" << endl;
        for (int i = 0; i < newSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Invalid position. Please enter a position between 1 and " << maxSize + 1 << "." << endl;
    }

    return 0;
}
