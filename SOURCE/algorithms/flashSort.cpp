#include "flashSort.hpp"

/*
 PROGRAMMING NOTE

be carefull with integer overflow when calculating k
(m - 1) * (x - min_arr) / (max_arr - min_arr) + 0; --> overflow
1ll * (m - 1) * (x - min_arr) / (max_arr - min_arr) + 0; --> correct

be carefull with insertion sort implementation!
 */


void flashSort(int arr[], int n, long long &comparisons) {
	comparisons = 0;
    
    // step 0: find min and max
	int min_arr = arr[0], max_arr = arr[0];
	for (int i = 1; ++comparisons && (i < n); i++) {
		if ( ++comparisons && (arr[i] < min_arr)) {
			min_arr = arr[i];
		}
		else if ( ++comparisons && (arr[i] > max_arr)) {
			max_arr = arr[i];
		}
	}

	// arr[i] == arr[j], for all i, j
	if ( ++comparisons && (max_arr == min_arr))
		return;

	// step 1: determine the size of partitions
	int m = n * 0.45; // 0.45 * n will be wrong
	if (++comparisons && (m <= 2)) m = 2;
	
	int *L = new int[m](); // set all member to 0

	for (int i = 0;  ++comparisons && (i < n); i++) {
		int k = 1ll * (m - 1) * (arr[i] - min_arr) / (max_arr - min_arr);
		L[k]++;
	}

	for (int k = 1; ++comparisons && (k < m); k++) L[k] += L[k - 1];	

	// step 2: partition
	int i = 0;
	int count = 0;
	int k = m - 1;
	while ( ++comparisons && (count < n)) {
		while ( ++comparisons && (i >= L[k])) {
			i++;
			k = 1ll * (m - 1) * (arr[i] - min_arr) / (max_arr - min_arr);
		}

		int flash = arr[i];
		while ( ++comparisons && (i != L[k])) {
			k = 1ll * (m - 1) * (flash - min_arr) / (max_arr - min_arr);
			swap(arr[L[k] - 1], flash);

			L[k]--;
			count++;
		}
	}

	// step 3: insertion sort for each partition
	for (int k = 1; ++comparisons && (k < m); k++) {
		int selected = 0, j = 0;

		for (int i = L[k - 1] + 1; ++comparisons && (i < L[k]); i++) {
			selected = arr[i];
			j = i - 1;
	
			// Find place to insert selected element
			while (++comparisons && (j >= 0) && ++comparisons && (arr[j] > selected)) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = selected;
		}
	}

	delete[] L;
	return;
}

void flashSort(int arr[], int n) {
	// step 0: find min and max
	int min_arr = arr[0], max_arr = arr[0];
	for (int i = 1;i < n; i++) {
		if (arr[i] < min_arr)
			min_arr = arr[i];
		else if (arr[i] > max_arr)
			max_arr = arr[i];
	}

	// if arr[i] == arr[j], for all i, j
	if (max_arr == min_arr)
		return;

	// step 1: determine the size of partitions
	int m = n * 0.45; // 0.45 * n will be wrong
	if (m <= 2) m = 2;

	int *L = new int[m](); // set all member to 0

	for (int i = 0; i < n; i++) {
		int k = 1ll * (m - 1) * (arr[i] - min_arr) / (max_arr - min_arr);
		L[k]++;
	}

	for (int k = 1; k < m; k++) L[k] += L[k - 1];
	
	// step 2: partition
	int i = 0;
	int count = 0;
	int k = m - 1;
	while (count < n) {
		while (i >= L[k]) {
			i++;
			k = 1ll * (m - 1) * (arr[i] - min_arr) / (max_arr - min_arr);
		}

		int flash = arr[i];
		while (i != L[k]) {
			k = 1ll * (m - 1) * (flash - min_arr) / (max_arr - min_arr);

			swap(arr[L[k] - 1], flash);
			L[k]--;
			count++;
		}
	}

	// step 3: insertion sort for each partition
	for (int k = 1; k < m; k++) {
		int selected = 0, j = 0;

		for (int i = L[k - 1] + 1; i < L[k]; i++) {
			selected = arr[i];
			j = i - 1;
	
			// Find place to insert selected element
			while ((j >= 0) && (arr[j] > selected)) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = selected;
		}
	}

	delete[] L;
	return;
}