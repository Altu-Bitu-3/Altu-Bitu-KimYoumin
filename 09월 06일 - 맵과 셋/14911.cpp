#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int n, k, cnt=0;
	vector<int> v;
	map<int, int> m;

	do {
		cin >> n;
		v.push_back(n);
	} while (getc(stdin) == ' ');
	cin >> k;

	sort(v.begin(), v.end());	//a<=b인 쌍을 출력하기 위해

	for (int i = 0; i < v.size(); i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (v[i] + v[j] == k && !m.count(v[i])) {
				m[v[i]] = v[j];
				cnt += 1;
			}
		}
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << (*iter).first << ' '<< (*iter).second<<"\n";
	}
	cout << cnt;

}