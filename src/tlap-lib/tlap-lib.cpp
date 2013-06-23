#include <tlap-lib.h>
#include <iostream>

/**
 * @brief Input::read_integer Read comma separated digits from stdin into an int
 * @return integer read
 */
int Input::read_integer() {
	int number = 0;
	char scanned = '0';
	bool neg = false;

	// For n == 3
	// Input-> 1 2 3
	// i1) 0, 0 * 10  + 1 = 1
	// i2) 1, 1 * 10  + 2 = 12
	// i3) 12, 12 * 10 + 3 = 123

	while ((scanned = std::cin.get()) != '\n' && scanned != ',') {
		if (scanned == '-') { neg = true; continue;}
		number *= 10;
		number += scanned - '0';
	}

	return (neg) ? -number : number;
}

/**
 * @brief Input::read_ch Reads a character from stdin
 * @return character read
 */
char Input::read_ch() {
	return std::cin.get();
}

void Sort::insertion(int n[], const int N_SIZE)
{
	int start = 0;
	int end = N_SIZE;
	for (int i = start + 1; i < end; ++i) {
		for (int j = i; j > start && n[j] < n[j-1]; --j) {
			// Found position, swap n[j] and n[j-1]
			swap(&n[j], &n[j-1]);
		}
	}
}

void Sort::quicksort(int n[], const int N_SIZE) {
	Sort::quicksort_h_(n, 0, N_SIZE);
}

// Partition array from start to end on pivot
// Return pivot
// lower_equal_pivot-pivot-greater_pivot
int Sort::qs_partition_(int n[], const int low, const int high) {
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

void Sort::quicksort_h_(int n[], const int l, const int h) {

	if (h - l > 0) {
		int pivot = qs_partition_(n, l, h);
		Sort::quicksort_h_(n, l, pivot-1);
		Sort::quicksort_h_(n, pivot + 1, h);
	}
}


void print_arr(int n[], const int N_SIZE) {
	for (int i = 0; i < N_SIZE; ++i) {
		std::cout << n[i] << " ";
	}
	std::cout << std::endl;
}


void bench_sorts(int n) {
	ArrayGenerator ag;
	Timer t;
	int* arr = ag.gen_random(n);

	std::cout << "Done generating array" << std::endl;
	print_arr(arr, n);

	t.start();
	Sort::insertion(arr, n);
	t.stop();

	std::cout << "=========" << std::endl;
	print_arr(arr, n);
	std::cout << "Insertion sort on " << n << " elements: " << t.elapsedMS().count() <<"ms" << std::endl;

	t.start();
	Sort::quicksort(arr, n);
	t.stop();

	std::cout << "=========" << std::endl;
	print_arr(arr, n);
	std::cout << "Quicksort sort on " << n << " elements: " << t.elapsedMS().count() <<"ms" << std::endl;


}
