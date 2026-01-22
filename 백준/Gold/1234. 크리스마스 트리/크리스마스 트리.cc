#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll dp[15][105][105];
ll fact[15];

ll go(ll n, ll r, ll g, ll b) {
	if (n == 0) return 1;
	if (dp[n][r][g] != -1) return dp[n][r][g];
	
	ll res = 0;

	// 1개 색상 쓰기
	if (r >= n) res += go(n - 1, r - n, g, b);
	if (g >= n) res += go(n - 1, r, g - n, b);
	if (b >= n) res += go(n - 1, r, g, b - n);

	// 2개 색상 쓰기
	if (n % 2 == 0) {
		ll tmp = n / 2;
		ll multi = fact[n] / (fact[tmp] * fact[tmp]);

		if (r >= tmp && g >= tmp) res += multi * go(n - 1, r - tmp, g - tmp, b);
		if (r >= tmp && b >= tmp) res += multi * go(n - 1, r - tmp, g, b - tmp);
		if (g >= tmp && b >= tmp) res += multi * go(n - 1, r, g - tmp, b - tmp);
	}

	// 3개 색상 쓰기
	if (n % 3 == 0) {
		ll tmp = n / 3;
		ll multi = fact[n] / (fact[tmp] * fact[tmp] * fact[tmp]);

		if (r >= tmp && g >= tmp && b >= tmp)  res += multi * go(n - 1, r - tmp, g - tmp, b - tmp);
	}

	return dp[n][r][g] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fact[0] = 1;
	for (int i = 1; i <= 10; i++) {
		fact[i] = fact[i - 1] * i;
	}

	ll n, r, g, b;
	cin >> n >> r >> g >> b;
	memset(dp, -1, sizeof(dp));

	cout << go(n, r, g, b) << "\n";

	return 0;
}