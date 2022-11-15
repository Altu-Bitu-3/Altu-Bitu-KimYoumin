#include <iostream>
#include <cstring>

using namespace std;

void reverse(char a[]) {
	char tmp;
	for (int i = 0; i < strlen(a)/2; i++) {
		tmp = a[i];
		a[i] = a[strlen(a) - i - 1];
		a[strlen(a) - i - 1] = tmp;
	}
}

 void printNum(int cnt, int a[]) {
	int k = 0;
	for (int j = cnt + 2; j >= 0; j--) {
		if (a[j] != 0) {
			k = 1;
		}
		if (k == 1) {
			cout << a[j];
		}
	}
}

int main() {
	char numA[10005], numB[10005] = { 0 };
	int numSum[10010] = { 0 };
	int add=0, num = 0;

	cin >> numA;
	cin >> numB;

	reverse(numA);
	reverse(numB);

	int cnt= (strlen(numA) > strlen(numB)) ? strlen(numA) : strlen(numB);

	for (int i = 0; i < cnt; i++) {
		num = (numA[i] - '0') + (numB[i] - '0') + add;
		if (num < 0) {
			num += '0';
		}
		if (num > 9) {	//올리는 수 결정
			add = 1;
		}
		else {
			add = 0;
		}
		numSum[i] = num % 10;
	}
	if (add == 1) {	//마지막 자리 올림
		numSum[cnt] = 1;
	}

	printNum(cnt, numSum);

	return 0;
}