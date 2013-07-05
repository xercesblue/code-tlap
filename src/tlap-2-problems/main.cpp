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

int bin2dec() {
	char scanned;
	int number = 0, digit;
	while ((scanned = tlap::Input::read_ch()) != '\n') {
		digit = scanned - '0';
		number = (number * 2) + digit;
	}
	return number;
}

std::string dec2bin() {
	int number = tlap::Input::read_integer();
	std::string res;
	int q;
	while (number > 0) {
		q = number % 2;
		number /= 2;
		res.insert(0, 1, q == 0 ? '0' : '1');
	}
	return res;
}

struct LineStats {
	int words;
	int longest_word;
	int max_vowels;
};

void line_stats(struct LineStats& stats) {
	char scanned;

	enum Char {CONSONANT, VOWEL, PUNCTUATION, WHITESPACE};
	Char char_state = WHITESPACE;
	int max_vowels = 0;
	int longest_word = 0;


	stats.longest_word = 0;
	stats.max_vowels = 0;
	stats.words = 0;

	while ((scanned = tlap::Input::read_ch())) {
		switch (scanned) {
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			char_state = VOWEL;
			max_vowels++;
			break;
		default:
			break;
		}

		if (char_state != VOWEL && ((scanned >= 'a' && scanned <= 'z') || (scanned >= 'A' && scanned <= 'Z'))) {
			char_state = CONSONANT;
		} else if (scanned == ' ' || scanned == '\t' || scanned == '\n') {
			char_state = WHITESPACE;
		} else if (char_state != VOWEL){
			char_state = PUNCTUATION;
		}

		// While VOWEL or CONSONANT, increment word
		if (char_state != WHITESPACE && char_state != PUNCTUATION) {
			longest_word++;
		}

		// At word boundary, increase word count
		// Also calculate longest word seen so far, maximum vowel
		// amound seen words
		if (char_state == WHITESPACE) {
			stats.words++;

			// Calculate Longest Word, Max Vowels
			longest_word = std::max(stats.longest_word, longest_word);
			stats.longest_word = longest_word;

			max_vowels = std::max(stats.max_vowels, max_vowels);
			stats.max_vowels = max_vowels;

			longest_word = 0;
			max_vowels = 0;

			// Exit on end of line
			if (scanned == '\n')
				break;
		}



	}
}

int main(int argc, char* argv[]) {
//	std::cout << "Type 'base,tip' ";
//	int base = Input::read_integer(); int tip = Input::read_integer();
//	int base = 10, tip = 2;
//	std::cout << base << ":"  << tip << std::endl;

//	std::cout << "======" << std::endl;

//	upside_down_triangle(base, tip);

//	std::cout << "======" << std::endl;

//	diamond(base, tip);

//	std::cout << "======" << std::endl;

//	draw_x();

//	std::cout << "ISBN13" << std::endl;
//	ISBN13 isbn13;
//	std::cout << "Is valid? " << isbn13.is_valid_stdin() << std::endl;
//	std::cout << "What Check? " << isbn13.calc_check_from_stdin() << std::endl;

//	int dec = bin2dec();
//	std::cout << "dec: " << dec << std::endl;
//	std::string bin = dec2bin();
//	std::cout << "bin: " << bin << std::endl;

	LineStats stats;
	line_stats(stats);
	std::cout << "Words " << stats.words << std::endl;
	std::cout << "Longest Word: " << stats.longest_word << std::endl;
	std::cout << "Maximum Vowels " << stats.max_vowels << std::endl;
	return 0;
}
