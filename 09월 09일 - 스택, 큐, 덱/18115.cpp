#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

void setCard(int n, deque<int> &d, vector<int> v) {
	for (int i = 1; i <= n; i++) {
		if (v[i - 1] == 1) {
			d.push_front(i);
		}
		else if (v[i - 1] == 2) {
			int a = d.front();
			d.pop_front();
			d.push_front(i);
			d.push_front(a);
		}
		else {
			d.push_back(i);
		}
	}
}

int main() {
	int n, cond;
	deque<int> d;
	vector<int> v;

	cin >> n;

	v.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	reverse(v.begin(), v.end());
	
	setCard(n,d,v);

	while (!d.empty()) {
		cout << d.front()<<" ";
		d.pop_front();
	}

	return 0;
}