#include <iostream>
#define fuck cout << __LINE__ << endl

using namespace std;

int exgcd(int m, int n, int &x, int &y) {
	if (!m) {
		x = 0; y = 1;
		return n;
	}
	int d = exgcd(n % m, m, x, y);
	int y1 = x;
	x = y - n / m * x;
	y = y1;
	return d;
}

int main() {
	int m, n;
	cin >> m >> n;
	int x, y;
	int d = exgcd(m, n, x, y);
	cout << "gcd: " << d << endl;
	cout << x << " * " << m << " + " << y << " * " << n << " = " << d << endl;
	return 0;
}
