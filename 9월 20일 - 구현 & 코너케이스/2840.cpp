#include <iostream>
#include <vector>
#include <map>

using namespace std;

string wheel(int n, int k) {
	int num, cnt = 1;
	char c;
	string output;
	vector<char> arr;
	map<char, bool> m;

	arr.assign(n + 1, '?');
	for (int i = 1; i <= k; i++) {
		cin >> num >> c;
		cnt = (cnt + num) % n;
		if (arr[cnt] != c) {
			if (m.find(c) != m.end() || arr[cnt] != '?') {
				return "!";
			}
		}
		if (arr[cnt] == '?') {
			arr[cnt] = c;
			m[c] = true;
		}
	}

	for (int i = n; i > 0; i--) {
		output += arr[(cnt + i) % n];
	}

	return output;
}

int main() {
	int n, k;
	char c;
	cin >> n >> k;

	cout << wheel(n, k);
}