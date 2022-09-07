#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arrA, arrB;


int main() {
	int n;
	int min=0;

	cin >> n;

	arrA.assign(n, 0);
	arrB.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> arrB[i];
	}

	sort(arrA.begin(), arrA.end());
	sort(arrB.begin(), arrB.end(),greater<>());

	for (int i = 0; i < n; i++) {
		min+=arrA[i]*arrB[i];
	}
	cout << min;
}