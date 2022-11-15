#include <iostream> //c++ 입출력 헤더
#include <deque>    //deque 헤더
using namespace std;    //std 라이브러리 사용

/**
 * [힌트] 벨트의 회전과 로봇의 이동을 인덱스로 관리해볼까요?
 * 1단계(rotate()): 벨트 회전 + n번째 칸 로봇 내리기
 * 2단계(move())  : 로봇 이동시키기 + n번째 칸 로봇 내리기
 * 3단계(put())   : 1번째 칸에 로봇 올리기
 */

struct info {
    int power;  //벨트의 내구도
    int robot;  //벨트 위 로봇 존재 여부(1: 존재O, 0: 존재X)
};

/** 1단계 */
void rotate(deque<info>& belt, int n) {
    //벨트 회전
    belt.push_front(belt.back());   //벨트를 회전시키기 위해 벨트 덱의 마지막 값을 맨 앞에 삽입함 
    belt.pop_back();    //덱의 마지막 값을 삭제

    //n번째 칸 로봇 내리기
    if (belt[n - 1].robot) {    //n번째 칸에 로봇이 존재한다면
        belt[n - 1].robot--;    //로봇 내리기
    }
}

/** 2단계 */
void move(deque<info>& belt, int n) { //로봇 이동시키기
    /*
    * [로봇 이동을 위한 조건]
    * 1. 현재 칸에 로봇이 존재하고(belt[i].robot)
    * 2. 다음 칸에 로봇이 존재하지 않고(!belt[i+1].robot)
    * 3. 다음 칸의 내구도가 1 이상일 때(belt[i].power)
    *
    * 이때 가장 먼저 올라간 로봇은 가장 뒤에 존재! -> 뒤에서부터 접근하기
    */

    int cur = 2 * n - 1, next;    //cur: 현재 칸, next: 다음 칸
    while (cur >= 0) {   //먼저 올라간 로봇부터 옮기기 시작
        next = (cur + 1) % (2 * n); //next를 (cur+1)로 한다면 2n-1 보다 커질 수 있으므로 (cur+1)을 2*n을 나눈 나머지로 설정
        if (belt[cur].robot && !belt[next].robot && belt[next].power) { //이동하려는 칸에 로봇이 없고 내구도가 1 이상이면 이동
            belt[cur].robot--;  //현재 칸의 로봇 존재 여부를 0으로 바꿔주기
            belt[next].robot++; //다음 칸의 로봇 존재 여부를 1로 바꿔주기
            belt[next].power--; //다음 칸의 내구도를 1 낮춰주기
        }
        cur--;  //현재 칸을 1 낮춰주기
    }

    //n번째 칸 로봇 내리기
    if (belt[n - 1].robot) {    //n-1 번째 칸에 로봇이 존재한다면
        belt[n - 1].robot--;    //로봇을 내리므로 존재 여부를 0으로 바꿔주기
    }
}

/** 3단계 */
void put(deque<info>& belt) {   //1번째 칸에 로봇 올리는 함수
    //1번째 칸에 로봇 올리기
    if (belt[0].power) {    //1번째 칸의 내구도가 0이 아니라면
        belt[0].robot++;    //로봇을 올리고
        belt[0].power--;    //내구도를 1 감소시켜줌
    }
}

int countZero(deque<info>& belt, int n) { //벨트에서 내구도가 0인 칸 세기
    int cnt = 0;    //cnt: 내구도가 0인 칸의 개수, 초기화
    for (int i = 0; i < 2 * n; i++) {   //2n번째 칸까지
        if (belt[i].power == 0) {   //벨트의 내구도가 0이라면
            cnt++;  //cnt를 1 증가시켜줌
        }
    }
    return cnt; //cnt 리턴
}

int main() {
    ios_base::sync_with_stdio(0);   //입출력 속도 향상
    cin.tie(0);

    int n, k; cin >> n >> k;    //n,k 입력받기
    deque<info> belt(2 * n, { 0,0 });    //벨트 초기화
    for (int i = 0; i < 2 * n; i++) {   //벨트 칸 별 내구도 입력받기
        cin >> belt[i].power;
    }

    int stage = 0;    //현재 진행 중인 단계
    do {
        rotate(belt, n);
        move(belt, n);
        put(belt);
        stage++;    //단계를 1 늘려줌
    } while (countZero(belt, n) < k);   //cnt가 k개 이상일때까지 과정 반복

    cout << stage;  //단계 출력

    return 0;
}