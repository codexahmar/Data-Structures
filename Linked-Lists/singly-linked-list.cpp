#include<iostream>
using namespace std;

// Define the structure for each node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node with the given data at the end of the linked list
void insert(Node*& head, int data) {
    // Create a new node
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    // If the list is empty, set the new node as the head
    if (head == nullptr) {
        head = newNode;
    } else {
        // Traverse to the end of the list
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        // Insert the new node at the end
        current->next = newNode;
    }
}

// Function to print all elements of the linked list
void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Main function to test the linked list operations
int main() {
    // Initialize an empty linked list
    Node* head = nullptr;
    int num_elements, value;

    // Ask the user for the number of elements to insert
    cout << "Enter the number of elements to insert: ";
    cin >> num_elements;

    // Insert elements into the linked list based on user input
    cout << "Enter " << num_elements << " numbers:\n";
    for (int i = 0; i < num_elements; ++i) {
        cout << "Enter value " << i+1 << ": ";
        cin >> value;
        insert(head, value);
    }

    // Display the elements of the linked list
    cout << "Linked List: ";
    display(head);

    // Free memory: deallocate all nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}