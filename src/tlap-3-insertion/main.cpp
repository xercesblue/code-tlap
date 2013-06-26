#include <iostream>

// Francisco De La Cruz
// dlcs.frank@gmail.com
// June 24, 2013

// Up to date sorting code in tlap-lib.h/.cpp
void insertion_sort(int n[], const int N_SIZE) {
	int start = 0;
	int end = N_SIZE;
	for (int i = start + 1; i < end; ++i) {
		for (int j = i; j > start && n[j] < n[j-1]; --j) {
			// Found position, swap n[j] and n[j-1]
			int tmp = n[j-1];
			n[j-1] = n[j];
			n[j] = tmp;
		}
	}
}

void print_arr(int n[], const int N_SIZE) {
	for (int i = 0; i < N_SIZE; ++i) {
		std::cout << n[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	const int N_SIZE = 10;
	int n[N_SIZE] = { 9,8,7,6,5,4,3,2,1,0 };
	insertion_sort(n, N_SIZE);
	print_arr(n, N_SIZE);
	int n2[N_SIZE] = {-9,-8, -7, -6, -5, -4, -3, -2, -1, 0};
	insertion_sort(n2, N_SIZE);
	print_arr(n2, N_SIZE);
}
