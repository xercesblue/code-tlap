#include <iostream>
#include <tlap-lib.h>

#include <cstring>


// Francisco De La Cruz
// dlcs.frank@gmail.com
// June 24, 2013

// Up to date sorting code in tlap-lib.h/.cpp
void bench_sorts(int n) {
	tlap::ArrayGenerator ag;
	tlap::Timer t;
	int* arr = ag.gen_random(n);
	int* cpy = new int[n];
	long avg = 0;
	int runs = 50;

	for (int i = 0; i < n; i++) cpy[i] = arr[i];

	std::cout << "Done generating array" << std::endl;

	/* Comment out to speed up test runs.
	std::cout << "=========" << std::endl;
	avg = 0;
	for (int r = 0; r < runs; ++r) {
		for (int i = 0; i < n; i++) arr[i] = cpy[i];
		t.start();
		Sort::insertion(arr, n);
		t.stop();
		avg += t.elapsedMS().count();
	}
	std::cout << "Insertion sort on " << n << " elements: " << avg/runs <<"ms" << std::endl;
	*/
	std::cout << "=========" << std::endl;
	avg = 0;
	for (int r = 0; r < runs; ++r) {
		for (int i = 0; i < n; i++) arr[i] = cpy[i];
		t.start();
		tlap::Sort::quicksort(arr, n);
		t.stop();
		avg += t.elapsedMS().count();
	}
	std::cout << "Quicksort sort on " << n << " elements: " << avg/runs <<"ms" << std::endl;

	std::cout << "=========" << std::endl;
	avg = 0;
	for (int r = 0; r < runs; ++r) {
		for (int i = 0; i < n; i++) arr[i] = cpy[i];
		t.start();
		tlap::Sort::quicksort3(arr, n);
		t.stop();
		avg += t.elapsedMS().count();
	}
	std::cout << "Quicksort3 sort on " << n << " elements: " << avg/runs <<"ms" << std::endl;


	std::cout << "=========" << std::endl;
	avg = 0;
	for (int r = 0; r < runs; ++r) {
		for (int i = 0; i < n; i++) arr[i] = cpy[i];
		t.start();
		tlap::Sort::mergesort(arr, n);
		t.stop();
		avg += t.elapsedMS().count();
	}
	std::cout << "Mergesort sort on " << n << " elements: " << avg/runs <<"ms" << std::endl;

	/* Comment out bad inputs to quicksort to speed up testing.
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

	*/
	delete[] cpy;
}


int main(int argc, char* argv[]) {
	int narg = 5;
	if (argc > 1) {
		narg = std::stoi(argv[1]);
	}

	bench_sorts(narg);

	return 0;
}
