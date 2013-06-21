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
