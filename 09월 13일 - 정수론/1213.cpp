#include <iostream>
#include <vector>

using namespace std;

bool isOdd(vector<int>& v1) {	//홀수 개인 알파벳이 2개 이상 존재하면 true
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (v1[i] % 2 == 1) {
			cnt += 1;
		}
	}
	return	cnt > 1 ? true : false;
}

string changePal(vector<int>&v1, string pal, string a, char odd) {
	int j = 0;
	while (true) {
		if (v1[j] == 0) { j += 1; }
		if (j > 25) {
			break;
		}
		if (v1[j] % 2 == 1) {	//홀수 개인 알파벳
			odd = j + 'A';	//odd에 홀수개인 알파벳 저장
			v1[j] -= 1;
		}
		if (v1[j] >= 2 && v1[j] % 2 == 0) {	//짝수 개인 알파벳
			pal += j + 'A';
			v1[j] -= 2;
		}
	}

	if (odd != 0) {	//홀수 개인 알파벳이 존재할 때
		pal += odd;
	}
	for (int i = 0; i < a.size() / 2; i++) {	//대칭으로 만들어주기
		pal += pal[a.size() / 2 - i - 1];
	}
	return pal;
}


int main() {
	vector<int> v1;
	string a, pal;
	char odd=0;
	cin >> a;

	v1.assign(26, 0);

	for (int i = 0; i < a.length(); i++) {
		v1[a[i]-'A'] += 1;
	}

	if (isOdd(v1)) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	
	cout << changePal(v1,pal,a,odd);

}