#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, p, q;
map<ll, ll> dp;

ll go(ll num) {
	if (num <= 0) return 1;
	if (dp.find(num) != dp.end()) return dp[num];
	return dp[num] = go(num / p) + go(num / q);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> p >> q;
	dp[0] = 1;
	go(n);
	cout << dp[n];


	return 0;
}