#include <iostream> //c++ 입출력 헤더
#include <vector>   //vetor 헤더

using namespace std;    //std 라이브러리 사용
const int INF = 1e8;    //최댓값 INF 정의(1000000*10보다 커야함)

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

void backtracking(int cnt, int cur_city, int cost) { //백트래킹으로 최소 비용을 구해주는 함수, cnt: 방문한 도시 수, cur_city: 현재 도시, cost: 현재까지의 비용
    if (cost >= ans) {  //현재까지의 비용이 최소 비용보다 크다면 탐색 종료(return)
        return;
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { //출발 도시(0)로 돌아올 수 있는 경우
            ans = min(ans, cost + matrix[cur_city][0]); //최소 비용을 현재 최소 비용과 (현재까지의 비용+현재도시에서 출발도시로 돌아가는 비용) 중 더 작은 값으로 경신시켜줌
        }
        return; //모든 도시를 순회했으므로 종료(return)
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true;  //i 도시의 방문 여부를 true로 변경해줌
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);   //방문 도시 수를 1 늘려주고, 현재 도시를 i로 바꿔주고, 현재까지의 비용에 이전 도시에서 i도시로 이동하는 비용을 더해서 backtracking 함수를 호출해줌 
            visited[i] = false; //원래 상태로 돌려놓음
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {

    //입력
    cin >> n;   //도시의 수 입력 받기
    visited.assign(n, false);   //방문 검사 배열을 false로 초기화
    matrix.assign(n, vector<int>(n, 0));    //n*n 비용 행렬을 0으로 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];    //비용행렬에 도시 i에서 j로 가기 위한 비용 입력 받기
        }
    }

    //연산
    visited[0] = true;  //0번 도시를 출발 도시로 정해 방문 여부 true로 바꿔주기
    backtracking(1, 0, 0);  //0번 도시에서 출발했으므로 cnt: 1, cur_city : 0, cost : 0

    //출력
    cout << ans;    //최종 최소 비용 출력
    return 0;
}