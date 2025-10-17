#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 1000000000;
ll n;
ll res;
ll dp[105][15][1 << 10]; // 길이, 마지막, 숫자 집합

ll go(int sz, int last, int mask) {
	if (dp[sz][last][mask] != -1) return dp[sz][last][mask];
	if (sz == n) {
		// 0~9까지 모두 등장함
		if (mask == (1 << 10) - 1) return dp[sz][last][mask] = 1;
		else return dp[sz][last][mask] = 0;
	}

	dp[sz][last][mask] = 0;
	if (last > 0) dp[sz][last][mask] = (dp[sz][last][mask] + go(sz + 1, last - 1, mask | (1 << (last - 1)))) % mod;
	if (last < 9) dp[sz][last][mask] = (dp[sz][last][mask] + go(sz + 1, last + 1, mask | (1 << (last + 1)))) % mod;

	return dp[sz][last][mask];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= 9; i++) {
		res = (res + go(1, i, 1 << i)) % mod;
	}

	cout << res << "\n";

	return 0;
}