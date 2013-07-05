#include <iostream>
#include <cstring>
#include <cmath>
#include <stdexcept>
#include <tlap-lib.h>

// Francisco De La Cruz
// dlcs.frank@gmail.com
// July 2, 2013

// Many of the examples below are *very* c-like.
// You've been warned :)

// See cpp/src/tlap-lib/tlap-lib.(h|cpp) for up to date code.

typedef char* ArrayString;
typedef const char* ArrayStringC;

/**	Note: Expects null-terminated strings.
 * @brief length calculates length of string
 * @param str string to calculate length for
 * @return length of str
 */
int length(ArrayString str) {
	if (!str) return 0;

	int l = 0;
	while(str[l] != '\0') ++l;
	return l;
}

int length(ArrayStringC str) {
	if (!str) return 0;

	int l = 0;
	while(str[l] != '\0') ++l;
	return l;
}

/**
 * NOTE: This function releases str!
 * @brief append_ch Appends ch to str.
 * @param str string to append to
 * @param ch char to append
 */
void append_ch(ArrayString& str, char ch) {
	int len = length(str);
	ArrayString str2 = new char[len + 2];

	for (int i = 0; i < len; ++i)
		str2[i] = str[i];

	str2[len] = ch;
	str2[len + 1] = '\0';

	if (str)
		delete[] str;

	str = str2;

}

/**
 * @brief substring get substring str[start..start+len)
 * @param str string to operate on
 * @param N_SIZE size of str
 * @param start starting position (>= 1)
 * @param len length of return substring
 * @return substring to return
 */
ArrayString substring(ArrayString str, int start, int mlen) {
	int str_len = length(str);
	if (str_len < 1 || mlen > str_len || start > mlen || start < 1) throw std::invalid_argument("Invalid arguments to substring");

	ArrayString sub = new char[mlen + 1];
	for (int i = start - 1; i < start - 1 + mlen; ++i) {
		sub[i - start + 1] = str[i];
	}
	sub[str_len] = '\0';

	return sub;
}


bool equals_upto(ArrayStringC str, ArrayStringC str2, const int start_pos, const int upto) {
	if (!str || !str2) throw std::invalid_argument("equal_upto:: Empty strings");
	int len1 = length(str), len2 = length(str2);
	if (len1 < len2 || upto > len2) throw std::invalid_argument("equal_upto:: str must be larger than str2. Upto must be <= length(str2)");
	if (start_pos >= len1 || start_pos < 0) throw std::invalid_argument("equal_upto:: start_pos must be within [0, length(str))");

	int i = start_pos;

	while (i - start_pos < upto && i - start_pos < len2 && str[i] == str2[i - start_pos]) i++;

	return i == start_pos + upto;
}

int find(ArrayStringC str, ArrayStringC what, const int start_pos = 0) {

	int w_len = length(what);
	int str_len = length(str);
	int pos = start_pos;
	while (pos < str_len && !equals_upto(str, what, pos, w_len)) pos++;

	return pos < str_len ? pos : -1;
}

void replace(ArrayString str, ArrayStringC this_str, ArrayStringC that_str) {
	int str_len = length(str);
	int this_len = length(this_str);
	int that_len = length(that_str);
	if (this_len != that_len) throw std::invalid_argument("Replace only works on same length strings.");
	int last_match = 0, match = 0;

	while( last_match < str_len ) {
		match = find(str, this_str, last_match);
		if (match != -1) {
			last_match = match + that_len;
			for (int j = 0; j < that_len; ++j) str[j + match] = that_str[j];
		} else {
			last_match += that_len;
		}
	}
}

double median(int n[], const int N_SIZE) {
	using namespace tlap;
	if (!Sort::is_sorted(n, N_SIZE, Sort::Increment)) {
		Sort::mergesort(n, N_SIZE);
	}

	double median = n[N_SIZE / 2];
	if (N_SIZE > 1 && (N_SIZE & 1) == 0) {
		median += n[N_SIZE / 2 - 1];
		median /= 2.0;
	}

	return median;
}

/**
 * Note: This function is intentionally c'ish
 * @brief percentile Calculates percentile by Nearest Rank
 * @param n array
 * @param N_SIZE size of array
 * @param percent percentile to calculate
 * @return percentile calculated percentile
 */
double percentile(int n[], const int N_SIZE, int percent) {
	if (N_SIZE < 1) return 0.0;
	// Create temporary copy
	int* tmp = new int[N_SIZE];
	for (int i = 0; i < N_SIZE; ++i) tmp[i] = n[i];

	tlap::Sort::quicksort3(tmp, N_SIZE);

	if (percent >= 100) {
		int ret = tmp[N_SIZE - 1];
		delete[] tmp;
		return ret;
	}

	double idx_d = (N_SIZE * percent) / 100.0 + 0.5;
	int idx = std::round(idx_d);
	// std::round rounds away from zero
	idx--;

	delete[] tmp;

	return tmp[idx];

}
int main(int argc, char* argv[]) {

//	int arr_sorted[5] = { 5,4,3,2,1};
	const int N_SIZE = 6;
	int arr_unsorted[N_SIZE] = { 1,2,3,5,4,0};

	const int SCORES_SIZE = 11;
	int scores[11] = { 10, 80, 78, 45, 99, 100, 60, 65, 78, 80, 84 };


	ArrayString str = new char[5];
	ArrayString strnull = nullptr, strsub = nullptr;
	ArrayString substr = new char[8];
	ArrayString strrep = new char[8];

	std::strncpy(str, "cool", 5);
	std::strncpy(substr, "abcdefg", 8);
	std::strncpy(strrep, "abcabfg", 8);

	append_ch(str, '!');
	append_ch(strnull, '?');
	strsub = substring(substr, 1, 7);
	replace(strrep, "ab", "XX");

	std::cout << "Median of: ";	tlap::print_arr(arr_unsorted, N_SIZE);
	std::cout << median(arr_unsorted, N_SIZE) << std::endl;
	std::cout << "Appending '!' to 'cool': " << str << std::endl;
	std::cout << "Appending '?' to null string: " << strnull << std::endl;
	std::cout << "Scores: "; tlap::print_arr(scores, SCORES_SIZE);
	std::cout << "25 percentile of Scores: " << percentile(scores, SCORES_SIZE, 100) << std::endl;
	std::cout << "Test substring(1, 7) on 'abcdefg': " << strsub << std::endl;
	std::cout << "Test replace(\"ab\",\"XX\") on 'abcabfg': " << strrep << std::endl;


	delete[] str;
	delete[] strnull;
	delete[] strsub;
	delete[] substr;
	delete[] strrep;

	return 0;
}
