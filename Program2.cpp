#include <iostream>

using namespace std;

int main() {
    int arr[5]; 

    cout << "Enter 5 elements: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int highest = arr[0];
    int lowest = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    
    cout << "Highest element: " << highest << endl;
    cout << "Lowest element: " << lowest << endl;

    return 0;
}