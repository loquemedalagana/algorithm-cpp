#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#define SIZE 50
typedef pair<int, int> pii;
int N, M;
char MAP[SIZE + 10][SIZE + 10];
int check[SIZE + 10][SIZE + 10][4];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

struct Info {
	int r, c, dir, cnt;
	Info(int r, int c, int dir) {
		this->r = r;
		this->c = c;
		this->dir = dir;
	}
	Info () {}
};

bool inRange(int r, int c) {
	return r >= 0 && c >= 0 && r < N && c < M;
}

bool canGo(int r, int c) {
	for (int d = 0; d < 4; d++) {
		int nR = r + dr[d], nC = c + dc[d];
		if (!inRange(nR, nC) || MAP[nR][nC] == '#') continue;
		if (MAP[nR][nC] == 'T') return false;
	}
	return true;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> M >> N;

	pii st;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'P') {
				st = pii(i, j);
				MAP[i][j] = '.';
			}
		}
	}

	queue<Info> q;

	for (int d = 0; d < 4; d++) {
		q.push(Info(st.first, st.second, d));
		check[st.first][st.second][d] = 1;
	}

	int ans = 0;

	while (!q.empty()) {
		int r = q.front().r, c = q.front().c, dir = q.front().dir; q.pop();
		printf("%d, %d, %c\n", r, c, MAP[r][c]);
		if (MAP[r][c] == 'G') {
			ans += 1;
			MAP[r][c] = '.';
		}
		bool ok = canGo(r, c);
		if (!ok) continue;

		for (int d = 0; d < 4; d++) {
			int nR = r + dr[d], nC = c + dc[d];
			if (!inRange(nR, nC) || check[nR][nC][d] || MAP[nR][nC] == '#') continue;
			check[nR][nC][d] = true;
			q.push(Info(nR, nC, d));			
		}
	}

	cout << ans << '\n';


	return 0;
}