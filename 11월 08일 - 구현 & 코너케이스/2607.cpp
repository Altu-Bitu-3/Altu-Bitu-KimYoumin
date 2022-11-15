#include <iostream>
#include <vector>

using namespace std;
vector<int> alphabet(26, 0);

int countSame(int n, vector<string>& word, string str) {
	int same = 0;
	for (int i = 0; i < n - 1; i++) {
		vector<int> walpha(26, 0);
		int diff = 0;
		int diffal = 0;
		for (int j = 0; j < word[i].length(); j++) {
			walpha[word[i][j] - 'A'] += 1;
		}
		for (int k = 0; k < 26; k++) {
			if (alphabet[k] == walpha[k]) continue;
			if (alphabet[k] != walpha[k]) {
				//cout <<k<<" " << walpha[k] << ' ' << alphabet[k] << "\n";
				diff += alphabet[k] > walpha[k] ? (alphabet[k] - walpha[k]) : (walpha[k] - alphabet[k]);
			}
		}
		if (diff <= 1 || (diff==2 && word[i].length()==str.length())) {
			same += 1;
		}
	}
	return same;
}

int main() {
	int n;
	string str,str1;
	cin >> n;

	vector<string> word;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		alphabet[str[i] - 'A'] += 1;
	}

	for (int i = 0; i < n-1; i++) {
		cin >> str1;
		word.push_back(str1);
	}

	cout << countSame(n, word, str);
	return 0;
}