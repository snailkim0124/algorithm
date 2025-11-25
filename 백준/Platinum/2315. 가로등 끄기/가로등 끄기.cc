#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m;
ll d[1005], w[1005];
ll pref[1005];
ll dp[1005][1005][2]; // l, r, 왼쪽 or 오른쪽?
const ll INF = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> d[i] >> w[i];
	}

	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + w[i];
	}

	ll sum = pref[n];

	fill(&dp[0][0][0], &dp[0][0][0] + 1005 * 1005 * 2, INF); // 최대로 초기화

	dp[m][m][0] = dp[m][m][1] = 0; // 첫 시작은 0
	

	for (int sz = 1; sz <= n; sz++) {
		for (int l = 1; l + sz - 1 <= n; l++) {
			int r = l + sz - 1;
			// 갱신 전이면 넘기기 
			if (dp[l][r][0] == INF && dp[l][r][1] == INF) continue;

			ll tmp = sum - (pref[r] - pref[l - 1]); // 남은거

			// 왼쪽으로
			dp[l - 1][r][0] = min(dp[l][r][0] + tmp * (d[l] - d[l - 1]), dp[l][r][1] + tmp * (d[r] - d[l - 1]));

			// 오른쪽으로
			dp[l][r + 1][1] = min(dp[l][r][0] + tmp * (d[r + 1] - d[l]), dp[l][r][1] + tmp * (d[r + 1] - d[r]));
		}
	}

	cout << min(dp[1][n][0], dp[1][n][1]);

	return 0;
}