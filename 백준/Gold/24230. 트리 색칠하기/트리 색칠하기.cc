#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int c[200005];
vector<int> adj[200005];
int cnt;

void dfs(int now, int prev) {

	for (auto next : adj[now]) {
		if (next != prev) {
			if (c[next] != c[now]) cnt++;
			dfs(next, now);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if (c[1] != 0) cnt++;
	dfs(1, 0);
	
	cout << cnt << "\n";

	return 0;
}