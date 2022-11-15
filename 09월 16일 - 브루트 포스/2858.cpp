#include <iostream>

using namespace std;

int main() {
	int r, b, tile,l,w,tmp;

	cin >> r >> b;

	tile = r + b;
	for (int i = 1; i < tile; i++) {
		if (tile % i == 0 && 2 * (i + tile / i - 2) == r) {
			l = i;
			w = tile / i;
			break;
		}
	}

	if (w > l) {
		tmp = l;
		l = w;
		w = tmp;
	}

	cout << l <<" "<< w;
}