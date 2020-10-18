#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#define SIZE 20
typedef pair<int, int> pii;
int N, M, K;
vector<int> MAP[SIZE + 10][SIZE + 10];
int smell[SIZE + 10][SIZE + 10];
int smell2[SIZE + 10][SIZE + 10];
int remain[SIZE + 10][SIZE + 10]; //time
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool isDead[SIZE*SIZE + 10]; //isdead
int sharkCnt[SIZE*SIZE + 10]; //moved
int sharkDir[SIZE*SIZE + 10]; //current direction
pii sharkPos[SIZE*SIZE + 10]; //current position
int priority[SIZE*SIZE + 10][4][4]; //priority

bool inRange(int r, int c) {
	return r >= 0 && c >= 0 && r < N && c < N;
}

void print() {
	printf("current shark pos\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(MAP[i][j].size()) printf("(%d,%d) ", MAP[i][j].size(),MAP[i][j][0]);
			else printf("(0, 0) ");
		}
		printf("\n");
	}
	printf("smell status\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", smell[i][j]);
		}
		printf("\n");
	}
	printf("remained time\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", remain[i][j]);
		}
		printf("\n");
	}
}

int removeSmell() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (remain[i][j]) {
				remain[i][j] -= 1;
				if (remain[i][j] == 0) {
					smell[i][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (smell2[i][j]) {
				cnt++;
				if (MAP[i][j].size() > 1) {
					while (true) {
						isDead[MAP[i][j].back()] = true;
						MAP[i][j].pop_back();
						if (MAP[i][j].size() == 1) {
							smell2[i][j] = MAP[i][j].back();
							break;
						}
					}
				}


				smell[i][j] = smell2[i][j];
				smell2[i][j] = 0;
				remain[i][j] = K;
			}
		}
	}
	return cnt;
}

void solve() {
	int ans = -1;

	for (int time = 1; time <= 1000; time++) {
		//printf("time lapsed %d\n", time);
		for (int i = 1; i <= M; i++) {
			if (isDead[i]) {
				//printf("shark %d is dead\n", i);
				continue;
			}

			int &r = sharkPos[i].first, &c = sharkPos[i].second, &dir = sharkDir[i];
			pii newpos = pii(-1, -1); int newDir = -1;

			//아무 냄새가 없는 칸 찾기
			for (int d = 0; d < 4; d++) {
				int nd = priority[i][dir][d];
				int nR = r + dr[nd], nC = c + dc[nd];

				if (!inRange(nR, nC)) continue;

				if (!smell[nR][nC]) {
					newpos = pii(nR, nC);
					newDir = nd;
					break;
				}
			}

			//printf("shark %d will move (%d,%d) => (%d,%d), %d -> %d\n", r, c, newpos.first, newpos.second, dir, newDir);

			//자신의 냄새가 있는 칸 찾기
			if (newpos == pii(-1, -1)) {
				for (int d = 0; d < 4; d++) {
					int nd = priority[i][dir][d];
					int nR = r + dr[nd], nC = c + dc[nd];

					if (!inRange(nR, nC)) continue;

					if (smell[nR][nC] == i) {
						newpos = pii(nR, nC);
						newDir = nd;
						break;
					}
				}
			}

			//이동하기
			if (newpos != pii(-1, -1)) {
				MAP[r][c].pop_back();
				r = newpos.first, c = newpos.second, dir = newDir;

				smell2[r][c] = i;
				MAP[r][c].push_back(i);
			}

		}

		//이동을 마치고 칸에 상어가 여러개 있으면 상어 죽이기

		//냄새 제거
		int survivedShark = removeSmell();
		//print();
		//printf("%d\n", survivedShark);
		if (survivedShark == 1) {
			ans = time;
			break;
		}
	}

	cout << ans << '\n';
}

int main() {
	freopen("19237.txt", "r", stdin);
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int val; cin >> val;
			smell[i][j] = val;
			if (val) {
				MAP[i][j].push_back(val);
				remain[i][j] = K;
				sharkPos[val] = pii(i, j);
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> sharkDir[i];
		sharkDir[i] -= 1;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> priority[i][j][k];
				priority[i][j][k] -= 1;
			}
		}
	}

	//print();

	solve();

	return 0;
}