#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of queue: ";
    cin >> size;
    int queue[size], option, rear = -1, front = -1; // Initialize rear to -1 to indicate an empty queue
    do {
        cout << "Enter 0 to stop, 1 for enqueue and 2 for dequeue: ";
        cin >> option;
        if (option == 0) {
            cout << "Program stopped!\n";
            break;
        } else if (option == 1) {
            if (rear == size - 1) {
                cout << "Queue Overflow\n";
            } else {
                int value;
                cout << "Enter the value you want to enqueue: ";
                cin >> value;
                rear++;
                queue[rear] = value;
                cout << value << " has been enqueued!\n";
                if (front == -1) {
                    front ++;
                }
            }
        } else if (option == 2) {
            if (front == -1 || front > rear) {
                cout << "No Elements in queue\n";
            } else {
                int number = queue[front];
                cout << number << " has been dequeued!\n";
                front++;
            }
        }
    } while (option != 0);
    return 0;
}