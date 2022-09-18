#include <iostream>
#include <vector>

using namespace std;

bool isOdd(vector<int>& v1) {	//Ȧ�� ���� ���ĺ��� 2�� �̻� �����ϸ� true
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
		if (v1[j] % 2 == 1) {	//Ȧ�� ���� ���ĺ�
			odd = j + 'A';	//odd�� Ȧ������ ���ĺ� ����
			v1[j] -= 1;
		}
		if (v1[j] >= 2 && v1[j] % 2 == 0) {	//¦�� ���� ���ĺ�
			pal += j + 'A';
			v1[j] -= 2;
		}
	}

	if (odd != 0) {	//Ȧ�� ���� ���ĺ��� ������ ��
		pal += odd;
	}
	for (int i = 0; i < a.size() / 2; i++) {	//��Ī���� ������ֱ�
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