#include<iostream>
using namespace std;
int main() {
    int maxSize;
    cout<<"Enter the maximum size of the array: "<<endl;
    cin>>maxSize;
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
    int pos;
    cout << "Enter the position of the number you want to delete: " <<endl;
    cin >> pos;
    if (pos >= 0 && pos <= maxSize) {
        for (int i = pos - 1; i < maxSize - 1; i++) {
            arr[i] = arr[i + 1];
        }
        int newSize = maxSize - 1;
        cout << "New Array:" << endl;
        for (int i = 0; i < newSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Invalid position. Please enter a position between 1 and " << maxSize << "." << endl;
    }

    return 0;
}