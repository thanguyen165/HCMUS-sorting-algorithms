#include "heapSort.hpp"

void heapify(int arr[], int l, int r, long long &comparisons) {
    int i = l;
    int j = 2 * i + 1;
    int x = arr[i];

    while (++comparisons && (j <= r)) {
        if (++comparisons && (j < r)) {
            // j point to larger value
            if (++comparisons && (arr[j] < arr[j + 1])) j++;
        }

        if (++comparisons && (x >= arr[j])) break;

        swap(arr[j], arr[i]);
        // prepare for new loop
        i = j; j = 2 * i + 1;
    }
}

void prepareHeap(int arr[], int n, long long &comparisons) {
    for (int l = n / 2 - 1; ++comparisons && (l >= 0); l--) {
        heapify(arr, l, n - 1, comparisons); // n - 1 because last element has index of n - 1
    }
}

void heapSort(int arr[], int n, long long &comparisons) {
    comparisons = 0;

    prepareHeap(arr, n, comparisons);
    int r = n - 1;
	while (++comparisons && (r > 0)) {
		swap(arr[0], arr[r]);
		r--;
		heapify(arr, 0, r, comparisons);
	}
}

void heapify(int arr[], int l, int r) {
    int i = l;
    int j = 2 * i + 1;
    int x = arr[i];

    while (j <= r) {
        if (j < r) {
            // j point to larger value
            if (arr[j] < arr[j + 1]) j++;
        }

        if (x >= arr[j]) break;

        swap(arr[j], arr[i]);
        // prepare for new loop
        i = j; j = 2 * i + 1;
    }
}

void prepareHeap(int arr[], int n) {
    for (int l = n / 2 - 1; l >= 0; l--) {
        heapify(arr, l, n - 1); // n - 1 because last element has index of n - 1
    }
}

void heapSort(int arr[], int n) {
    prepareHeap(arr, n);
    int r = n - 1;
	while (r > 0) {
		swap(arr[0], arr[r]);
		r--;
		heapify(arr, 0, r);
	}
}