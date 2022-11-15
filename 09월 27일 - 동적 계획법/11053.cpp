#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxLength(int n, vector<int>& num) {
	vector<int> dp(n + 1, 0);	
	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 0; j <= i - 1; j++) {
			if (num[i] > num[j]) {
				if (dp[j] > max) {
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1;
	}
	int result = *max_element(dp.begin(), dp.end());	//벡터 최대값 구하기
	return result;
}

int main() {
	int n;

	cin >> n;
	vector<int> num(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	cout << maxLength(n, num);
}