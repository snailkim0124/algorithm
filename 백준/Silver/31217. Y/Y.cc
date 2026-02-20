#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll fact[100005], invfact[100005];
const ll mod = 1e9 + 7;
int n, m;
vector<int> adj[100005];

// 분할 정복 거듭제곱
ll divide_pow(ll k, ll x) {
	ll res = 1;
	k %= mod;
	while (x > 0) {
		if (x % 2 == 1) res = (res * k) % mod;
		k = (k * k) % mod;
		x /= 2;
	}
	return res;
}

// nCr
ll comb(ll n, ll r) {
	if (r < 0 || r > n) return 0;
	return (((fact[n] * invfact[r]) % mod) * invfact[n - r]) % mod;
}

// 모듈러 역원
ll mod_inv(ll n) {
	return divide_pow(n, mod - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fact[0] = 1;
	invfact[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		invfact[i] = mod_inv(fact[i]);
	}

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + comb(adj[i].size(), 3)) % mod;
	}

	cout << ans << "\n";
	

	return 0;
}