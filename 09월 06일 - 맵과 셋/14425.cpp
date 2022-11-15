#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int count(int m, const set<string> &s) {
	int cnt = 0;
	string input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (s.find(input)!=s.end()) {
			cnt += 1;
		}
	}
	return cnt;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	string input;
	set<string> s;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		s.insert(input);
	}

	cout << count(m,s);

	return 0;
}