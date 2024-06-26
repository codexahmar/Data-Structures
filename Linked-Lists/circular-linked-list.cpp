#include <iostream>
using namespace std;

// Define the structure for each node in the circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a new node with the given data at the end of the circular linked list
Node* insert(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr) {
        newNode->next = newNode; // Point to itself to form a circular list
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head; // Make the new node point to the head to form the circular structure
    return head;
}

// Function to delete the node with the given data from the circular linked list
Node* deleteNode(Node* head, int data) {
    if (head == nullptr) {
        cout << "Circular Linked List is empty. Nothing to delete." << endl;
        return nullptr;
    }

    // If the node to delete is the head node
    if (head->data == data) {
        Node* temp = head;
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = head->next;
        head = head->next;
        delete temp;
        return head;
    }

    Node* prev = nullptr;
    Node* current = head;

    // Traverse the list to find the node to delete
    do {
        prev = current;
        current = current->next;
    } while (current != head && current->data != data);

    // If the node is found, delete it
    if (current != head) {
        prev->next = current->next;
        delete current;
    }

    return head;
}

// Function to display all elements of the circular linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Main function to interact with the circular linked list
int main() {
    Node* head = nullptr;
    int choice, value;

    while (true) {
        cout << "Enter 1 to insert, 2 to delete, 3 to display, or 4 to exit: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> value;
            head = insert(head, value);
        } else if (choice == 2) {
            head = deleteNode(head, value);
            if (head != nullptr)
                cout << "Enter value to delete: ";
            cin >> value;
        } else if (choice == 3) {
            display(head);
        } else if (choice == 4) {
            cout << "Exiting program." << endl;
            // Free memory: deallocate all nodes
            if (head != nullptr) {
                Node* temp = head->next;
                while (temp != head) {
                    Node* delNode = temp;
                    temp = temp->next;
                    delete delNode;
                }
                delete head;
            }
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}