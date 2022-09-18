#include<iostream>
#include<vector>
#include<cmath>
#include<map>

using namespace std;

vector<bool> isPrime(int n) {
	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;

	for (int i = 2; i <= sqrt(n); i++){
		if (prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
	return prime;
}

bool isSang(int tmp) {
	int sum;
	map<int, bool> m;
	while (true) {
		sum = 0;
		while (tmp > 0) {
			sum += pow((tmp % 10), 2);
			tmp = tmp / 10;
		}
		//cout << "sum" << sum << "tmp" << tmp;
		if (m.count(sum)) {
			return false;
		}
		m[sum] = true;
		if (sum == 1) {
			return true;
		}
		tmp = sum;
	}
}

int main() {
	int n;
	cin >> n;

	auto prime = isPrime(n);

	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			if (isSang(i)) cout << i << "\n";
		}
	}

}