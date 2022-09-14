#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n,k;
	queue<int> q;

	cin >> n>>k;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int j = 1;
	cout << "<";
	while (!q.empty()) {
		if (j % k == 0) {
			cout << q.front();
			if (q.size() != 1) {
				cout << ", ";
			}
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
		j++;
	}
	cout << ">";

	return 0;
}