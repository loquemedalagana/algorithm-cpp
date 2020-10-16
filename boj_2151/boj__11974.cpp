#define _CRT_SECURE_NO_WARNINGS

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#define SIZE 50000
typedef unsigned long long u64;
int N, ans;

int main() {
	freopen("11974.txt", "r", stdin);
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N; 

	vector<int> mod; u64 sum = 0ULL;

	for (int i = 0; i < N; i++) {
		u64 val; cin >> val;
		sum += val;
		mod.push_back(sum % 7);
	}

	for (int r = N - 1; r >= 0; r--) {
		for (int l = 0; l < r; l++) {
			if (mod[r] == mod[l]) {
				ans = max(ans, r - l);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

#endif

#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#define SIZE 50000
typedef unsigned long long u64;
int N, ans;
vector<u64> arr;
vector<u64> prefixSum;

int main() {
	freopen("11974.txt", "r", stdin);
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N; arr.resize(N);
	
	prefixSum = { 0ULL };
	u64 sum = 0ULL;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		prefixSum.push_back(sum);
	}


	//calculate the lagest consecutive array with 2 pointers
	//(prefixSum[right]-prefixSum[left])%7 == 0
	//len = right - left + 1
	int ans = 0, right = N;

#if 01
	while (right >= 1) {
		bool ok = false;
		int left = -1;

		for (int i = 1; i <= right; i++) {
			u64 temp = prefixSum[right] - prefixSum[i - 1];

			if (temp % 7 == 0) {
				left = i;
				ok = true;
				break;
			}
		}

		if (ok && left != -1 && left <= right) {
			ans = max(ans, right - left + 1);
		}
		right--;
	}
#endif


	cout << ans << '\n';

	return 0;
}
#endif