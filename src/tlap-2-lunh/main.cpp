#include <iostream>


int doubleDigitValue(int digit) {
	int doubledDigit = digit * 2;
	int sum;
	if (doubledDigit >= 10) sum = 1 + doubledDigit % 10;
	else sum = doubledDigit;
	return sum;
}

std::string genLunh(const std::string& str) {
	using std::string;
	string cs_str;

	int cs = 0;

	// Generate Code
	for (string::size_type i = 0; i < str.length(); ++i) {
		char ch = str.at(i);
		cs += (int) ch;
	}
	cs_str = std::to_string(cs);
	// Generate Check Character
	int checksum = 0;
	int digit = 0;
	// Add 1 to account for check bit
	bool evenLen = (cs_str.length() + 1) % 2 == 0;
	for (string::size_type i = 0; i < cs_str.length(); ++i) {
		char ch = cs_str.at(i);
		digit = ch - '0';
		if (evenLen) {
			if (i % 2 == 0) checksum += doubleDigitValue(digit);
			else checksum += digit;
		} else {
			if (i % 2 == 0) checksum += digit;
			else checksum += doubleDigitValue(digit);
		}
	}

	int checkDig = checksum % 10;
	if (checkDig == 0) cs_str.append("0");
	else cs_str.append(std::to_string(10 - checkDig));

	return cs_str;

}

int main(int argc, char* argv[]) {

	char digit;
	int position = 1;
	int evenLengthChecksum = 0;
	int oddLengthChecksum = 0;
	std::string cs = genLunh("cookie");
	std::cout << "Cookie Lunh: " << cs << std::endl;
	std::cout << "Enter a number:";
	digit = std::cin.get();

	while (digit != 10) {
		// 1 2 3
		//   *
		// 1 2 3 4
		// *   *
		if (position % 2 == 0) {
			evenLengthChecksum += digit - '0';
			oddLengthChecksum += doubleDigitValue(digit - '0');
		} else {
			oddLengthChecksum += digit - '0';
			evenLengthChecksum += doubleDigitValue(digit - '0');
		}
		digit = std::cin.get();
		position++;
	}
	int checksum;
	if ((position - 1) % 2 == 0) checksum = evenLengthChecksum;
	else checksum = oddLengthChecksum;
	std::cout << "Checksum: " << checksum << std::endl;
	if (checksum % 10 == 0) {
		std::cout << "Checksum VALID" << std::endl;

	} else {
		std::cout << "Checksum INVALID" << std::endl;
	}

	return 0;
}

