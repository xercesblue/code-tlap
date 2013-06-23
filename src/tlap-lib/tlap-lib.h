#ifndef TLAP_LIB_H
#define TLAP_LIB_H


class Input {

public:

	Input() {};
	static int read_integer();
	static char read_ch();
};
#ifdef CXX11
#include <chrono>
#include <ctime>
#include <iostream>

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
	std::chrono::milliseconds elapsedMS() {  return duration_cast<milliseconds>(end_time_ - start_time_);
	}
};

#endif

class Sort {
public:
	Sort() {}
	static void insertion(int n[], const int N_SIZE);
	static void quicksort(int n[], const int N_SIZE);
private:
	// Quicksort Helpers
	// Partition Array
	static int qs_partition_(int n[], const int low, const int high);
	// Recursive Helper
	static void quicksort_h_(int n[], const int l, const int h);
};
#ifdef CXX11
#include <list>
#include <memory>
#include <cstddef>
#include <random>

class ArrayGenerator {
	std::list<std::unique_ptr<int[]>> clist;
public:
	ArrayGenerator() {}

	int* gen_random(int n) {
		int* arr = new int[n];

		std::random_device rd;
		std::mt19937 e2(rd());
		std::uniform_int_distribution<> uint_dist(-100, 100);
		for (int i = 0; i < n; i++) {
			arr[i] = uint_dist(e2);
		}
		clist.push_back(std::unique_ptr<int[]>(arr));
		return arr;
	}
};

#endif
void print_arr(int n[], const int N_SIZE);
void swap(int n[], int a_idx, int b_idx);
void swap(int *a, int* b);
void bench_sorts(int n);
#endif //TLAP_LIB_H
