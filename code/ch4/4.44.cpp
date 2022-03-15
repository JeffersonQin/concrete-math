#include <iostream>
#define fuck cout << __LINE__ << endl

using namespace std;

struct element {
	int numerator;
	int denominator;
};

struct node {
	struct node *next;
	struct node *last;
	struct element val;
};

void print_farey(struct node *start) {
	for (struct node *iter = start; iter != nullptr; iter = iter->next)
		cout << "[" << iter->val.numerator << "/" << iter->val.denominator << "] ";
	cout << endl;
}

bool check(struct node *start) {
	for (struct node *iter = start; iter != nullptr; iter = iter->next) {
		double val = (double) iter->val.numerator / iter->val.denominator;
		if (val >= 0.3155 && val < 0.3165)
			return true;
	}
	return false;
}

int main() {
	int n; cin >> n;

	struct node *start = new node;
	struct node *end = new node;
	start->last = nullptr;
	start->next = end;
	start->val = (element) {0, 1};
	end->last = start;
	end->next = nullptr;
	end->val = (element) {1, 1};

	cout << "F1" << endl;
	print_farey(start);

	for (int i = 2; i <= n; i ++) {
		for (struct node *iter = start; iter != nullptr; iter = iter->next) {
			if (iter->last == nullptr) continue;
			struct node *last = iter->last;
			if (iter->val.denominator + last->val.denominator <= i) {
				struct node *insert = new node;
				insert->val = (element) {
					iter->val.numerator + last->val.numerator,
					iter->val.denominator + last->val.denominator
				};
				insert->last = last;
				insert->next = iter;
				last->next = insert;
				iter->last = insert;
			}
		}
		cout << "F" << i << endl;
		print_farey(start);
	}

	cout << "Check: " << check(start) << endl;
	return 0;
}
