#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	string name, con;
	set<string, greater<string>> s;

	cin >> n;
	while (n--) {
		cin >> name >> con;
		if (con == "enter") {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}

	for (auto iter = s.begin(); iter != s.end(); iter++) {	//set ¼øÈ¸
		cout << *iter << '\n';
	}
	return 0;
}