

#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of stack: ";
    cin >> size;
    int stack[size], option, top = -1; // Initialize top to -1 to indicate an empty stack
    do {
        cout << "Enter 0 to stop, 1 to push and 2 to pop: ";
        cin >> option;
        if (option == 0) {
            cout << "Program stopped!\n";
            break;
        } else if (option == 1) {
            if (top == size - 1) {
                cout << "Stack Overflow\n";
            } else {
                int value;
                cout << "Enter the value you want to push: ";
                cin >> value;
                top++;
                stack[top] = value;
                cout << value << " has been pushed!\n";
            }
        } else if (option == 2) {
            if (top == -1) {
                cout << "No Elements in Stack\n";
            } else {
                int number = stack[top];
                cout << number << " has been popped!\n";
                top--;
            }
        }
    } while (option != 0);
    return 0;
}