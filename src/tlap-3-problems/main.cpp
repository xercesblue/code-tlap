#include <iostream>
#include <cstring>
#include <cmath>
#include <tlap-lib.h>

// Francisco De La Cruz
// dlcs.frank@gmail.com
// July 2, 2013

// See cpp/src/tlap-lib/tlap-lib.(h|cpp) for up to date code.

typedef char* ArrayString;

/**	Note: Expects null-terminated strings.
 * @brief length calculates length of string
 * @param str string to calculate length for
 * @return length of str
 */
int length(const ArrayString str) {
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

double median(int n[], const int N_SIZE) {
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

	Sort::quicksort3(tmp, N_SIZE);

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

	ArrayString str = new char[4];
	ArrayString strnull = nullptr;

	std::strncpy(str, "cool", 4);

	append_ch(str, '!');
	append_ch(strnull, '?');

	std::cout << "Median of: ";	print_arr(arr_unsorted, N_SIZE);
	std::cout << median(arr_unsorted, N_SIZE) << std::endl;
	std::cout << "Appending '!' to 'cool': " << str << std::endl;
	std::cout << "Appending '?' to null string: " << strnull << std::endl;
	std::cout << "Scores: "; print_arr(scores, SCORES_SIZE);
	std::cout << "25 percentile of Scores: " << percentile(scores, SCORES_SIZE, 100) << std::endl;
	delete[] str;
	delete[] strnull;

	return 0;
}
