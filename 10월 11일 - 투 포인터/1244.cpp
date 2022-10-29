#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> change(vector<int>& swit, vector<pair<int,int>>&stud, int k, int n) {
    for (int i = 0; i < k; i++) {
        if (stud[i].first == 1) {   //남학생
            for (int j = 1; j < n + 1; j++) {
                if (j % stud[i].second == 0) {
                    swit[j] = (swit[j] == 0) ? 1 : 0;
                }
            }
        }
        if (stud[i].first == 2) {  //여학생
            int left = stud[i].second, right = stud[i].second;
            swit[left] = (swit[left] == 0) ? 1 : 0;
            while (left > 1 && right < n) {
                left -= 1;
                right += 1;
                if (swit[left] == swit[right]) {
                    swit[left] = (swit[left] == 0) ? 1 : 0;
                    swit[right] = (swit[right] == 0) ? 1 : 0;
                }
                else {
                    break;
                }
            }
        }
    }
    return swit;
}

int main() {
    int n, k;

    //입력
    cin >> n;
    vector<int> swit(n+1, 0);
    for (int i = 1; i < n+1; i++) {
        cin >> swit[i];
    }
    cin >> k;   //학생 수
    vector<pair<int, int>> stud(k, {0,0});
    for (int i = 0; i < k; i++) {
        cin >> stud[i].first >> stud[i].second;
    }

    swit = change(swit, stud, k, n);
    
    for (int i = 1; i < n+1; i++) {
        cout << swit[i] << " ";
        if (i % 20 == 0) {
            cout << "\n";
        }
    }
    
    return 0;
}