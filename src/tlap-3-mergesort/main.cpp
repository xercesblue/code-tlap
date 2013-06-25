#include <iostream>
#include <queue>
#include <tlap-lib.h>

void merge_h_(int n[], int low, int half, int high) {
	std::queue<int> b1, b2;

	for (int i = low; i <= half; ++i) b1.push(n[i]);
	for (int i = half + 1; i <= high; ++i) b2.push(n[i]);

	int i = low, eb1 = 0, eb2 = 0;

	while (!b1.empty() && !b2.empty()) {
		eb1 = b1.front(); eb2 = b2.front();
		if (eb1 < eb2) {
			b1.pop();
			n[i++] = eb1;
		} else {
			b2.pop();
			n[i++] = eb2;
		}
	}
	// Add remaining elements
	while (!b1.empty()) { n[i++] = b1.front(); b1.pop(); }
	while (!b2.empty()) { n[i++] = b2.front(); b1.pop(); }
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
	print_arr(n, N_SIZE);
	mergesort_h_(n, 0, N_SIZE - 1);
	std::cout << "=======" << std::endl;
	print_arr(n, N_SIZE);
}




int main(int argc, char* argv[]) {
	const int N_SIZE = 10;
	int n[N_SIZE] = { 9,8,7,6,5,4,3,2,1,0 };
	mergesort(n, N_SIZE);
	return 0;
}
