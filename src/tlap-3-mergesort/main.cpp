#include <iostream>
#include <vector>
#include <tlap-lib.h>

// Francisco De La Cruz
// dlcs.frank@gmail.com
// June 24, 2013

// Up to date sorting code in tlap-lib.h/.cpp

void merge_h_(int n[], int low, int half, int high) {

	std::vector<int> tmp(high - low + 1);
	int li = low, ri = half + 1;

	while (li <= half && ri <= high) {

		if (n[li] <= n[ri]) {
			tmp.push_back(n[li++]);
		} else {
			tmp.push_back(n[ri++]);
		}
	}

	// Add remaining elements and copy backs
	while (li <= half) { tmp.push_back(n[li++]);}
	while (ri <= high) { tmp.push_back(n[ri++]);}
	for (int i = low, idx = 0; i <= high; ++i, ++idx) n[i] = tmp.at(idx);
}


void mergesort_h_(int n[], int start, int end) {
	if (start >= end) return;

	// Or start + end / 2 for values of START && END < MAX_INT - 1
	const int half_point = start + (end - start) / 2;
	mergesort_h_(n, start, half_point);
	mergesort_h_(n, half_point + 1, end);


	merge_h_(n, start, half_point, end);

}

// While array_size > 0
//		Split array in half at each iteration
//
// Merge left and right arrays
void mergesort(int n[], const int N_SIZE) {
	if (N_SIZE < 1) return;

	mergesort_h_(n, 0, N_SIZE - 1);
}

int main(int argc, char* argv[]) {
	const int N_SIZE = 10;
	ArrayGenerator ag;
	int* arr = ag.gen_random(N_SIZE);
	//int arr2[] = { 5, 4, 3 ,2};

	print_arr(arr, N_SIZE);

	Timer t;
	t.start();
	mergesort(arr, N_SIZE);
	t.stop();

	std::cout << t.elapsedMS().count() << "ms" << std::endl;
	print_arr(arr, N_SIZE);

	return 0;
}
