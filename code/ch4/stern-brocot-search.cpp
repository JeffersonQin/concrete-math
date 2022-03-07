// Used to use binary search to find the path
// of a number in Stern-Brocot Tree w/o using
// matrix method
#include <iostream>

using namespace std;

int gcd(int m, int n) {
	if (!m) return n;
	return gcd(n % m, m);
}

int main() {
	int m, n;
	cin >> m >> n;

	int d = gcd(m, n);
	m /= d; n /= d;

	while (m != n) {
		if (m < n) {
			cout << 'L';
			n -= m;
		} else {
			cout << 'R';
			m -= n;
		}
	}
	cout << endl;

	return 0;
}
