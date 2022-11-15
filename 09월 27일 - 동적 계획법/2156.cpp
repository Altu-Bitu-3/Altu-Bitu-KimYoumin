#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxScore(int n, vector<int>& arr) {
	vector<int> dp(n + 1, 0);	

	if (n == 1) {
		return arr[1];
	}
	if (n == 2) {
		return arr[1] + arr[2];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];	
	for (int i = 3; i <= n; i++) {
		int maxn = 0;
		for (int j = 1; j <= i-3; j++) {	//i-3번째까지의 dp 최댓값 구하기
			if (maxn < dp[j]) {
				maxn = dp[j];
			}
		}
		dp[i] = max(dp[i - 2], maxn + arr[i - 1]) + arr[i];
	}

	int result = *max_element(dp.begin(), dp.end());
	return result;
}

int main() {
	int n;

	cin >> n;
	vector<int> arr(n + 1, 0);	//계단 함수
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cout << maxScore(n, arr);
}