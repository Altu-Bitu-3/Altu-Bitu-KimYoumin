#include <iostream>
#include <string>

using namespace std;

int calTime(string input, int time) {
	int H, M, H1, M1, mon=0;
	H = stoi(input.substr(0, 2));
	M = stoi(input.substr(3, 2));
	H1 = H;
	M1 = M;
	if (time + M >= 60) {
		M1 = time + M - 60;
		H1 = (H1+1) % 24;
	}
	else {
		M1 = time + M;
	}

	if (H == 6 && H1 == 7) {
		mon+= (60 - M) * 5 + M1 * 10;
	}
	else if (H == 18 && H1 == 19) {
		mon+= (60 - M) * 10 + M1 * 5;
	}
	else {
		if (H < 7 || H >= 19) {
			mon += 5 * time;
		}
		else if (7 <= H < 19) {
			mon += 10 * time ;
		}
		
	}

	return mon;
}

int main() {
	int n, time, sum = 0;
	string input;

	cin >> n;
	while (n--) {
		cin >> input >> time;
		sum += calTime(input, time);
	}

	cout << sum;
}