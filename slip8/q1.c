#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i which is an index in arr[]
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2*i + 1; // Left child
    int right = 2*i + 2; // Right child
 
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heapsort function to sort an array of size n
void heapsort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array
    int *arr = malloc(n * sizeof(int));
    
    // Generate n random numbers and store them in the array
    printf("Generating %d random numbers...\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%100;
    }
    
    // Print the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort the array using heapsort
    heapsort(arr, n);
    
    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free the dynamically allocated memory
    free(arr);
    
    return 0;
}
