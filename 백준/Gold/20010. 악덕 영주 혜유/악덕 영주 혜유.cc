#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct EDGE {
	int s, e, v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
}EDGE;

int n, k;
int parent[1005];
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq;
int mx, mxidx;
vector<pii> adj[1005];

int findParent(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[b] = a;
	}
}

void dfs(int now, int prev, int dist) {
	if (mx < dist) {
		mx = dist;
		mxidx = now;
	}

	for (auto next : adj[now]) {
		if (next.first != prev) {
			dfs(next.first, now, dist + next.second);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a,b,c });
	}

	int res = 0;
	while (!pq.empty()) {
		auto now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) {
			unionParent(now.s, now.e);
			res += now.v;
			// 역추적
			adj[now.s].push_back({ now.e, now.v });
			adj[now.e].push_back({ now.s, now.v }); 
		}
	}

	// 트리 지름
	dfs(0, -1, 0);
	mx = 0;
	dfs(mxidx, -1, 0);
	
	cout << res << "\n";
	cout << mx << "\n";

	return 0;
}