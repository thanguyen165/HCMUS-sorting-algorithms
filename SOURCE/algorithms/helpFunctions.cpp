#include "helpFunctions.hpp"
#include <time.h>
#include <stdlib.h>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int max(int arr[], int n, long long &comparisons) {
	int max_idx = 0;
	for (int i = 1; ++comparisons && (i < n); i++)
		if (++comparisons && (arr[max_idx] < arr[i]))
			max_idx = i;

	return arr[max_idx];
}

int max(int a, int b, long long &comparisons) {
	comparisons++;
	return (a > b) ? a : b;
}

int max(int arr[], int n) {
	int max_idx = 0;
	for (int i = 1; i < n; i++)
		if (arr[max_idx] < arr[i])
			max_idx = i;

	return arr[max_idx];
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int random(int l, int r) {
    srand((unsigned int)time(nullptr));
	int ran = rand();
	
	return 1ll * ran % (r - l + 1) + l;
}