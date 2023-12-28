#include "quickSort.hpp"

// smaller element than pivot goes left and higher element goes right
int partition(int arr[], int l, int r, long long &comparisons) {
	// choose the pivot
	swap(arr[random(l, r)], arr[r]);
	int pivot = arr[r];

	// Index of smaller element and Indicate
	// the right position of pivot found so far
	int i = (l - 1);

	for(int j = l; ++comparisons && (j <= r); j++) {
		// If current element is smaller than the pivot
		if(++comparisons && (arr[j] < pivot)) {
			// Increment index of smaller element
			i++;
		swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return (i + 1);
}

void quickSort_I(int arr[], int l, int r, long long &comparisons) {
	if(++comparisons && (l >= r))
		return;

	int pivot = partition(arr, l, r, comparisons);
	
	// Sort left and right subarray
	quickSort_I(arr, l, pivot - 1, comparisons);
	quickSort_I(arr, pivot + 1, r, comparisons);
}

void quickSort(int arr[], int n, long long &comparisons) {
	comparisons = 0;
	quickSort_I(arr, 0, n - 1, comparisons);
	return;
}

// smaller element than pivot goes left and higher element goes right
int partition(int arr[], int l, int r) {
	// choose the pivot
	swap(arr[random(l, r)], arr[r]);
	int pivot = arr[r];

	// Index of smaller element and Indicate
	// the right position of pivot found so far
	int i = (l - 1);

	for(int j = l; j <= r; j++) {
		// If current element is smaller than the pivot
		if(arr[j] < pivot) {
			// Increment index of smaller element
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return (i + 1);
}

void quickSort_I(int arr[], int l, int r) {
	if (l >= r)
		return;

	int pivot = partition(arr, l, r);
	
	// Sort left and right subarray
	quickSort_I(arr, l, pivot - 1);
	quickSort_I(arr, pivot + 1, r);
}

void quickSort(int arr[], int n) {
	quickSort_I(arr, 0, n - 1);
	return;
}