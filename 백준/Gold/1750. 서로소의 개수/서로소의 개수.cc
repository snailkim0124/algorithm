#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 10'000'003;
ll n;
ll arr[55];
ll dp[55][100005];

ll go(ll idx, ll g) {
	if (idx == n) return (g == 1);
	if (dp[idx][g] != -1) return dp[idx][g] % mod;

	ll res = 0;
	res = (res + go(idx + 1, gcd(g, arr[idx]))) % mod;
	// 스킵
	res = (res + go(idx + 1, g)) % mod;

	return dp[idx][g] = res % mod;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << "\n";

	return 0;
}

