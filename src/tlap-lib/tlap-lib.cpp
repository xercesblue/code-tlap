#include <tlap-lib.h>
#include <iostream>

/**
 * @brief Input::read_integer Read comma separated digits from stdin into an int
 * @return integer read
 */
int Input::read_integer() {
	int number = 0;
	char scanned = '0';
	bool neg = false;

	// For n == 3
	// Input-> 1 2 3
	// i1) 0, 0 * 10  + 1 = 1
	// i2) 1, 1 * 10  + 2 = 12
	// i3) 12, 12 * 10 + 3 = 123

	while ((scanned = std::cin.get()) != '\n' && scanned != ',') {
		if (scanned == '-') { neg = true; continue;}
		number *= 10;
		number += scanned - '0';
	}

	return (neg) ? -number : number;
}

/**
 * @brief Input::read_ch Reads a character from stdin
 * @return character read
 */
char Input::read_ch() {
	return std::cin.get();
}

void Sort::insertion(int n[], const int N_SIZE)
{
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
