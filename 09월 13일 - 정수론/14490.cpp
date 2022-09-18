#include <iostream>
#include <string>

using namespace std;

int gcd(int n, int m) {
	if (m == 0) {
		return n;
	}
	return gcd(m, n % m);
}

int main() {
	string input;
	int idx, g, n, m;

	cin >> input;

	idx = input.find(":");
	n = stoi(input.substr(0, idx));
	m = stoi(input.substr(idx+1, input.length() - idx-1));


	g = gcd(max(n, m), min(n, m));
	cout << n / g << ":" << m / g;
}