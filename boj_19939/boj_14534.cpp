#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int TC;

void solve(string &str, vector<int> &ord) {
	vector<vector<int> > res;
	do {
		res.push_back(ord);
	} while (next_permutation(ord.begin(), ord.end()));

	sort(res.begin(), res.end());

	for (auto &v : res) {
		for (auto &idx : v) {
			printf("%c", str[idx]);
		}
		printf("\n");
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> TC;

	for (int t = 1; t <= TC; t++) {		
		string str; cin >> str;

		vector<int> ord;

		for (int i = 0; i < str.length(); i++) {
			ord.push_back(i);
		}

		printf("Case # %d:\n", t);
		solve(str, ord);

	}

	return 0;
}