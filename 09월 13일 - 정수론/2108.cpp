#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

bool cmp(const pair<int,int>& a,const pair<int,int>&b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {
	int n;
	double sum=0;
	cin >> n;
	vector<int> v1;
	map<int,int> m;
	map<int, int>::iterator iter=m.begin();

	v1.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v1[i];
		sum += v1[i];
		if (m.count(v1[i])) {
			m[v1[i]] += 1;
		}
		else {
			m[v1[i]] = 0;
		}
		
	}
	sort(v1.begin(), v1.end());

	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	//»ê¼úÆò±Õ
	if (round(sum / n) == -0) {
		cout << 0 << "\n";
	}
	else {
		cout << round(sum / n) << "\n";
	}

	//Áß¾Ó°ª
	cout << v1[n / 2] << "\n";

	//ÃÖºó°ª
	if (n>=2 && v[0].second == v[1].second) {
		cout << v[1].first << "\n";
	}
	else {
		cout << v[0].first << "\n";
	}

	//¹üÀ§
	cout << v1[n - 1] - v1[0] << "\n";
}