#include <iostream>  
#include <vector>
#include <string>

using namespace std;

pair<int, int> king;
pair<int, int> stone;
int x, y;

void dire(string move) {
	if (move == "R") {
		x = 1;
		y = 0;
	}
	else if (move == "L") {
		x = -1;
		y = 0;
	}
	else if (move == "B") {
		x = 0;
		y = -1;
	}
	else if (move == "T") {
		x = 0;
		y = 1;
	}
	else if (move == "RT") {
		x = 1;
		y = 1;
	}
	else if (move == "LT") {
		x = -1;
		y = 1;
	}
	else if (move == "RB") {
		x = 1;
		y = -1;
	}
	else {
		x = -1;
		y = -1;
	}
}


void playGame(int n, vector<string>& move) {
	int dx, dy;
	for (int i = 0; i < n; i++) {
		//cout<< move[i];
		dire(move[i]);
		dx = x;
		dy = y;
		int nx = king.first + dx;
		int ny = king.second + dy;
		//cout << move[i] << "\n";
		//cout <<"n: " << dx << " " << dy<<"\]n";
		if (nx < 0 || ny <= 0 || nx >= 8 || ny > 8) continue;
		pair<int, int> tmp = make_pair(nx, ny);

		if (tmp == stone) {	//킹이 움직인 자리에 돌이 있다면
			int sx = stone.first + dx;
			int sy = stone.second + dy;
			if (sx < 0 || sy <= 0 || sx >= 8 || sy > 8) {
				continue;
			}
			else {
				stone.first = sx;
				stone.second = sy;
			}
		}
		king.first = nx;
		king.second = ny;
		//cout <<"k1: "<< king.first << "k2; " << king.second << "\n";
		//cout << "s1: " << stone.first << "s2; " << stone.second << "\n";
	}

}


int main() {
	int n, b;
	char a;
	string tp;
	
	//king
	cin >> a >> b;
	king = make_pair(a - 'A', b);

	//stone
	cin >> a >> b;
	stone = make_pair(a - 'A', b);

	cin >> n;
	//cout << n;
	vector<string> move;
	for (int i = 0; i < n; i++) {
		cin >> tp;
		move.push_back(tp);
	}
	playGame(n, move);


	cout << char(king.first+'A') << king.second << "\n";
	cout << char(stone.first + 'A')<< stone.second;
	return 0;
}