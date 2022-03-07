// Used to use binary search to find the path
// of a number in Stern-Brocot Tree using
// matrix method
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

pair<int, int> f(struct matrix m) {
	return make_pair(m.a21 + m.a22, m.a11 + m.a12);
}

int gcd(int m, int n) {
	if (!m) return n;
	return gcd(n % m, m);
}

int main() {
	int m, n;
	cin >> m >> n;

	int d = gcd(m, n);
	m /= d; n /= d;

	struct matrix S = (matrix) {1,0,0,1};
	struct matrix L = (matrix) {1,1,0,1};
	struct matrix R = (matrix) {1,0,1,1};
	
	while (m != f(S).first || n != f(S).second) {
		if (m * f(S).second < n * f(S).first) {
			cout << 'L';
			S = S * L;
		} else {
			cout << 'R';
			S = S * R;
		}
	}
	cout << endl;
	return 0;
}
