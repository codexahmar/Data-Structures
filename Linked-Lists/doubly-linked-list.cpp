#include <iostream>
using namespace std;

// Define the structure for each node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a new node with the given data at the end of the doubly linked list
Node* insert(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to delete the node with the given data from the doubly linked list
Node* deleteNode(Node* head, int data) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }

    Node* current = head;
    while (current != nullptr && current->data != data) {
        current = current->next;
    }

    if (current != nullptr) {
        Node* prevNode = current->prev;
        prevNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = prevNode;
        }
        delete current;
    }

    return head;
}

// Function to display all elements of the doubly linked list in forward order
void displayForward(Node* head) {
    cout << "Doubly Linked List (forward): ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to interact with the doubly linked list
int main() {
    Node* head = nullptr;
    int choice, value;

    while (true) {
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                head = insert(head, value);
                break;
            case 2:
                if (head == nullptr) {
                    cout << "List is empty. Nothing to delete." << endl;
                } else {
                    cout << "Enter value to delete: ";
                    cin >> value;
                    head = deleteNode(head, value);
                }
                break;
            case 3:
                if (head == nullptr) {
                    cout << "List is empty." << endl;
                } else {
                    displayForward(head);
                }
                break;
            case 4:
                cout << "Exiting program." << endl;
                // Free memory: deallocate all nodes
                while (head != nullptr) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}