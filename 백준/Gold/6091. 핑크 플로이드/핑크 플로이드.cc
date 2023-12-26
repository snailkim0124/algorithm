#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct EDGE {
	int s, e, v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
}EDGE;

int n, m;
int parent[1050];
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순
vector<int> adj[1050];

int findParent(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = findParent(parent[a]);
	}
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) { // 부모 초기화
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int cost;
			cin >> cost;
			pq.push({ i, j, cost });
		}
	}

	int res = 0;

	while (!pq.empty()) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			adj[now.s].push_back(now.e);
			adj[now.e].push_back(now.s);
		}
	}

	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
		cout << adj[i].size() << " ";
		for (auto it : adj[i]) {
			cout << it << " ";
		}
		cout << "\n";
	}
	
	return 0;
}