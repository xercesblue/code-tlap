#include <iostream>
#include <stdexcept>
#include <cstdlib>


void print_full_square() {
	for (int i = 5; i > 0; i--) {
		for (int j = 5; j > 0; j--)
			std::cout << "#";
		std::cout << std::endl;
	}
}

void print_half_square(int top_dim, char ch) {
	if (top_dim < 0) throw std::invalid_argument("Dimension cannot be Negative");
	for (int i = top_dim; i > 0; i--) {
		for (int j = 0; j < i; j++)
			std::cout << ch;
		std::cout << std::endl;
	}
}

void print_sideways_triangle(int dim) {
	for (int row = 1; row <= dim * 2 - 1; row++) {
		for (int i = 1; i <= dim - abs(dim - row); i++) {
			std::cout << "#";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char* argv[]) {

    try {
        print_half_square(4, '#');
		std::cout << "---" << std::endl;
		print_full_square();
		std::cout << "---" << std::endl;
		print_sideways_triangle(10);
    } catch(std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
