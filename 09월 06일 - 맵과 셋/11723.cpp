#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, num;
	string calc;
	vector<bool> arr;

	arr.assign(21, false);	//¼ýÀÚ 1~20

	cin >> n;
	while (n--) {
		cin >> calc;

		if (calc == "add") {
			cin >> num;
			arr[num] = true;
		}
		else if (calc == "remove") {
			cin >> num;
			arr[num] = false;
		}
		else if (calc == "check") {
			cin >> num;
			if (arr[num] == false) {
				cout << 0 <<"\n";
			}else{
				cout << 1<<"\n";
			}
		}
		else if (calc == "toggle") {
			cin >> num;
			if (arr[num] == false) {
				arr[num] = true;
			}
			else {
				arr[num] = false;
			}
		}
		else if (calc == "all") {
			fill(arr.begin(), arr.end(), true);
		}
		else {
			fill(arr.begin(), arr.end(), false);
		}
		
	}

	return 0;
}