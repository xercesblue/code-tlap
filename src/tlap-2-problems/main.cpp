/**
  * Francisco De La Cruz
  * dlcs.frank@gmail.com
  * June 20, 2013
  * Some problems from the end of chapter 2
  *
  */

#include <iostream>
#include <tlap-lib.h>
#include "isbn-13.h"

#include <cmath>
/** Prints ##########
 *			########
 *           ######
 *            ####
 *			   ##
 *	By printing spaces on left side then hashmarks.
 *  Note: Note spaces are printed for right side
 * @brief upside_down_triangle Prints an upside down triangle.
 * @param base base length of triangle
 * @param tip tip length of triangle
 */
void upside_down_triangle(int base, int tip) {
	int total_rows = std::floor((base - tip)/2.0);
	// base - row = number of prefix spaces
	for (int row = 0; row <= total_rows; ++row) {
		// 0 -> 10
		// 1 -> 8
		// ...
		//4 -> 2
		// 0  > -10
		for (int s = row; s > -base + row * 2; --s) {
			if (s <= 0) std::cout << "X";
			else std::cout << " ";
		}
		//for (int s = 0; s < row; s++) std::cout << " ";
		//for (int i = 0; i < base - row * 2; ++i) std::cout << "#";
		//for (int s = 0; s < row; s++) std::cout << " ";
		std::cout << std::endl;
	}
}
/** Prints a right-side up triangle by inverting the loop upside_down_triangle(...)
 * @brief triangle Prints a right-side up triangle.
 * @param base base length of triangle
 * @param tip tip length of triangle
 */
void triangle(int base, int tip) {
	int total_rows = std::floor((base - tip)/2.0);
	for (int row = total_rows; row >= 0; --row) {
		for (int s = row; s > -base + row * 2; --s) {
			if (s <= 0) std::cout << "X";
			else std::cout << " ";
		}
		std::cout << std::endl;
	}
}

/**
 * @brief diamond Prints a diamond with base base and tip tip.
 * @param base base length of diamond
 * @param tip tip length of diamond
 */
void diamond(int base, int tip) {
	triangle(base, tip);
	upside_down_triangle(base, tip);
}

void step_x_(int i) {
		for (int s = 0; s < i-1; ++s) {
			std::cout << " ";
		}
		for (int h = 1; h <= i; ++h) {
			std::cout << "x";
		}

		for (int s = 0; s < (16) - (4 * i); ++s) {
			std::cout << " ";
		}
		for (int h = 1; h <= i; ++h) {
			std::cout << "x";
		}
		std::cout << std::endl;

}

/**
 * @brief draw_x Draws a fixed 'x' symbold with hash (#) marks.
 */
void draw_x() {
	for (int i = 1; i <= 4; ++i) {
		step_x_(i);
	}

	for (int i = 4; i >= 1; --i) {
		step_x_(i);
	}


}

int main(int argc, char* argv[]) {
//	std::cout << "Type 'base,tip' ";
//	int base = Input::read_integer(); int tip = Input::read_integer();
	int base = 10, tip = 2;
	std::cout << base << ":"  << tip << std::endl;

	std::cout << "======" << std::endl;

	upside_down_triangle(base, tip);

	std::cout << "======" << std::endl;

	diamond(base, tip);

	std::cout << "======" << std::endl;

	draw_x();

	std::cout << "ISBN13" << std::endl;
	ISBN13 isbn13;
	std::cout << "Is valid? " << isbn13.is_valid_stdin() << std::endl;
	std::cout << "What Check? " << isbn13.calc_check_from_stdin() << std::endl;
	return 0;
}
