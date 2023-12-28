#include "shakerSort.hpp"

void shakerSort(int arr[], int n, long long &comparisons) {
    comparisons = 0;

    bool swapped = true;
    int start = 0;
    int end = n - 1;
 
    while (swapped) {
        // reset the swapped flag
        swapped = false;
 
        // bubble sort from left to right
        for (int i = start; ++comparisons && (i < end); i++) {
            if (++comparisons && (arr[i] > arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
 
        // if nothing moved, then array is sorted.
        if (!swapped)
            break;
 
        // otherwise, reset the swapped flag
        swapped = false;
 
        // item at the end is in its rightful spot, so decrease the end
        end--;
 
        // bubble sort from right to left
        for (int i = end - 1; ++comparisons && (i >= start); i--) {
            if (++comparisons && (arr[i] > arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
 
        // imtem at the start is in its rightful spot, so increase the start
        start++;
    }
}

void shakerSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;
 
    while (swapped) {
        // reset the swapped flag
        swapped = false;
 
        // bubble sort from left to right
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
 
        // if nothing moved, then array is sorted.
        if (!swapped)
            break;
 
        // otherwise, reset the swapped flag
        swapped = false;
 
        // item at the end is in its rightful spot, so decrease the end
        end--;
 
        // bubble sort from right to left
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
 
        // imtem at the start is in its rightful spot, so increase the start
        start++;
    }
}