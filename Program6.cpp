//      program to create a stack and implement push and pop operation

#include <iostream>

using namespace std;

#define MAX_SIZE 100 // Maximum size of the stack

class Stack {
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() {
        top = -1; // Initialize top to -1 (empty stack)
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[++top] = data;
            cout << data << " pushed to stack" << endl;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1; // Return an error value (you can choose any value)
        } else {
            int data = arr[top--];
            return data;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Popped element: " << s.pop() << endl;

    s.display();

    return 0;
}