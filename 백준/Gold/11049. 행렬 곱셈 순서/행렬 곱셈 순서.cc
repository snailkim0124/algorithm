#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int dp[505][505];
const int INF = 987654321;
pair<int, int> v[505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r, c;
		cin >> r >> c;
		v[i] = { r,c };
	}


	//fill(&dp[0][0], &dp[0][0] + 505 * 505, INF); // 최대로 초기화

	// 3중 for문
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i + j <= n; j++) {
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++) {
				int tmp = v[j].first * v[k].second * v[i + j].second + dp[j][k] + dp[k + 1][i + j];
				dp[j][i + j] = min(dp[j][i + j], tmp);
			}
		}
	}

	cout << dp[1][n];

	return 0;
}