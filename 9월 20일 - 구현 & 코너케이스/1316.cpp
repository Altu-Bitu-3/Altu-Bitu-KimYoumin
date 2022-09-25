#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string input) {
	vector<bool> v;
	v.assign(26, false);

	for (int i = 1; i < input.length(); i++) {
		if (input[i]!= input[i - 1]) {
			v[input[i-1] - 'a'] = true;
		}
		if (v[input[i] - 'a']) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n, cnt=0;
	string input;

	cin >> n;
	while (n--) {
		cin >> input;
		if (isGroup(input)) {
			cnt += 1;
		}
	}
	cout << cnt;
}