#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;
ll dp[35][35];
int res, n;

ll dfs(int l, int r) {
	if (l == r) return 1;
	if (l > r) return 0;
	if (dp[l][r] != -1) return dp[l][r];

	dp[l][r] = dfs(l + 1, r) + dfs(l, r - 1);

	if (s[l] != s[r]) dp[l][r] -= dfs(l + 1, r - 1); // 중복 배제
	else dp[l][r] += 1;

	return dp[l][r];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	n = s.size();

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, n - 1) << "\n";

	return 0;
}