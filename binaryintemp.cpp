#include <iostream>
using namespace std;

// Template function for binary search
template <typename T>
int binarySearch(T arr[], int size, T key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // To prevent overflow

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid; // Key found
        }
        // If key is greater, ignore the left half
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        // If key is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Key not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the element to search: ";
    cin >> key;

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
