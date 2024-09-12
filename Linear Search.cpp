#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if target found
        }
    }
    return -1; // Return -1 if target not found
}

// Main function
int main() {
    int arr[] = {10, 23, 4, 5, 16, 7};
    int target = 16;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

