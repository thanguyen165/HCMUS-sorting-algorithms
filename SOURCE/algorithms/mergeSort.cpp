#include "mergeSort.hpp"

void merge(int arr[], int l, int mid, int r, long long &comparisons) {
    int const left_size = mid - l + 1;
    int const right_size = r - mid;

    // Create temp arrays
    auto *leftArr = new int[left_size],
    *rightArr = new int[right_size];

    // Copy data to temp arrays leftArr[] and rightArr[]
    for (int i = 0; ++comparisons &&  (i < left_size); i++)
        leftArr[i] = arr[l + i];

    for (int j = 0; ++comparisons && (j < right_size); j++)
        rightArr[j] = arr[mid + 1 + j];

    int left_idx = 0, right_idx = 0;
    int merged_idx = l;

    // push the smallest element of leftArr[] and rightArr[] to original array
    while ((++comparisons && (left_idx < left_size)) && (++comparisons && (right_idx < right_size))) {
        if (++comparisons && (leftArr[left_idx] <= rightArr[right_idx])) {
            arr[merged_idx] = leftArr[left_idx];
            left_idx++;
        }
        else {
            arr[merged_idx] = rightArr[right_idx];
            right_idx++;
        }
        merged_idx++;
    }

    // Copy the remaining elements of leftArr[], if there are any
    while (++comparisons &&(left_idx < left_size)) {
        arr[merged_idx] = leftArr[left_idx];
        left_idx++;
        merged_idx++;
    }

    // Copy the remaining elements of rightArr[], if there are any
    while (++comparisons && (right_idx < right_size)) {
        arr[merged_idx] = rightArr[right_idx];
        right_idx++;
        merged_idx++;
    }

    delete[] leftArr;
    delete[] rightArr;

    return;
}

void mergeSort_I(int arr[], int l, int r, long long &comparisons) {
    if (++comparisons && (l >= r))
        return;
    int mid = l + (r - l) / 2;
    mergeSort_I(arr, l, mid, comparisons);
    mergeSort_I(arr, mid + 1, r, comparisons);
    merge(arr, l, mid, r, comparisons);
}

void mergeSort(int arr[], int n, long long &comparisons) {
    comparisons = 0;
    mergeSort_I(arr, 0, n - 1, comparisons);
    return;
}

void merge(int arr[], int l, int mid, int r) {
    int const left_size = mid - l + 1;
    int const right_size = r - mid;

    // Create temp arrays
    auto *leftArr = new int[left_size],
    *rightArr = new int[right_size];

    // Copy data to temp arrays leftArr[] and rightArr[]
    for (int i = 0; i < left_size; i++)
        leftArr[i] = arr[l + i];

    for (int j = 0; j < right_size; j++)
        rightArr[j] = arr[mid + 1 + j];

    int left_idx = 0, right_idx = 0;
    int merged_idx = l;

    // push the smallest element of leftArr[] and rightArr[] to original array
    while ((left_idx < left_size) && (right_idx < right_size)) {
        if (leftArr[left_idx] <= rightArr[right_idx]) {
            arr[merged_idx] = leftArr[left_idx];
            left_idx++;
        }
        else {
            arr[merged_idx] = rightArr[right_idx];
            right_idx++;
        }
        merged_idx++;
    }

    // Copy the remaining elements of leftArr[], if there are any
    while (left_idx < left_size) {
        arr[merged_idx] = leftArr[left_idx];
        left_idx++;
        merged_idx++;
    }

    // Copy the remaining elements of rightArr[], if there are any
    while (right_idx < right_size) {
        arr[merged_idx] = rightArr[right_idx];
        right_idx++;
        merged_idx++;
    }

    delete[] leftArr;
    delete[] rightArr;

    return;
}

void mergeSort_I(int arr[], int l, int r) {
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort_I(arr, l, mid);
    mergeSort_I(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void mergeSort(int arr[], int n) {
    mergeSort_I(arr, 0, n - 1);
    return;
}