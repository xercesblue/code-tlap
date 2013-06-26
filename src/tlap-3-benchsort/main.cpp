#include <iostream>
#include <tlap-lib.h>

#include <cstring>

void bench_sorts(int n) {
	ArrayGenerator ag;
	Timer t;
	int* arr = ag.gen_random(n);
	int* cpy = new int[n];

	for (int i = 0; i < n; i++) cpy[i] = arr[i];


	std::cout << "Done generating array" << std::endl;
//	print_arr(arr, n);

	std::cout << "=========" << std::endl;
//	std::cout << "c";
//	print_arr(cpy, n);
	t.start();
	Sort::insertion(arr, n);
	t.stop();
//	print_arr(arr, n);
	std::cout << "Insertion sort on " << n << " elements: " << t.elapsedMS().count() <<"ms" << std::endl;



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




	std::cout << "=========" << std::endl;
	for (int i = 0; i < n; i++) arr[i] = cpy[i];
//	std::cout << "c";
//	print_arr(arr, n);
	t.start();
	Sort::mergesort(arr, n);
	t.stop();
//	print_arr(arr, n);
	std::cout << "Mergesort sort on " << n << " elements: " << t.elapsedMS().count() <<"ms" << std::endl;


//	for (int i = 0; i < n; i++) arr[i] = 0;

//	t.start();
//	Sort::quicksort(arr, n);
//	t.stop();
//	std::cout << "Quicksort Degenerate - Equal Elements: " << t.elapsedMS().count() << "ms" << std::endl;

//	for (int i = 0; i < n; i++) arr[i] = 0;

//	t.start();
//	Sort::quicksort3(arr, n);
//	t.stop();
//	std::cout << "Quicksort Degenerate3 - Equal Elements: " << t.elapsedMS().count() << "ms" << std::endl;




	delete[] cpy;


}


int main(int argc, char* argv[]) {
	int narg = 10;
	if (argc > 1) {
		narg = std::stoi(argv[1]);
	}

	bench_sorts(narg);

	return 0;
}
