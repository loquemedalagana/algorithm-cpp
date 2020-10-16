#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
#define SIZE 1000

struct Node {
	int from, to; ll cost;
	Node(int from, int to, ll cost) {
		this->from = from;
		this->to = to;
		this->cost = cost;
	}
	Node () {}
	bool operator < (const Node &other) const {
		return cost < other.cost;
	}
};

int N, K; vector<int> parent;
vector<Node> graph;
vector<pii> adj[SIZE];
vector<int> check;

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

void print() {
	printf("print tree\n");
	for (int i = 0; i < N; i++) cout << parent[i] << " ";
	cout << '\n';
}

void bfs(int cur) {
	queue<int> q;
	fill(check.begin(), check.end(), -1);

	check[cur] = 0; q.push(cur);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto &next : adj[now]) {
			if (check[next.second] == -1) {
				check[next.second] = check[now] + next.first;
				q.push(next.second);
			}
		}
	}
	
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> K; parent.resize(N); check.resize(N);

	for (int i = 0; i < N; i++) parent[i] = i;

	for (int i = 0; i < K; i++) {
		int from, to; ll cost; cin >> from >> to >> cost;
		graph.push_back(Node(from, to, cost));
	}

	sort(graph.begin(), graph.end());

	ll minCost = 0, maxCost = 0;

	for (int i = 0; i < K; i++) {
		int x = Find(graph[i].from);
		int y = Find(graph[i].to);

		if (x != y) {
			Union(graph[i].from, graph[i].to);
			minCost += graph[i].cost;
			adj[graph[i].from].push_back(pii(graph[i].cost,graph[i].to));
			adj[graph[i].to].push_back(pii(graph[i].cost, graph[i].from));
		}
	}

	cout << minCost << '\n';

	bfs(0);

	int st = 0;

	for (int i = 0; i < N; i++) {
		if (check[i] > check[st]) st = i;
	}

	bfs(st);

	maxCost = *max_element(check.begin(), check.end());

	cout << maxCost << '\n';


	return 0;
}