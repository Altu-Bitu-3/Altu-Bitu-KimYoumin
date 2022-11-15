#include <iostream> //c++ 입출력 헤더
#include <vector>   //vector 헤더

using namespace std;    //std 라이브러리 사용

vector<bool> visited(10, false);    //방문 검사(순서 유무 여부) 배열
vector<int> order(10); //주자 순서
/**
 * [힌트] 입력이 그렇게 크지 않네요! 모든 경우의 수를 다 해보면 될 것 같아요.
 *        3아웃이 되면 아웃 카운트와 출루한 주자들이 모두 리셋되고 새로운 이닝이 시작된다는 규칙을 잘 기억해주세요!
 */

 /* 출루한 주자들의 상태 업데이트 */
int hit(vector<bool>& state, int n) {   //state: 출루 상태, n: 현재 주자의 진루 수
    int score = 0;  //현재 점수 초기화
    for (int i = 3; i > 0; i--) {   //3루부터 1루까지 체크
        if (!state[i]) {    //i번째 루에 사람이 없을 때
            continue;
        }
        state[i] = false; //주자 위치 이동
        if (i + n >= 4) { //홈으로 들어오는 경우
            score++;    //점수를 1 늘려줌
        }
        else {  //홈으로 들어오지 않는 경우
            state[i + n] = true;    //i(원래 있던 루)+n(진루 수) 한 위치로 주자를 이동 
        }
    }
    //현재 타자의 위치 설정하기
    if (n == 4) { //타자가 홈런을 날렸을 경우
        return score + 1;   //점수를 1 늘려줌
    }
    //안타를 쳤을 경우
    state[n] = true;    //진루한 위치로 주자를 이동
    return score;   //점수를 리턴
}
/* 타순이 결정됐을 때 경기에서 얻는 점수 구하기 */
int getScore(vector<vector<int>>& inning, int n) {
    int out = 0, score = 0, cur = 0;    //out:현재 아웃 수 , score:현재 점수, cur:현재 이닝 수
    vector<bool> state(4, false);   //출루한 주자를 나타내는 vector
    int i = 1;  //첫번째부터 시작
    while (true)
    {
        if (out == 3) { //3아웃
            cur++; //다음 이닝
            out = 0;    //아웃 횟수를 다시 0으로 바꿔줌
            state = vector<bool>(4, false); //출루한 주자 리셋
            continue;
        }
        if (cur == n) { //모든 이닝 종료
            break;
        }

        int player = order[i++]; //타석으로 나갈 주자 (주자 순서 배열의 i번째 선수)
        i = i % 9 + 1;  //i가 9를 초과할 경우 다시 첫번째 주자부터 시작
        if (inning[cur][player] == 0) { //아웃
            out++;  //아웃 수를 1늘려줌
            continue;
        }
        score += hit(state, inning[cur][player]);   //점수를 더해줌
    }
    return score;   //점수 리턴
}
/* 타순 정하기 */
void game(int cnt, int n, vector<vector<int>>& inning, int& maxScore) {
    if (cnt == 4) { //4번째 타자는 1로 고정
        game(cnt + 1, n, inning, maxScore);
    }
    else if (cnt == 10) { //9명의 타자 순서 정해진 경우
        int score = getScore(inning, n);    //이번 순서의 점수를 계산
        if (score > maxScore) { //점수가 현재 최고 점수보다 높다면
            maxScore = score;   //최고 점수를 갱신
        }
    }
    else {  //타자 순서가 아직 안 정해진 경우
        for (int i = 2; i <= 9; i++) {  //2번부터 9번까지
            if (visited[i]) {   //i번째 선수가 이미 순서가 있다면 
                continue;
            }
            visited[i] = true;  //i번째 선수가 순서가 없다면 방문 여부(순서 유무)를 true로 변경
            order[cnt] = i; //cnt번 선수를 i로 정함
            game(cnt + 1, n, inning, maxScore); //순서를 1 늘려주고 game 함수를 호출
            visited[i] = false; //원래 상태로 돌려놓음
        }
    }
}
int main() {
    int n; cin >> n; //이닝 횟수
    int score, maxScore = 0;
    vector<vector<int>> inning(n, vector<int>(10)); //타자들이 각 이닝에서 얻는 결과
    for (int i = 0; i < n; i++) {   //각 이닝에서 타자들의 결과 입력 받기
        for (int j = 1; j <= 9; j++) {
            cin >> inning[i][j];
        }
    }
    order[4] = 1; //1번 선수는 4번 타자로 고정
    visited[1] = true;  //1번 선수 방문 여부를 true로 변경

    game(1, n, inning, maxScore);   //1번 선수에서 출발
    cout << maxScore;   //최고점수출력
    return 0;
}