#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#define SIZE 200
typedef pair<int, int> pii;
int N;

struct Info {
	pii p; int power;
	Info(pii p, int power) {
		this->p = p;
		this->power = power;
	}
	Info () {}
};

Info cows[SIZE + 10];
int check[SIZE + 10];

int calc(pii a, pii b) {
	return pow((a.first - b.first), 2) + pow((a.second - b.second), 2);
}

void dfs(int cur, int dist) {
	check[cur] = true;
	
}

int main() {
	freopen("14172.txt", "r", stdin);
	cin.tie(0); ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cows[i].p.first >> cows[i].p.second >> cows[i].power;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int dist = calc(cows[i].p, cows[j].p);
			if (dist <= max(cows[i].power, cows[j].power)) {
				cout << i << " " << j << " " << dist << '\n';
			}
		}
	}


	return 0;
}