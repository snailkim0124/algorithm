#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int v, e;
vector<int> adj[3005];
int cnt;
int parent[3005];

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
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	while (e--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		unionParent(a, b);
	}

	// 모든 점이 연결되어 있는지
	bool flag = true;
	for (int i = 1; i <= v; i++) {
		for (int j = i + 1; j <= v; j++) {
			if (findParent(i) != findParent(j)) flag = false;
		}
	}

	// 한붓그리기 공식
	for (int i = 1; i <= v; i++) {
		// cout << adj[i].size() << " ";
		if (adj[i].size() % 2 == 1) cnt++;
	}

	if ((cnt == 2 || cnt == 0) && flag) cout << "YES";
	else cout << "NO";

	return 0;
}