#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int n, test;
	string name, cate;

	cin >> n;
	while (n--) {
		cin >> test;
		map<string, int> m;	//<종류, 개수> 맵
		int cnt = 1;
		for (int i = 0; i < test; i++) {
			cin >> name >> cate;

			if(m.find(cate) != m.end()) {
				m[cate] += 1;
			}
			else {
				m[cate] = 1;
			}
		}

		for (auto iter = m.begin(); iter != m.end(); iter++) {	//set 순회
			cnt = ((*iter).second + 1) * cnt;
		}
		cout << cnt-1 <<"\n";	//-1: 의상을 아무것도 입은 않은 경우
	}

}