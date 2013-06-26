#include <iostream>
#include <list>
#include <tlap-lib.h>

void merge_h_(int n[], int low, int half, int high) {
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


void mergesort_h_(int n[], int start, int end) {
	if (start >= end) return;

	const int half_point = start + (end - start) / 2; // Or start + end / 2 for values of START && END < MAX_INT - 1
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
	const int N_SIZE = 10000;
	ArrayGenerator ag;
	int* arr = ag.gen_random(N_SIZE);
	Timer t;
	t.start();
	mergesort(arr, N_SIZE);
	t.stop();
	std::cout << t.elapsedMS().count() << "ms" << std::endl;
	return 0;
}
