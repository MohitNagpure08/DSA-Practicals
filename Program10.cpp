#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // To prevent overflow

        // Check if the target is at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }

        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int size, target;

    // Input size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    // Input sorted array elements
    cout << "Enter " << size << " sorted elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Input the target element to search
    cout << "Enter the element to search: ";
    cin >> target;

    // Perform binary search
    int result = binarySearch(arr, size, target);

    // Output the result
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}

