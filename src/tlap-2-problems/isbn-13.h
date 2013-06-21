#ifndef ISBN13_H
#define ISBN13_H

// Verify ISBN13 number
// Generate check number for incomplete ISBN13
class ISBN13 {
public:
	ISBN13() {};

	/**
	 * @brief is_valid_stdin checks stdin for a valid isbn13
	 * @return true if number is valid
	 */
	bool is_valid_stdin();
	int checksum_12_stdin();
	int calc_check_from_stdin();
};

#endif //ISBN13_H
