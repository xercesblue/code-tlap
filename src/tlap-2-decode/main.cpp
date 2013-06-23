/**
  * Francisco De La Cruz
  * dlcs.frank@gmail.com
  * June 20, 2013
  * Integer String Decoding
  *
  */

#include <iostream>

// n1, n2, n3, n4
// if ni % 27 == 0, ||  ni % 9 == 0
// Scan n character to convert to 10-base integer
// Test Case: 18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10
// Output: "Right? Yes!"


int scanDigit() {
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

int main(int argc, char* argv[]) {
	// While until eol
	char scanned = '\0', outputCh =' ';
	char punctuation[] = {'!', '?', ',','.',' ',';','"','\''};
	int number = 0;

	enum State {UPPERCASE, LOWERCASE, PUNCTUATION};
	State currentState = UPPERCASE;

	while (scanned != '\n') {
		number = scanDigit();
		switch (currentState) {
		case UPPERCASE:
			number %= 27;
			outputCh = number + 'A' - 1; // Input numbers start at 1
			if (number == 0) {
				currentState = LOWERCASE;
				continue;
			}
			break;

		case LOWERCASE:
			number %= 27;
			outputCh = number + 'a' - 1; // Input numbers start at 1
			if (number == 0) {
				currentState = PUNCTUATION;
				continue;
			}
			break;

		case PUNCTUATION:
			number %= 9;
			if (number == 0) {
				currentState = UPPERCASE;
				continue;
			}
			// number > 0 or add a dummy entry in array and remove -1
			outputCh = punctuation[number - 1]; // Input numbers start at 1
		default:
			break;
		}
		std::cout << outputCh;
	}
	std::cout << std::endl;
	return 0;
}
