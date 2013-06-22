#ifndef TLAP_LIB_H
#define TLAP_LIB_H


class Input {

public:

	Input() {};
	static int read_integer();
	static char read_ch();
};


class Sort {
public:
	Sort() {};
	static void insertion(int n[], const int N_SIZE);
};


void print_arr(int n[], const int N_SIZE);

#endif //TLAP_LIB_H
