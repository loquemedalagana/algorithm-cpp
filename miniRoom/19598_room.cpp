#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int N, tempans, ans; vector<pii> arr;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		arr.push_back({ a, 1 }), arr.push_back({ b, -1 });
	}

	sort(arr.begin(), arr.end());

	for (auto &p : arr) {
		tempans += p.second;
		ans = max(tempans, ans);
	}


	cout << ans << '\n';


	return 0;
}