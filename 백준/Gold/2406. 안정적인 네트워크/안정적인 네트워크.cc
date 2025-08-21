#include <bits/stdc++.h>
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

int n, m;
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq;
int connected[1005][1005];
int parent[1005];
int res;
vector<pii> v;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		int x, y;
		cin >> x >> y;
		connected[x][y] = 1;
		connected[y][x] = 1;
		unionParent(x, y);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int dist;
			cin >> dist;
			if (i == 1) continue;
			if (i < j && !connected[i][j]) pq.push({i, j, dist});
		}
	}

	while (!pq.empty()) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) {
			unionParent(now.s, now.e);
			v.push_back({ now.s, now.e });
			res += now.v;
		}
	}

	if (v.empty()) cout << "0 0" << "\n";
	else {
		cout << res << " " << v.size() << "\n";
		for (auto [x, y] : v) {
			cout << x << " " << y << "\n";
		}
	}


	return 0;
}