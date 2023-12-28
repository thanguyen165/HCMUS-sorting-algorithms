#include "shellSort.hpp"

void shellSort(int arr[], int n, long long &comparisons) {
    comparisons = 0;

    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = n / 2; ++comparisons && (interval > 0); interval /= 2) {
        // insertion sort for interval
        int selected = 0, j = 0;

        for (int i = interval; ++comparisons && (i < n); i++) {
            selected = arr[i];
            j = i;

            while ((++comparisons && (j >= interval)) && (++comparisons && (arr[j - interval] > selected))) {
                arr[j] = arr[j - interval];
                j -= interval;
            }
            arr[j] = selected;
        }
    }

    return;
}

void shellSort(int arr[], int n) {
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = n / 2; interval > 0; interval /= 2) {
        // insertion sort for interval
        int selected = 0, j = 0;

        for (int i = interval; i < n; i++) {
            selected = arr[i];
            j = i;

            while ((j >= interval) && (arr[j - interval] > selected)) {
                arr[j] = arr[j - interval];
                j -= interval;
            }
            arr[j] = selected;
        }
    }

    return;
}