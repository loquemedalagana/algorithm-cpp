#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#define SIZE 100
typedef pair<int, int> pii;
int N, M;
char MAP[SIZE + 10][SIZE + 10];
int check[SIZE + 10][SIZE + 10];
int dr[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dc[] = { 0, 0, -1, 1, -1, 1, 1, -1 };

bool inRange(int r, int c) {
	return r >= 0 && c >= 0 && r < N && c < M && MAP[r][c] == '@' && !check[r][c];
}

void dfs(int r, int c, int cnt) {
	check[r][c] = cnt;
	for (int d = 0; d < 8; d++) {
		int nR = r + dr[d], nC = c + dc[d];
		if (inRange(nR, nC)) dfs(nR, nC, cnt);
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> MAP[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (check[i][j] || MAP[i][j] == '*') continue;
				dfs(i, j, ++cnt);
			}
		}

		cout << cnt << '\n';


		memset(MAP, NULL, sizeof(MAP));
		memset(check, 0, sizeof(check));
	}



	return 0;
}