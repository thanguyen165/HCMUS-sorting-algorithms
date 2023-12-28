#include "insertionSort.hpp"

void insertionSort(int arr[], int n, long long &comparisons) {
    comparisons = 0;
    int selected = 0, j = 0;

    for (int i = 1; ++comparisons && (i < n); i++) {
        selected = arr[i];
        j = i - 1;
 
        // Find place to insert selected element into sorted segment arr[0..i - 1]
        while ((++comparisons && (j >= 0)) && (++comparisons && (arr[j] > selected))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }

    return;
}

void insertionSort(int arr[], int n) {
    int selected = 0, j = 0;

    for (int i = 1; i < n; i++) {
        selected = arr[i];
        j = i - 1;
 
        // Find place to insert selected element into sorted segment arr[0..i - 1]
        while ((j >= 0) && (arr[j] > selected)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }

    return;
}