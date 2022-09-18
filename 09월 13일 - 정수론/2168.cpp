#include <iostream>

using namespace std;

int gcdRecursion(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcdRecursion(b, a % b);
}


int main() {
	int x, y, mx, my, cnt, tmp;
	cin >> x >> y;

	int g = gcdRecursion(max(x,y), min(x,y));	//최대공약수

	cout << x+y-g;
}