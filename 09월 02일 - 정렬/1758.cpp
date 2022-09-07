#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;

int main() {
	int n, tip;
	long long int sum = 0;

	cin >> n;
	arr.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<>());

	for (int i = 0; i < n; i++) {
		tip= arr[i] - i;	//arr[i]-((i+1)-1)
		if (tip > 0) {
			sum += tip;
		}
	}
	cout << sum;
}