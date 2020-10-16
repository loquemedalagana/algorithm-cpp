#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 15000
int arr[SIZE + 10], N, M;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	int p = 0, q = N - 1, ans = 0;

	for (int i = 0; i < N-1; i++) {
		int j = N - 1;
		while (i < j) {
			if (arr[i] + arr[j] == M) ans++;
			j--;
		}
	}

	cout << ans << '\n';


	return 0;
}