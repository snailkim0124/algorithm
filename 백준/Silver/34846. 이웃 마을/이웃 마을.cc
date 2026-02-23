#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, q;
vector<int> adj[200005];
int subway[200005], ans[200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> q;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	while (q--) {
		int cmd, i;
		cin >> cmd >> i;
		if (cmd == 1) {
			if (!subway[i]) {
				// 이웃하는 마을 더하기
				for (auto j : adj[i]) {
					ans[j]++;
				}
			}
			subway[i]++;
		}
		else if (cmd == 2) {
			cout << ans[i] << "\n";
		}
	}
    
	return 0;
}