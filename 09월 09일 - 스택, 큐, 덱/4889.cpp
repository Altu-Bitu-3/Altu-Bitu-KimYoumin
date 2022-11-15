#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

void delString(string s, stack<char>& st) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '}' && !st.empty() && st.top()=='{') {
			st.pop();
		}
		else {
			st.push(s[i]);
		}
	}
}

int calString(stack<char>& st) {
	int cal = 0;
	char a, b;

	if (st.size() == 0) {
		return 0;
	}

	while(!st.empty()){
		a = st.top();
		st.pop();
		b = st.top();
		st.pop();

		if (a == '{') {
			b == '{' ? cal += 1: cal += 2;
		}
		else {
			cal += 1;
		}
	}
	
	return cal;
}

int main() {
	string s;
	int i = 1;

	while (true) {
		cin >> s;
		if (s.find("-") != string::npos) {
			break;
		}
		stack<char> st;
		delString(s, st);
		cout<<i<<". "<<calString(st)<<"\n";
		i++;
	}
	return 0;
}