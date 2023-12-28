#include "selectionSort.hpp"

void selectionSort(int arr[], int n, long long &comparisons) {
    comparisons = 0;
    int min_idx = 0;
 
    // One by one move boundary of unsorted subarray
    for (int i = 0; ++comparisons && (i < n - 1); i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (int j = i + 1; ++comparisons && (j < n); j++) {
            if (++comparisons && (arr[j] < arr[min_idx]))
                min_idx = j;
        }
 
        // Swap the minimum element with the first element of unsorted subarray
        if (++comparisons && (min_idx != i))
            swap(arr[min_idx], arr[i]);
    }
    
    return;
}

void selectionSort(int arr[], int n) {
    int min_idx = 0;
 
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
 
        // Swap the minimum element with the first element of unsorted subarray
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
    
    return;
}