#include <bits/stdc++.h>
#include <limits.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
vector<int> adj[55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		adj[i].push_back(i + 1);
	}

	m -= 2;
	int node = n - 1;

	while (m--) {
		adj[node - 1].clear(); // 마지막 노드 제거
		adj[1].push_back(node);
		node--;
	}

	for (int i = 0; i < n - 1; i++) {
		for (auto next : adj[i]) {
			cout << i << " " << next << "\n";
		}
	}
	


	return 0;
}