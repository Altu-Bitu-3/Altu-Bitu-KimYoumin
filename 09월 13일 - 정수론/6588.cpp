#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<bool> isPrime(int n) {
	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;

	for (int i = 2; i <= sqrt(n); i++) {
		if (prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
	return prime;
}

void verify(int k, vector<bool>& prime) {
	int pos=0;
	for (int i = 3; i < k/2+1; i++) {
		if (prime[i] && prime[k - i]) {
			cout << k << " = " << i << " + " << k - i<<"\n";
			pos = 1;
			break;
		}
	}
	if (pos == 0) {
		cout << "Goldbach's conjecture is wrong.\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	auto prime = isPrime(1000001);

	while (true) {
		cin >> k;
		if (k == 0) return 0;
		verify(k, prime);
	}
	
}