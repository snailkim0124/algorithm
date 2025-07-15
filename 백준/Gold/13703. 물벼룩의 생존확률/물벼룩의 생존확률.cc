#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll k, n;
ll dp[1000][1000];

ll go(ll now, ll depth) {
	if (dp[now][depth] != -1) return dp[now][depth];
	if (now == 0) return 0; // 수면
	if (depth == n) return 1;

	// 위 경우의 수  + 아래 경우의 수
	return dp[now][depth] = go(now + 1, depth + 1) + go(now - 1, depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> k >> n;
	cout << go(k, 0);

	return 0;
}