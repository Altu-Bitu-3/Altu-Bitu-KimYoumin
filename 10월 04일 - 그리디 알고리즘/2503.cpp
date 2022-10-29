#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> number(1000, 1);    //조건을 만족하는지 여부를 저장하는 vector(1: 만족, 0: 만족x)

void except() {
    for (int i = 123; i <= 987; i++) {
        string c1;
        c1 = to_string(i);
        if (c1[0] == c1[1] || c1[1] == c1[2] || c1[0] == c1[2]) //같은 숫자가 있으면 제외
            number[i] = 0;
        if (c1[1] - '0' == 0 || c1[2] - '0' == 0)   //0이 있으면 제외
            number[i] = 0;
    }
}

void check(int k, int s, int b) {
    string c1, k1;
    int strike, ball;
    for (int i = 123;i <= 987; i++) {
        strike = 0;
        ball = 0;
        k1 = to_string(k);
        c1 = to_string(i);
        //cout<< "k1 " << k1[0]<<"\n";
        if (!number[i]) continue;   //이미 제외된 숫자는 비교하지 않고 넘어감
        for (int p = 0; p < 3; p++) {   //i와 k 비교
            for (int j = 0; j < 3; j++) {
                //cout << i << " " << j << "c1[j]:" << c1[j] << " " << k1[p] << " " << "\n";
                if (c1[j] == k1[p]) {
                    if (p == j) //자릿수도 같으면 strike
                        strike += 1;
                    else
                        ball += 1;  //자릿수 다르면 ball
                    //cout<<i<<" " << j << "c1[j]:" << c1[j] << " " << k1[p] << " " << "\n";
                }
            }
        }
        if (strike != s || ball != b) { //strike, ball 둘 다 아니라면 제외
            number[i] = 0;
        }
        
    }

}

int main() {
    int n,k,s,b,cnt=0;
    // 입력
    cin >> n;

    except();

    for (int i = 0; i < n; i++) {
        cin >> k >> s >> b;
        check(k, s, b);
    }
    // 연산 + 출력

    for (int i = 123; i <=987; i++) {
        if (number[i])
            //cout << number[i] << "\n";
            cnt += 1;
            //cout << i << "\n";
    }
    cout << cnt;
    return 0;
}