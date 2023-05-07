#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left child index
    int r = 2*i + 2; // right child index

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n-1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Generate n random elements and store them in an array
    int arr[n];
    printf("Randomly generated elements: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using heap sort
    heapsort(arr, n);

    // Print the sorted array
    printf("Sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
