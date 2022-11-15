#include <iostream>
#include <deque>

using namespace std;

string printpwd(deque<char> &left, deque<char> &right) {
	string pwd;
	while (!left.empty()) {
		pwd += left.front();
		left.pop_front();
	}
	while (!right.empty()) {
		pwd += right.front();
		right.pop_front();
	}
	return pwd;
}

string keylog(string input) {
	deque<char> left;
	deque<char> right;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '<') {
			if (!left.empty()) {
				int tmp = left.back();
				left.pop_back();
				right.push_front(tmp);
			}
		}
		else if (input[i] == '>') {
			if (!right.empty()) {
				int tmp = right.front();
				right.pop_front();
				left.push_back(tmp);
			}
		}
		else if (input[i] == '-') {
			if (!left.empty()) {
				left.pop_back();
			}
		}
		else {
			left.push_back(input[i]);
		}
	}
	string pwd = printpwd(left, right);

	return pwd;
}

int main() {
	int n;
	string input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cout << keylog(input)<<"\n";
	}
}