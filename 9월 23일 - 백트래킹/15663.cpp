#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num(SIZE);
vector<bool> check(SIZE);


void backtracking(int cnt, vector<int> arr) {
	int prevnum = 0;	//바로 이전에 선택된 값
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i] && prevnum!=arr[i]) {
			num[cnt] = prevnum = arr[i];
			check[i] = true;
			backtracking(cnt + 1, arr);
			check[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	vector<int> arr(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	backtracking(0, arr);
	return 0;
}