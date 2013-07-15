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
	int sum = sum_positive_r(n, size - 1);
	return (n[size - 1] > 0) ? n[size - 1] + sum : sum;
}

// Determines if a string represented by n[0..N_SIZE) has odd parity
// Parity = 1, odd number of 1s
// Parity = 0, even number of 1s (this is also the empty string case)
// return Parity
// Precondition: for all x in n[0..N_SIZE) 0 <= x <= 1
bool is_odd_parity(int n[], const int N_SIZE) {
	if (N_SIZE == 0) return true; // empty string is even parity
	bool parity = false;
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

bool is_odd_parity_r(int n[], int size) {
	if (size == 0) return false;

	bool parity = is_odd_parity_r(n, size - 1);
	int bit = n[size - 1];

	if (bit & 1 && !parity) parity = !parity;
	else if (bit & 0 && !parity) { } // do nothing
	else if (bit & 1 && parity) { parity = !parity; }
	else /* bit & 0 && parity) */ { } // do nothing
	return parity;
}

// Refactored and simplified
bool is_odd_parity_r2(int n[], int size) {
	if (size == 0) return false;

	bool parity = is_odd_parity_r2(n, size - 1);
	int bit = n[size - 1];

	if (bit & 1) parity = !parity;

	return parity;
}

int count_number(int n[], const int N_SIZE, int target) {
    if (N_SIZE == 0) return 0;
    int count = 0;
    for (int i = 0; i < N_SIZE; ++i) {
        if (n[i] == target) count++;
    }
    return count;
}

int count_number_r(int n[], int size, int target) {
    if (size == 0) return 0;
    int count = count_number_r(n, size - 1, target);
    int number = n[size - 1];
    return (number == target) ? count + 1 : count;
}

int main(int argc, char* argv[]) {
	const int N_SIZE = 5;
	int arr[N_SIZE] = {1,2,3,4,-8};
	int ret = sum_positive_r(arr, N_SIZE);
	std::cout << "Sum of array: " << ret << std::endl;

	int par[N_SIZE] = {1, 1, 0, 0, 0};
	std::cout << "Parity of array odd?: "; tlap::print_arr(par, N_SIZE, false);
	std::cout << " is: " << std::boolalpha << is_odd_parity_r(par, N_SIZE) << std::endl;

	int par2[N_SIZE] = {1, 0, 0, 0, 0};
	std::cout << "Parity of array odd?: "; tlap::print_arr(par2, N_SIZE, false);
	std::cout << " is: " << std::boolalpha << is_odd_parity_r(par2, N_SIZE) << std::endl;

    int par3[N_SIZE] = {0, 0, 1, 0, 0};
	std::cout << "Parity of array odd?: "; tlap::print_arr(par3, N_SIZE, false);
	std::cout << " is: " << std::boolalpha << is_odd_parity_r2(par3, N_SIZE) << std::endl;

    std::cout << "Count 0s: "; tlap::print_arr(par3, N_SIZE, false);
    std::cout << " is: " << std::boolalpha << count_number(par3, N_SIZE, 0) << std::endl;

    tlap::BinaryTree<int> bt;
    bt.root_node()->        set_data(7);

    bt.root_node()->set_left(4).set_right(6);
    bt.root_node()->                      set_right(8);



    std::cout << "Is Binary Tree a max-heap?: " << std::boolalpha << bt.is_max_heap() << std::endl;
    std::cout << "Is Binary Tree a bst?: " << std::boolalpha << bt.is_bst() << std::endl;
	return 0;
}
