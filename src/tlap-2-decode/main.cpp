#include <iostream>



// Scan n character to convert to 10-base integer
int scanDigit(int n) {
    int number = 0;
	char scanned = '0';
	bool neg = false;
    // For n == 3
    // Input-> 1 2 3
    // i1) 0, 0 * 10  + 1 = 1 
    // i2) 1, 1 * 10  + 2 = 12
    // i3) 12, 12 * 10 + 3 = 123
    
	do {

        number *= 10;
		number += (scanned - '0');
        std::cin.get(scanned);
		if (scanned == '-') { neg = true;  scanned = '0'; continue;}

        
	} while(scanned != 10);
	return (neg) ? -number : number;
}

int main(int argc, char* argv[]) {
	int n = scanDigit(4);
    std::cout << "Scanning Digit: " << n <<  std::endl;
    return 0;
}
