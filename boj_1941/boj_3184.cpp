#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define SIZE 250
int R, C;
int check[SIZE + 10][SIZE + 10];
char MAP[SIZE + 10][SIZE + 10];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << check[i][j] << " ";
		}
		cout << '\n';
	}
}

bool inRange(int r, int c) {
	return r >= 0 && c >= 0 && r < R && c < C;
}

pair<int, int> bfs(pii st, int cnt) {
	queue<pii> q; 
	check[st.first][st.second] = cnt;
	q.push(st);

	int wolfCnt = 0, sheepCnt = 0;

	while (!q.empty()) {
		int r = q.front().first, c = q.front().second; q.pop();

		if (MAP[r][c] == 'o') sheepCnt++;
		else if (MAP[r][c] == 'v') wolfCnt++;

		for (int d = 0; d < 4; d++) {
			int nR = r + dr[d], nC = c + dc[d];
			if (inRange(nR, nC) && MAP[nR][nC] != '#' && !check[nR][nC]) {
				check[nR][nC] = cnt;
				q.push(pii(nR, nC));
			}
		}
	}

	if (sheepCnt > wolfCnt) wolfCnt = 0;
	else sheepCnt = 0;

	return pii(sheepCnt, wolfCnt);
}

int main() {
	freopen("3184.txt", "r", stdin);
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> R >> C; 
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
		}
	}

	int cnt = 0, wolfAns = 0, sheepAns = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (check[i][j] || MAP[i][j] == '#') continue;
			pii survived = bfs(pii(i, j), ++cnt);
			sheepAns += survived.first, wolfAns += survived.second;
		}
	}

	//print();
	cout << sheepAns << " " << wolfAns << '\n';


	return 0;
}