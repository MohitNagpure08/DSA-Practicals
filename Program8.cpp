#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int* queue;

public:
    CircularQueue(int size) {
        this->size = size;
        front = -1;
        rear = -1;
        queue = new int[size];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to insert an element into the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert " << value << endl;
            return;
        }

        if (front == -1) { // First insertion
            front = 0;
        }

        rear = (rear + 1) % size;
        queue[rear] = value;
        cout << "Inserted " << value << " into the queue." << endl;
    }

    // Function to delete an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot delete." << endl;
            return;
        }

        cout << "Deleted " << queue[front] << " from the queue." << endl;

        if (front == rear) { // Last element being removed
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements are: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;

    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircularQueue cq(size);

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;

        case 2:
            cq.dequeue();
            break;

        case 3:
            cq.display();
            break;

        case 4:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
