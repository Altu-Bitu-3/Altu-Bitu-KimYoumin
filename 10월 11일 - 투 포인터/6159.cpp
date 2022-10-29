#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, s, cnt=0;
    //입력
    cin >> n >> s;
    vector<int> cow(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (cow[i] + cow[j] <= s)   //두마리의 소 크기의 합 < 코스튬 크기
                cnt += 1;
        }
    }
   
    cout << cnt;

    return 0;
}