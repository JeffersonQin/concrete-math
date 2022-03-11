// Used to test homework 4.5
#include <iostream>

using namespace std;

struct matrix {
	int a11, a12, a21, a22;

	friend struct matrix operator * (struct matrix &a, struct matrix &b) {
		return (matrix) {
			a.a11 * b.a11 + a.a12 * b.a21,
			a.a11 * b.a12 + a.a12 * b.a22,
			a.a21 * b.a11 + a.a22 * b.a21,
			a.a21 * b.a12 + a.a22 * b.a22
		};
	}
};

void print_m(struct matrix m) {
	cout << "+-------+-------+" << endl;
	cout << "|" << m.a11 << "\t|" << m.a12 << "\t|" << endl;
	cout << "|" << m.a21 << "\t|" << m.a22 << "\t|" << endl;
	cout << "+-------+-------+" << endl;
}

int main() {
	struct matrix L = (matrix) {1,1,0,1};
	struct matrix R = (matrix) {1,0,1,1};

	struct matrix L_0 = L, R_0 = R;

	cout << "L: " << endl;
	for (int i = 0; i <= 10; i ++) {
		print_m(L);
		L = L * L_0;
	}

	cout << "R: " << endl;
	for (int i = 0; i <= 10; i ++) {
		print_m(R);
		R = R * R_0;
	}

	return 0;
}