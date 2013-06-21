#include "isbn-13.h"
#include <tlap-lib.h>
#include <iostream>

int ISBN13::checksum_12_stdin() {
	int i = 0;
	char scanned;

	int checksum = 0;
	while (i < 12 && (scanned = std::cin.get()) != '\n') {
		i++;
		checksum += (scanned - '0') * (i & 1 ? 1 : 3);
	}

	return checksum;
}

bool ISBN13::is_valid_stdin() {

	int calc_check = calc_check_from_stdin();
	char scanned = std::cin.get(); // Read char 13
	std::cin.ignore(); // ignore newline

	int read_check = scanned - '0';
	if (read_check < 0 || read_check > 9) return false;

	return calc_check == read_check;
}

int ISBN13::calc_check_from_stdin() {
	int checksum = checksum_12_stdin();

	checksum %= 10;
	int calc_check = (10 - checksum) % 10;

	return calc_check;
}
