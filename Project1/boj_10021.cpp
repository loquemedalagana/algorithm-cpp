#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Node {
	int from, to; ll cost;
	Node(int from, int to, ll cost) {
		this->from = from;
		this->to = to;
		this->cost = cost;
	}
	Node() {}
	bool operator < (const Node &other) const {
		return cost < other.cost;
	}
};

int N, C; vector<int> parent;
vector<Node> mst;
vector<pii> pos;

int Find(int x) {
	if (x == parent[x]) return x;
	else {
		parent[x] = Find(parent[x]);
		return parent[x];
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	freopen("10021.txt", "r", stdin);
	cin >> N >> C; parent.resize(N); 

	for (int i = 0; i < N; i++) parent[i] = i;

	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		pos.push_back(pii(x, y));
	}

	set<int> vertexes;

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			ll cost = pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2);
			if (cost >= C) {
				mst.push_back(Node(i, j, cost));
				vertexes.insert(i);
				vertexes.insert(j);
			}
		}
	}

	ll minCost = -1;

	//cout << vertexes.size() << " " << N << '\n';

	if (vertexes.size() < N) {
		cout << -1 << '\n';
		return 0;
	}

	sort(mst.begin(), mst.end());

	for (auto &v : mst) {
		int x = Find(v.from);
		int y = Find(v.to);

		if (x != y) {
			if (minCost == -1) minCost = 0;
			Union(v.from, v.to);
			minCost += v.cost;
		}
	}

	cout << minCost << '\n';

	return 0;
}