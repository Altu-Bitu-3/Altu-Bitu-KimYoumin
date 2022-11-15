#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool check(string input, vector<string> &v1) {
	char a;
	int size = input.length();
	for (int i = 0; i < size; i++) {
		if (find(v1.begin(), v1.end(), input) != v1.end())
			return true;
		a = input[0];
		input = input.substr(1, input.length() - 1) + a;
	}
	return false;
}

int main() {
	int n, idx;
	string input;
	vector<string> v1;

	cin >> n;


	for(int i=0; i<n; i++) {
		cin >> input;
		if (i == 0) {
			v1.push_back(input);
		}
		if (!check(input, v1)) v1.push_back(input);
	}

	cout << v1.size();
}