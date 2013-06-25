#include <tlap-lib.h>
#include <iostream>
#include <algorithm>

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
	// Help with degenerate case for many repeated elements
	// All repeated elements still degenerates to O(n^2)
	std::random_shuffle(n, n + N_SIZE);
	Sort::quicksort_h_(n, 0, N_SIZE - 1);
}
void Sort::quicksort3(int n[], const int N_SIZE) {
	// No need to care for degenerate case
	Sort::quicksort3_(n, 0, N_SIZE - 1);
}

// 3-Way Quicksort
// Based on Sedgewick/Wayne
// http://algs4.cs.princeton.edu/23quicksort/Quick3way.java.html
void Sort::quicksort3_(int n[], const int low, const int high)
{
	//	if (hi <= lo) return;
	//       int lt = lo, gt = hi;
	//       Comparable v = a[lo];
	//       int i = lo;
	//       while (i <= gt) {
	//           int cmp = a[i].compareTo(v);
	//           if      (cmp < 0) exch(a, lt++, i++);
	//           else if (cmp > 0) exch(a, i, gt--);
	//           else              i++;
	//       }

	if (high - low <= 0) return;

	int pivot = n[low];
	int lk = low, hk = high;
	int i = low;
	int res = 0;
	while (i <= hk) {
		res = n[i] - pivot;

		if (res < 0) { // n[i] < n[pivot]
			swap(&n[lk++], &n[i++]);
		} else if (res > 0) { // n[i] > n[pivot]
			swap(&n[i], &n[hk--]);
		} else {
			i++;
		}

	}



	// Invariant: n[low..lk-1] <= n[lk..hk] < n[hk+1..high]
	Sort::quicksort3_(n, low, lk-1);
	Sort::quicksort3_(n, hk+1, high);

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

	return after_pivot;
}

// Based on Skienna 2way Quicksort
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

#include <cstring>
void bench_sorts(int n) {
	ArrayGenerator ag;
	Timer t;
	int* arr = ag.gen_random(n);
	int* cpy = new int[n];

	for (int i = 0; i < n; i++) cpy[i] = arr[i];


	std::cout << "Done generating array" << std::endl;
//	print_arr(arr, n);

//	std::cout << "=========" << std::endl;
//	std::cout << "c";
//	print_arr(cpy, n);
//	t.start();
//	Sort::insertion(arr, n);
//	t.stop();
//	print_arr(arr, n);
//	std::cout << "Insertion sort on " << n << " elements: " << t.elapsedMS().count() <<"ms" << std::endl;



	std::cout << "=========" << std::endl;
	for (int i = 0; i < n; i++) arr[i] = cpy[i];
//	std::cout << "c";
//	print_arr(arr, n);
	t.start();
	Sort::quicksort(arr, n);
	t.stop();
//	print_arr(arr, n);
	std::cout << "Quicksort sort on " << n << " elements: " << t.elapsedMS().count() <<"ms" << std::endl;


	std::cout << "=========" << std::endl;
	for (int i = 0; i < n; i++) arr[i] = cpy[i];
//	std::cout << "c";
//	print_arr(arr, n);
	t.start();
	Sort::quicksort3(arr, n);
	t.stop();
//	print_arr(arr, n);
	std::cout << "Quicksort3 sort on " << n << " elements: " << t.elapsedMS().count() <<"ms" << std::endl;

	for (int i = 0; i < n; i++) arr[i] = 0;

	t.start();
	Sort::quicksort(arr, n);
	t.stop();
	std::cout << "Quicksort Degenerate - Equal Elements: " << t.elapsedMS().count() << "ms" << std::endl;

	for (int i = 0; i < n; i++) arr[i] = 0;

	t.start();
	Sort::quicksort3(arr, n);
	t.stop();
	std::cout << "Quicksort Degenerate3 - Equal Elements: " << t.elapsedMS().count() << "ms" << std::endl;




	delete[] cpy;


}
