#include <iostream>
#include <tlap-lib.h>

// Francisco De La Cruz
// dlcs.frank@gmail.com
// July 5, 2013

// See cpp/src/tlap-lib/tlap-lib.(h|cpp) for up to date code.

void insertion_sort(int n[], const int N_SIZE) {
    if (N_SIZE < 1) return;
    int start = 0;
    for (int i = start + 1; i < N_SIZE; ++i) { // forward
        for (int j = i; j > start && n[j - 1] > n[j] ; --j) { // backward
            // Swap
            int tmp = n[j];
            n[j] = n[j - 1];
            n[j - 1] = tmp;
        }
    }
}
// 4 5 5 -1 1 2
// l r.
//   l r
//      l r
// 4 5 -1 5 1 2
//   l  r
// 4 -1 5 5 1 2
// l  r
// -1 4 5 5 1 2
//        l r
// -1 4 5 1 5 2
//      l r
// -1 4 1 5 5 2
//    l r
// -1 1 4 5 5 2
//          l r
// -1 1 4 5 2 5
//        l r
// -1 1 4 2 5 5
//      l r
// -1 1 2 4 5 5

void insertion_sort_fixed(int n[], const int N_SIZE, int fixed) {
    if (N_SIZE < 1) return;
    int start = 0;
    for (int i = start + 1; i < N_SIZE; ++i) {
        int right = i;
        if (n[right] != fixed) {
            for (int left = right - 1; left >= start && (n[left] > n[right] || n[left] == fixed); --left) {
                if (n[left] != fixed) {
                    // swap
                    int tmp = n[left];
                    n[left] = n[right];
                    n[right] = tmp;
                    right = left;
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    const int N_SIZE = 6;
    int n[N_SIZE] = { 2, 5, 5, -1, 1, 2 };
    tlap::print_arr(n, N_SIZE);
    insertion_sort_fixed(n, N_SIZE, 2);
    tlap::print_arr(n, N_SIZE);
	return 0;
}
