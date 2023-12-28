#include "sort_execute.hpp"

void sort(int arr[], int N, int algorithmID, long long &comparisons) {
    comparisons = 0;

    switch (algorithmID) {
        case SELECTION_SORT:
            selectionSort(arr, N, comparisons);
            break;
        case INSERTION_SORT:
            insertionSort(arr, N, comparisons);
            break;
        case BUBBLE_SORT:
            bubbleSort(arr, N, comparisons);
            break;
        case SHAKER_SORT:
            shakerSort(arr, N, comparisons);
            break;
        case SHELL_SORT:
            shellSort(arr, N, comparisons);
            break;
        case HEAP_SORT:
            heapSort(arr, N, comparisons);
            break;
        case MERGE_SORT:
            mergeSort(arr, N, comparisons);
            break;
        case QUICK_SORT:
            quickSort(arr, N, comparisons);
            break;
        case COUNTING_SORT:
            countingSort(arr, N, comparisons);
            break;
        case RADIX_SORT:
            radixSort(arr, N, comparisons);
            break;
        case FLASH_SORT:
            flashSort(arr, N, comparisons);
            break;
        default:
            break;
    }
}

void sort(int arr[], int N, int algorithmID, std::chrono::duration<double, std::milli> &running_time) {
    const auto start = std::chrono::high_resolution_clock::now();

    switch (algorithmID) {
        case SELECTION_SORT:
            selectionSort(arr, N);
            break;
        case INSERTION_SORT:
            insertionSort(arr, N);
            break;
        case BUBBLE_SORT:
            bubbleSort(arr, N);
            break;
        case SHAKER_SORT:
            shakerSort(arr, N);
            break;
        case SHELL_SORT:
            shellSort(arr, N);
            break;
        case HEAP_SORT:
            heapSort(arr, N);
            break;
        case MERGE_SORT:
            mergeSort(arr, N);
            break;
        case QUICK_SORT:
            quickSort(arr, N);
            break;
        case COUNTING_SORT:
            countingSort(arr, N);
            break;
        case RADIX_SORT:
            radixSort(arr, N);
            break;
        case FLASH_SORT:
            flashSort(arr, N);
            break;
        default:
            break;
    }

    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> elapsed_milliseconds = end - start;
    running_time = elapsed_milliseconds;
}

std::string getAlgorithmName(int algorithmID) {
    switch(algorithmID) {
        case SELECTION_SORT:
            return "Selection sort";
        case INSERTION_SORT:
            return "Insertion sort";
        case BUBBLE_SORT:
            return "Bubble sort";
        case SHAKER_SORT:
            return "Shaker sort";
        case SHELL_SORT:
            return "Shell sort";
        case HEAP_SORT:
            return "Heap sort";
        case MERGE_SORT:
            return "Merge sort";
        case QUICK_SORT:
            return "Quick sort";
        case COUNTING_SORT:
            return "Counting sort";
        case RADIX_SORT:
            return "Radix sort";
        case FLASH_SORT:
            return "Flash sort";
        default:
            return "Unknown sort algorithm";

    }
}

int getAlgorithmID(std::string sort_name) {
    if (sort_name == "selection-sort") {
        return SELECTION_SORT;
    } else if (sort_name == "insertion-sort") {
        return INSERTION_SORT;
    } else if (sort_name == "bubble-sort") {
        return BUBBLE_SORT;
    } else if (sort_name == "shaker-sort") {
        return SHAKER_SORT;
    } else if (sort_name == "shell-sort") {
        return SHELL_SORT;
    } else if (sort_name == "heap-sort") {
        return HEAP_SORT;
    } else if (sort_name == "merge-sort") {
        return MERGE_SORT;
    } else if (sort_name == "quick-sort") {
        return QUICK_SORT;
    } else if (sort_name == "counting-sort") {
        return COUNTING_SORT;
    } else if (sort_name == "radix-sort") {
        return RADIX_SORT;
    } else if (sort_name == "flash-sort") {
        return FLASH_SORT;
    } else {
        return -1;
    }
}