#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> number(1000, 1);    //������ �����ϴ��� ���θ� �����ϴ� vector(1: ����, 0: ����x)

void except() {
    for (int i = 123; i <= 987; i++) {
        string c1;
        c1 = to_string(i);
        if (c1[0] == c1[1] || c1[1] == c1[2] || c1[0] == c1[2]) //���� ���ڰ� ������ ����
            number[i] = 0;
        if (c1[1] - '0' == 0 || c1[2] - '0' == 0)   //0�� ������ ����
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
        if (!number[i]) continue;   //�̹� ���ܵ� ���ڴ� ������ �ʰ� �Ѿ
        for (int p = 0; p < 3; p++) {   //i�� k ��
            for (int j = 0; j < 3; j++) {
                //cout << i << " " << j << "c1[j]:" << c1[j] << " " << k1[p] << " " << "\n";
                if (c1[j] == k1[p]) {
                    if (p == j) //�ڸ����� ������ strike
                        strike += 1;
                    else
                        ball += 1;  //�ڸ��� �ٸ��� ball
                    //cout<<i<<" " << j << "c1[j]:" << c1[j] << " " << k1[p] << " " << "\n";
                }
            }
        }
        if (strike != s || ball != b) { //strike, ball �� �� �ƴ϶�� ����
            number[i] = 0;
        }
        
    }

}

int main() {
    int n,k,s,b,cnt=0;
    // �Է�
    cin >> n;

    except();

    for (int i = 0; i < n; i++) {
        cin >> k >> s >> b;
        check(k, s, b);
    }
    // ���� + ���

    for (int i = 123; i <=987; i++) {
        if (number[i])
            //cout << number[i] << "\n";
            cnt += 1;
            //cout << i << "\n";
    }
    cout << cnt;
    return 0;
}