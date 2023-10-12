#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[305][305];
int dp[305][305];
int cnt;

void check(int x, int y) {

	for (int i = x; i <= n; i++) {
		for (int j = y; j <= m; j++) {
			int ans;
			ans = dp[i][j] - dp[x - 1][j] - dp[i][y - 1] + dp[x - 1][y - 1];
			if (ans == 10) cnt++;
			else if (ans > 10) break;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//if (dp[i][j] > 10) continue;
			check(i, j);
		}
	}

	cout << cnt;

	return 0;
}