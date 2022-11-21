#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;	//��������Ʈ ���·� ����

void printAnswer() {
	int q, t, k;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t >> k;
		if (t == 1) {	//������ ����
			if (tree[k].size() < 2) {
				cout << "no\n";
			}
			else {
				cout << "yes\n";
			}
		}
		else {	//������ ����
			cout << "yes\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, a, b;

	cin >> n;

	tree.assign(n + 1, vector<int>(0));

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	printAnswer();

	return 0;
}