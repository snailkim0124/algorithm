#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 1e9 + 7;
int n, m;
ll graph[100005];

ll comb(ll num) {
	if (num < 3) return 0;
	else return (num * (num - 1) * (num - 2)) / 6;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u]++; graph[v]++;
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + comb(graph[i])) % mod;
	}

	cout << ans << "\n";
	

	return 0;
}