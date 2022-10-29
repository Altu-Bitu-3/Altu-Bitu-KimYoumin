#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n,sum=0;

    cin >> n;
    vector<int> time(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    sort(time.begin(), time.end(), greater<>());

    for (int i = 0; i < n; i++) {
        sum += (i+1) * time[i];
    }
    cout << sum;

    return 0;
}