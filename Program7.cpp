//   Program to create a queue and implement insertion and deletion operation on it

#include <iostream>

using namespace std;

#define MAX_SIZE 100 // Maximum size of the queue

class Queue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
        } else {
            if (isEmpty()) {
                front = 0;
            }
            arr[++rear] = data;
            cout << data << " enqueued to queue" << endl;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1; // Return an error value
        } else {
            int data = arr[front];
            if (front == rear) {
                front = rear = -1; // If only one element, reset both pointers
            } else {
                front++;
            }
            return data;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Dequeued element: " << q.dequeue() << endl;

    q.display();

    return 0;
}