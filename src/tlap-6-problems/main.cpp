#include <iostream>
#include <tlap-lib.h>
// Francisco De La Cruz
// dlcs.frank@gmail.com
// July 4, 2013

// See cpp/src/tlap-lib/tlap-lib.(h|cpp) for up to date code.

// Sums positive integer in array n
int sum_positive(int n[], const int N_SIZE) {
	int sum = 0;
	for (int i = 0; i < N_SIZE; ++i) {
		if (n[i] > 0) { sum += n[i]; }
	}
	return sum;
}

int sum_positive_r(int n[], int size) {
	if (size == 0) return 0;
	int sum = sum_positive(n, size - 1);
	return (n[size - 1] > 0) ? n[size - 1] + sum : sum;
}

// Determines the parity of the string represented by n[0..N_SIZE)
// Parity = 1, odd number of 1s
// Parity = 0, even number of 1s
// return Parity
bool array_parity(int n[], const int N_SIZE) {
	if (N_SIZE == 0) return true; // empty string is even parity
	bool parity = true;
	for (int i = 0; i < N_SIZE; ++i) {
		int bit = n[i];
		if (bit & 1 && !parity) parity = !parity;
		else if (bit & 0 && !parity) { } // do nothing
		else if (bit & 1 && parity) { parity = !parity; }
		else /* bit & 0 && parity) */ { } // do nothing
	}
	// If string '0' even parity
	//	appending '1' and even parity, set to odd
	//	appending '0' and even parity, set to even
	//  appending '1' and odd parity, set even
	//  appending '0' and odd parity, set odd
	return parity;
}

int main(int argc, char* argv[]) {
	const int N_SIZE = 5;
	int arr[N_SIZE] = {1,2,3,4,-8};
	int ret = sum_positive_r(arr, N_SIZE);
	std::cout << "Sum of array: " << ret << std::endl;

	int par[N_SIZE] = {1,1,0,1,1};
	std::cout << "Parity of array: "; print_arr(par, N_SIZE);
	std::cout << " is:" << array_parity(par, N_SIZE);
	return 0;
}
