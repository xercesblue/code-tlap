#include <iostream>
#include <cstdlib>

#include <tlap-lib.h>



int mode(int n[], const int N_SIZE) {
	tlap::print_arr(n, N_SIZE);

	// Generate Histogram
	int *hist = new int[N_SIZE];
	for (int i = 0; i < N_SIZE; ++i) hist[i] = 0;

	for (int i = 0; i < N_SIZE; ++i) hist[n[i]]++;

	int max_freq = 0;
	for (int i = 0; i < N_SIZE; ++i) {
			if (hist[i] > hist[max_freq]) max_freq = i;
	}

	delete[] hist;
	return max_freq;
}

int main(int argc, char* argv[]) {

	const int N_SIZE = 11;

	int n[N_SIZE] = {1,2,3,4,5,6,6,7,8,9,0};
	int mode_n = mode(n, N_SIZE);
	tlap::print_arr(n, N_SIZE);
	std::cout << "Mode is: " << mode_n << std::endl;
	return 0;
}
