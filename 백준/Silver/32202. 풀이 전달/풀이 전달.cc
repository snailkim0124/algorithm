#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
const ll mod = 1e9 + 7;
ll dp[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	dp[1] = 3;
	dp[2] = 8;

	for (int i = 3; i <= n; i++) {
		ll tmp = (2 * dp[i - 1] + 2 * dp[i - 2]) % mod;
		dp[i] = (dp[i] + tmp) % mod;
	}
	
	cout << dp[n] << "\n";

	
	return 0;
}