#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct  person {
	int x, y;
};

bool cmp(const person& a, const person& b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
}


int main() {
	int n;
	int k;	//지원자의 수
	int stan;
	int cnt;

	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> k;
		vector<person> arr(k);
		for (int j = 0; j < k; j++) {
			cin >> arr[j].x >> arr[j].y;
		}
		sort(arr.begin(), arr.end(), cmp);
		cnt = 1;
		stan = arr[0].y;
		for (int m = 1; m < k; m++) {
			if (arr[m].y < stan) {
				cnt += 1;
				stan = arr[m].y;
			}
		}
		cout << cnt << "\n";
	}
}