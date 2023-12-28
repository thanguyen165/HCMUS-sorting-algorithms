#include "countingSort.hpp"

void countingSort(int arr[], int n, long long &comparisons) {
    comparisons = 0;

    // Finding the maximum element
    int h = max(arr, n, comparisons);

    // frequency
    int* f = new int[h + 1](); // set all member to 0

    for (int i = 0; ++comparisons && (i < n); i++) f[arr[i]]++;
    for (int i = 1; ++comparisons && (i <= h); i++) f[i] += f[i - 1];

    // temp array to save sorted data
    int* b = new int[n];

    for (int i = n - 1; ++comparisons && (i >= 0); i--) {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }

    // copy back to origin array
    for (int i = 0; ++comparisons && (i < n); i++) arr[i] = b[i];

    delete[] f;
    delete[] b;

    return;
}

void countingSort(int arr[], int n) {
    // Finding the maximum element
    int h = max(arr, n);

    // frequency
    int* f = new int[h + 1](); // set all member to 0

    for (int i = 0; i < n; i++) f[arr[i]]++;
    for (int i = 1; i <= h; i++) f[i] += f[i - 1];

    // temp array to save sorted data
    int* b = new int[n];

    for (int i = n - 1; i >= 0; i--) {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }

    // copy back to origin array
    for (int i = 0; i < n; i++) arr[i] = b[i];

    delete[] f;
    delete[] b;

    return;
}