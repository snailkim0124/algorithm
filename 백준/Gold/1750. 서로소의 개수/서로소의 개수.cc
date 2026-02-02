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
ll n, mx;
ll arr[55];
ll dp[55][100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		dp[i][arr[i]] = (dp[i][arr[i]] + 1) % mod; // 자기자신

		for (int g = 1; g <= mx; g++) {
			if (!dp[i - 1][g]) continue;
			dp[i][g] = (dp[i][g] + dp[i - 1][g]) % mod;
			dp[i][gcd(g, arr[i])] = (dp[i][gcd(g, arr[i])] + dp[i - 1][g]) % mod;
		}
	}

	cout << dp[n][1] % mod << "\n";
	
	return 0;
}

