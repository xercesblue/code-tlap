#ifndef TLAP_LIB_H
#define TLAP_LIB_H

#include <iostream>
#include <cstddef>
#include <ctime>
#include <list>

#ifdef CXX11
#include <chrono>
#include <memory>
#include <random>
#endif

namespace tlap {
namespace Input {
	int read_integer();
	char read_ch();
}

#ifdef CXX11
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::nanoseconds;
using std::chrono::microseconds;
using std::chrono::duration;

class Timer {
	high_resolution_clock::time_point start_time_, end_time_;
public:
	Timer() {}
	void start() { start_time_ = high_resolution_clock::now(); }
	void stop() {end_time_ = high_resolution_clock::now();}
	std::chrono::milliseconds elapsedMS() {  return duration_cast<milliseconds>(end_time_ - start_time_); }
	std::chrono::microseconds elapsedUS() { return duration_cast<microseconds>(end_time_ - start_time_); }

};

#endif



namespace Sort {
	enum Order {Increment, Decrement};
	void insertion(int n[], const int N_SIZE);
	void quicksort(int n[], const int N_SIZE);
	void quicksort3(int n[], const int N_SIZE);
	void mergesort(int n[], const int N_SIZE);

	bool is_sorted(int n[], const int N_SIZE, const Order ord = Increment);

	// Quicksort Helpers
	// Partition Array
	int qs_partition_(int n[], const int low, const int high);
	int qs_partition3_(int n[], const int low, const int high);
	// Recursive Helper
	void quicksort_h_(int n[], const int l, const int h);
	void quicksort3_(int n[], const int l, const int h);

	// Mergesort Helpers
	void mergesort_h_(int n[], const int l, const int h);
	void mergesort3_h_(int n[], int tmp[], const int l, const int h);
	void merge_h_(int n[], int low, int half, int high);
	void merge2_h_(int n[], int low, int half, int high);
	void merge3_h_(int n[], int tmp[], int low, int half, int high);

	inline void swap(int* a, int* b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	inline void swap(int n[], int a_idx, int b_idx) {
		int tmp = n[a_idx];
		n[a_idx] = n[b_idx];
		n[b_idx] = tmp;
	}

	void bench_sorts(int n);
} //namespace Sort


#ifdef CXX11
class ArrayGenerator {
	std::list<std::unique_ptr<int[]>> clist;
public:
	ArrayGenerator() {}

	int* gen_random(int n) {
		int* arr = new int[n];

		std::random_device rd;
		std::mt19937 e2(rd());
		std::uniform_int_distribution<> uint_dist(0, n);
		for (int i = 0; i < n; i++) {
			arr[i] = uint_dist(e2);
		}

		clist.push_back(std::unique_ptr<int[]>(arr));
		return arr;
	}
};

#endif


void print_arr(int n[], const int N_SIZE, const bool new_line = true);

} // namespace tlap
#endif //TLAP_LIB_H
