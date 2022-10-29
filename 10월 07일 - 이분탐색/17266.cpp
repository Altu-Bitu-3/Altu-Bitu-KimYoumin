#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int search(int left, int right, vector<int>& pos) {
    int upper = right;
    while (left <= right) {
        int a = 0;
        int mid = (left + right) / 2;

        if (mid < pos[0]) a = 1;    //첫번째 가로등
        for (int i = 1; i < pos.size(); i++) {
            if (pos[i] - pos[i-1] > mid * 2) { //가로등 사이 거리가 2*높이보다 클 때
                a = 1;
                break;
            }
        }
        if (upper - pos[pos.size() - 1] > mid) a = 1;   //마지막 가로등

        //cout << left << " " << right << " " << mid << "\n";

        if (a == 1) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left; 
}


int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> pos(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> pos[i];
    }

    cout << search(1, n, pos);

    return 0;
}