#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<string, ll> P;
#define SIZE (int)2e5
int N;
unordered_map<string, ll> arr;

int main() {
	freopen("14171.txt", "r", stdin);
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		string city, state; cin >> city >> state;
		
		if (city.substr(0, 2) != state) {
			string key = city.substr(0, 2) + state;

			if (arr.find(key) == arr.end()) {
				arr.insert(P(key, 0LL));
			}
			arr[key]++;
		}
	}
	
	ll ans = 0;

	for (auto it = arr.begin(); it != arr.end(); it++) {
		string key = it->first;
		string reversedKey = key.substr(2, 2) + key.substr(0, 2);
		if (arr.find(reversedKey) != arr.end()) {
			ans += arr[key] * arr[reversedKey];
		}
	}

	cout << ans/2 << '\n';

	return 0;
}