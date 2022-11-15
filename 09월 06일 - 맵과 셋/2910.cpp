#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> order;	//나온 순서를 나타내는 맵

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second) {
		return order[a.first] < order[b.first];
	}
	return a.second > b.second;
}

int main() {
	int n, k, input, ord=0;	
	string car;
	map<int, int> m;	//나온 횟수를 나타내는 맵

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (m.find(input) != m.end()) {
			m[input] += 1;
		}
		else {
			m[input] = 1;
			order[input] = ord;
			ord+=1;
		}
	}

	vector<pair<int,int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	for (auto num : v) {
		for (int j = 0; j < num.second; j++) {
			cout << num.first<< " ";
		}
	}

	return 0;
}