#include <tlap-lib.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

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
		Sort::quicksort_h_(n, l, pivot - 1);
		Sort::quicksort_h_(n, pivot + 1, h);
	}
}

void Sort::merge_h_(int n[], int low, int half, int high) {
	std::list<int> b1, b2;

	for (int i = low; i <= half; ++i) b1.push_back(n[i]);
	for (int i = half + 1; i <= high; ++i) b2.push_back(n[i]);

	int i = low, eb1 = 0, eb2 = 0;

	while (!b1.empty() && !b2.empty()) {
		eb1 = b1.front(); eb2 = b2.front();
		if (eb1 < eb2) {
			b1.pop_front();
			n[i++] = eb1;
		} else {
			b2.pop_front();
			n[i++] = eb2;
		}
	}
	// Add remaining elements
	while (!b1.empty()) { n[i++] = b1.front(); b1.pop_front(); }
	while (!b2.empty()) { n[i++] = b2.front(); b2.pop_front(); }
}

void Sort::merge2_h_(int n[], int low, int half, int high) {

		std::vector<int> tmp(high - low + 1);
		int li = low, ri = half + 1;

		while (li <= half && ri <= high) {

			if (n[li] <= n[ri]) {
				tmp.push_back(n[li++]);
			} else {
				tmp.push_back(n[ri++]);
			}
		}

		// Add remaining elements
		while (li <= half) { tmp.push_back(n[li++]);}
		while (ri <= high) { tmp.push_back(n[ri++]);}
		for (int i = low, idx = 0; i <= high; ++i, ++idx) n[i] = tmp.at(idx);
}

void Sort::merge3_h_(int n[], int tmp[], int low, int half, int high) {

		int li = low, ri = half + 1, i = 0;

		while (li <= half && ri <= high) {

			if (n[li] <= n[ri]) {
				tmp[i++] = n[li++];
			} else {
				tmp[i++] = n[ri++];
			}
		}

		// Add remaining elements
		while (li <= half) { tmp[i++] = n[li++];}
		while (ri <= high) { tmp[i++] = n[ri++];}
		for (int f = low, idx = 0; f <= high; ++f, ++idx) n[f] = tmp[idx];
}

void Sort::mergesort_h_(int n[], int start, int end) {
	if (start >= end) return;
	// Or start + end / 2 for values of START && END < MAX_INT - 1
	const int half_point = start + (end - start) / 2;
	mergesort_h_(n, start, half_point);
	mergesort_h_(n, half_point + 1, end);

	merge2_h_(n, start, half_point, end);

}


void Sort::mergesort3_h_(int n[], int tmp[],  int start, int end) {
	if (start >= end) return;
	// Or start + end / 2 for values of START && END < MAX_INT - 1
	const int half_point = start + (end - start) / 2;
	mergesort3_h_(n, tmp, start, half_point);
	mergesort3_h_(n, tmp, half_point + 1, end);

	merge3_h_(n, tmp, start, half_point, end);

}

// While array_size > 0
//		Split array in half at each iteration
//
// Merge left and right arrays
void Sort::mergesort(int n[], const int N_SIZE) {
	if (N_SIZE < 1) return;
//	mergesort_h_(n, 0, N_SIZE - 1);

	int* tmp = new int[N_SIZE];
	mergesort3_h_(n, tmp, 0, N_SIZE - 1);

	delete[] tmp;
}

// Check if an array is sorted
bool Sort::is_sorted(int n[], const int N_SIZE, const Order ord) {
	for (int i = 1; i <= N_SIZE; ++i) {
		if ((ord == Sort::Increment ? n[i-1] > n[i] : n[i] > n[i-1])) {
			return false;
		}
	}
	return true;
}

void print_arr(int n[], const int N_SIZE, const bool new_line) {
	for (int i = 0; i < N_SIZE; ++i) {
		std::cout << n[i] << " ";
	}
	if (new_line)
		std::cout << std::endl;
}

