//    Program to create a linked list and implement insertion and deletion operations on it

#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the beginning of the linked list
void deleteAtBeginning(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

// Function to delete a node from the end of the linked list
void deleteAtEnd(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Initialize head as null

    // Inserting nodes
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);

    cout << "Linked List: ";
    printList(head);

    // Deleting nodes
    deleteAtBeginning(&head);
    deleteAtEnd(&head);

    cout << "Linked List after deletion: ";
    printList(head);

    return 0;
}