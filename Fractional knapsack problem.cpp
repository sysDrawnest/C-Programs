#include <stdio.h>
#include <stdlib.h>

// Structure to represent each item
struct Item {
    int value; // Value of the item
    int weight; // Weight of the item
    float ratio; // Value-to-weight ratio
};

// Comparison function for sorting items based on their value-to-weight ratio in non-increasing order
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio);
}

// Function to solve fractional knapsack problem
float fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Sort items based on their value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    float totalValue = 0.0; // Total value obtained

    // Fill the knapsack greedily
    for (int i = 0; i < n; i++) {
        if (capacity <= 0)
            break;

        if (items[i].weight <= capacity) {
            // Take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            totalValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50; // Capacity of the knapsack
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}}; // Array of items: {value, weight}
    int n = sizeof(items) / sizeof(items[0]); // Number of items

    float maxValue = fractionalKnapsack(capacity, items, n);

    printf("Maximum value that can be obtained = %.2f\n", maxValue);

    return 0;
}

