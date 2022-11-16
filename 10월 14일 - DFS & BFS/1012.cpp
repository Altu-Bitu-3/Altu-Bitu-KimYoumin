#include <iostream>
#include <vector>

using namespace std;

vector<int> x{1,-1,0,0};
vector<int> y{ 0,0,1,-1 };

// dfs 함수
void dfsRecur(vector<vector<int>>& visited, vector<vector<int>>& v, int a, int b, int m, int n) {    
    visited[a][b] = 1; // 방문 표기
    
    for (int i = 0; i < 4; i++) {
        int a1 = a + x[i];
        int b1 = b + y[i];
        if (a1<0 || b1<0 || a1>=n || b1>=m) //a1,b1이 배추밭의 범위를 초과할 때
            continue;
        if (v[a1][b1] && !visited[a1][b1]) 
            dfsRecur(visited, v, a1, b1, m, n);
    }
}


int main() {
    int m, n, k, a, b, t, cnt;

    // 입력
    cin >> t;

    while (t--) {
        cin >> m >> n >> k;
        cnt = 0;
        
        vector<vector<int>> v(n, vector<int>(m, 0));  //배추 심어진 위치 vector
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            v[b][a] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && v[i][j]) {             
                    //cout <<'cnt:' << cnt << ' ';
                    dfsRecur(visited, v, i, j, m, n);
                    cnt += 1;
                }

            }
        }
        cout << cnt<<"\n";   
    }
    return 0;
}