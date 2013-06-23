#include <iostream>
#include <tlap-lib.h>

// Chose pivot
//  Move all elements <= pivot to the left of pivot
//  Move all elements > pivot to the right of pivot
// Recurse on left and right sub arrays

// Partition array from start to end on pivot
// Return pivot
// lower_equal_pivot-pivot-greater_pivot
int qs_partition_(int n[], const int low, const int high) {
	// Test Input: 1 9  7  16  3  2  0  8
	//
	//  .1i 9  7  16  3  2  0  8 s
	//	 1 .9i 7  16  3  2  0  8
	//   1  7 .9i 16  3  2  0  8 s
	//   1  7 .9  16i 3  2  0  8
	//   1  7 .9  16  3i 2  0  8 s
	//   1  7  3 .16  9  2i 0  8 s
	//   1  7  3  2  .9  16 0i 8 s
	//
	//  -- end of for loop
	//
	//  swap (p, after_pivot)
	// 1 7 3  2  0 .16 9  8i  s

	int pivot = high;
	int after_pivot = low;
	for (int i = low; i < high; ++i) {
		if (n[i] < n[pivot]) {
			swap(&n[i], &n[after_pivot]);
			after_pivot++;
		}
	}

	swap(&n[pivot], &n[after_pivot]);

	return pivot;
}

void quicksort_h_(int n[], const int l, const int h) {

	if (h - l > 0) {
		int pivot = qs_partition_(n, l, h);
		quicksort_h_(n, l, pivot-1);
		quicksort_h_(n, pivot+1, h);
	}
}

void quicksort(int n[], const int N_SIZE) {
	quicksort_h_(n, 0, N_SIZE);
}

int main(int argc, char* argv[]) {
	const int N_SIZE = 10;
	int n[N_SIZE] = { 9,8,7,6,5,4,3,2,1,0 };
	quicksort(n, N_SIZE);
	print_arr(n, N_SIZE);
	int n2[N_SIZE] = {-9,-8, -7, -6, -5, -4, -3, -2, -1, 0};
	quicksort(n2, N_SIZE);
	print_arr(n2, N_SIZE);
	int narg = 10;
	if (argc > 1) {
		narg = std::stoi(argv[1]);
	}
	bench_sorts(narg);
}
