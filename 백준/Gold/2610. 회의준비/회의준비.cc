#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int parent[105];
int dist[105][105];
int timing[105]; // 전달 시간
const int INF = 987654321;
vector<pii> v;
set<int> st;

int findParent(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	// 전달시간이 작은게 부모
	if (timing[a] < timing[b]) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 105 * 105, INF);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
		v.push_back({ a, b });
	}

	// 가중치
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int mx = -1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (dist[i][j] != INF && dist[i][j] > mx) {
				mx = max(mx, dist[i][j]);
			}
		}
		timing[i] = mx;
	}

	for (auto it : v) {
		unionParent(it.first, it.second);
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = findParent(i);
		st.insert(parent[i]);
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << parent[i] << " ";
	//}

	cout << st.size() << "\n";
	for (auto it : st) {
		cout << it << "\n";
	}
	
	return 0;
}