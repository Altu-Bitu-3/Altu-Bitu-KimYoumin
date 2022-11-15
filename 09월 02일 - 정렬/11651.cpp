#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct  coord{
	int x, y;
};

bool cmp(const coord& a, const coord& b) {

	if (a.y!= b.y) {	
		return a.y < b.y;
	}

	return a.x < b.x;
}

int main() {
	int n;

	cin >> n;

	vector<coord> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].x <<" "<< arr[i].y << "\n";
	}

}