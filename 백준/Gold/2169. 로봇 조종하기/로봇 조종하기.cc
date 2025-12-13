#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int arr[1005][1005];
int dp[1005][1005];
int up[1005], l[1005], r[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	// 1행은 위가 없음
	for (int j = 2; j <= m; j++) {
		dp[1][j] = dp[1][j - 1] + arr[1][j];
	}

	for (int i = 2; i <= n; i++) {
		// 위에서 내려옴
		for (int j = 1; j <= m; j++) {
			up[j] = dp[i - 1][j] + arr[i][j];
		}

		// 왼 -> 오
		l[1] = up[1];
		for (int j = 2; j <= m; j++) {
			l[j] = max(up[j], l[j - 1] + arr[i][j]);
		}

		// 오 -> 왼
		r[m] = up[m];
		for (int j = m - 1; j >= 1; j--) {
			r[j] = max(up[j], r[j + 1] + arr[i][j]);
		}

		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(l[j], r[j]);
		}

	}

	//for (int i = 0; i <= n; i++) {
	//	for (int j = 1; j <= m; j++) {
	//		cout << dp[i][j] << "\t";
	//	}
	//	cout << "\n";
	//}

	cout << dp[n][m] << "\n";

	return 0;
}