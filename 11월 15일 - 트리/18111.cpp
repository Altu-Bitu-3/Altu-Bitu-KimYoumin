#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minTime=10e8, minH;

void calMinTime(int n, int m, int b, vector<vector<int>>& ground) {
	for (int i = 0; i <= 256; i++) {
		bool poss = true;
		int tmpb = b;
		int time = 0;
		int h=i;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int tmpH = ground[j][k] - h;
				if (tmpH > 0) {
					time += 2*tmpH;
					tmpb += tmpH;
				}
				else if (tmpH < 0) {
					time += abs(tmpH);
					tmpb -= abs(tmpH);
				}
			}
		}

		if (tmpb < 0) continue;
		if (minTime >= time) {
			minTime = time;
			minH = i;
		}
	}
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, b;
	cin >> n >> m >> b;

	vector<vector<int>> ground(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
		}
	}

	calMinTime(n, m, b, ground);

	cout << minTime << " " << minH;

	return 0;
}