#include <iostream>
#define fuck cout << __LINE__ << endl

using namespace std;

int gcd(int m, int n) {
	if (!m) return n;
	return gcd(n % m, m);
}

int main() {
	int m, n;
	cin >> m >> n;
	cout << "gcd: " << gcd(m, n) << endl;
	return 0;
}
