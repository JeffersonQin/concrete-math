// Used to evaluate whether a / b * b + a % b == a
#include <iostream>

using namespace std;

void test(int a, int b) {
	cout << "|" << a 
		<< "\t|" << b
		<< "\t|" << a % b
		<< "\t|" << a / b
		<< "\t|" << (b * (a / b) + (a % b) == a)
		<< "\t\t|" << endl;
}

int main() {
	cout << "|a\t|b\t|a % b\t|a / b\t|a/b*b + a%b==a\t|" << endl;
	test(1, -2);
	test(-1, 2);
	test(1, 2);
	test(-1, -2);
	test(7, -3);
	test(-7, 3);
	test(7, 3);
	test(-7, -3);
	return 0;
}
