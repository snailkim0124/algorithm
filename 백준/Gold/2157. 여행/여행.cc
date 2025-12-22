#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, k;
vector<pii> adj[305];
int dp[305][305];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	memset(dp, -1, sizeof(dp));

	// dp 누적
	dp[1][1] = 0;
	for (int j = 1; j < m; j++) {
		for (int now = 1; now <= n; now++) {
			if (dp[now][j] == -1) continue;
			for (auto [next, dist] : adj[now]) {
				// 도시번호가 증가하는 대로 움직이기
				if (now < next) {
					dp[next][j + 1] = max(dp[next][j + 1], dp[now][j] + dist);
				}			}
		}
	}

	int mx = 0;
	for (int j = 1; j <= m; j++) {
		mx = max(mx, dp[n][j]);
	}

	cout << mx << "\n";
	
	return 0;
}