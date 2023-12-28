#include "radixSort.hpp"

// Counting sort of arr[] according to the digit represented by exp
void countingSort(int arr[], int n, int exp, long long &comparisons) {
    const int k = 10; // 0 to 9
    int *output = new int[n];
    int count[k] = {0};

    // Count occurrences of each digit in the input array
    for (int i = 0; ++comparisons && (i < n); i++)
        count[(arr[i] / exp) % 10]++;

    // Update count[i] to store the position of the next occurrence
    for (int i = 1; ++comparisons && (i < k); i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; ++comparisons && (i >= 0); i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[] so that arr[] contains sorted numbers based on current digit
    for (int i = 0; ++comparisons && (i < n); i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int n, long long &comparisons) {
    comparisons = 0;
    // Find the maximum number to know the number of digits
	int max_element = max(arr, n, comparisons);

    // Do counting sort for every digit
    for (int exp = 1; ++comparisons && (max_element / exp > 0); exp *= 10)
        countingSort(arr, n, exp, comparisons);
}

// Counting sort of arr[] according to the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    const int k = 10; // 0 to 9
    int *output = new int[n];
    int count[k] = {0};

    // Count occurrences of each digit in the input array
    for (int i = 0;i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count[i] to store the position of the next occurrence
    for (int i = 1;i < k; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1;i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[] so that arr[] contains sorted numbers based on current digit
    for (int i = 0;i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
	int max_element = max(arr, n);

    // Do counting sort for every digit
    for (int exp = 1; max_element / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}