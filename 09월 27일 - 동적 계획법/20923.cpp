#include <iostream>
#include <deque>

using namespace std;

deque<int> do_d;	//���� ��
deque<int> su_d;	//���� �� 
deque<int> do_g;	//���� �׶��� ��
deque<int> su_g;	//���� �׶��� ��

void bell() {
	if (!do_g.empty() && !su_g.empty() && (do_g.front() + su_g.front()) == 5) {	//�����̰� ���� ħ
		while (!do_g.empty()) {
			su_d.push_back(do_g.back());
			do_g.pop_back();
		}
		while (!su_g.empty()) {
			su_d.push_back(su_g.back());
			su_g.pop_back();
		}
	}
	if ((!do_g.empty() && do_g.front() == 5) || (!su_g.empty() && su_g.front() == 5)) {	//������ ���� ħ
		while (!su_g.empty()) {
			do_d.push_back(su_g.back());
			su_g.pop_back();
		}
		while (!do_g.empty()) {
			do_d.push_back(do_g.back());
			do_g.pop_back();
		}
	}
}

void win() {
	if (do_d.size() < su_d.size()) {
		cout << "su";
	}
	else if (do_d.size() > su_d.size()) {
		cout << "do";
	}
	else {
		cout << "dosu";
	}
}

int main() {
	int n, m, input1, input2;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input1 >> input2;
		do_d.push_front(input1);
		su_d.push_front(input2);
	}

	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {	//������ ��
			do_g.push_front(do_d.front());
			do_d.pop_front();
		}
		else {	//������ ��
			su_g.push_front(su_d.front());
			su_d.pop_front();
		}

		if (do_d.empty()) {
			cout << "su";
			return 0;
		}
		if (su_d.empty()) {
			cout << "do";
			return 0;
		}
		bell();
	}

	win();

	return 0;
}