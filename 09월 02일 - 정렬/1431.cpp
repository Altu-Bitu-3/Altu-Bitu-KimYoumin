#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

using namespace std;

vector<string> arr;

bool cmp(const string &a,const string &b) {
	int suma = 0;
	int sumb = 0;

	if (a.size() != b.size()) {	//a와 b의 길이가 다를 때
		return a.size() < b.size();
	}

	for (int i = 0; i < a.size(); i++) {	//a와 b의 자리수의 합 구하기
		if (isdigit(a[i])) {
			suma += a[i]-'0';
		}
		if (isdigit(b[i])) {
			sumb += b[i]-'0';
		}
	}

	if (suma != sumb) {	//a와 b의 자리수의 합이 다를 때
		return suma < sumb;
	}

	return a < b;
}


int main() {
	int n;
	string word;
	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> word;
		arr.push_back(word);
	}

	sort(arr.begin(), arr.end(), cmp);
	

	for (int i = 0; i < n; i++) {
		cout << arr[i]<<"\n";
	}
}