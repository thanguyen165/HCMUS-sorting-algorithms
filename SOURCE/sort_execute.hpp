#ifndef SORT_EXECUTE_HPP
#define SORT_EXECUTE_HPP

#include <iostream>
#include <chrono>

#include "algorithms/selectionSort.hpp"
#include "algorithms/insertionSort.hpp"
#include "algorithms/bubbleSort.hpp"
#include "algorithms/shakerSort.hpp"
#include "algorithms/shellSort.hpp"
#include "algorithms/heapSort.hpp"
#include "algorithms/mergeSort.hpp"
#include "algorithms/quickSort.hpp"
#include "algorithms/countingSort.hpp"
#include "algorithms/radixSort.hpp"
#include "algorithms/flashSort.hpp"

/*
 sort algorithms' ID: must be natural number, starting from 0, and must be consecutive
 */

#define NUMBER_SORT_ALGORITHM 11
#define SELECTION_SORT 0
#define INSERTION_SORT 1
#define BUBBLE_SORT 2
#define SHAKER_SORT 3
#define SHELL_SORT 4
#define HEAP_SORT 5
#define MERGE_SORT 6
#define QUICK_SORT 7
#define COUNTING_SORT 8
#define RADIX_SORT 9
#define FLASH_SORT 10

void sort(int arr[], int N, int algorithmID, long long &comparisons);
void sort(int arr[], int N, int algorithmID, std::chrono::duration<double, std::milli> &running_time);
std::string getAlgorithmName(int algorithmID);
int getAlgorithmID(std::string sort_name);

#endif // SORT_EXECUTE_HPP