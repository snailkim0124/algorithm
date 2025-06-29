#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
int n;
int arr[505];
int pref[505];
const int INF = 987654321;
int dp[505][505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(pref, 0, sizeof(pref));
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		// fill(&dp[0][0], &dp[0][0] + 505 * 505, INF);

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			pref[i] = pref[i - 1] + arr[i];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j + i <= n; j++) {
				dp[j][i + j] = INF;
				for (int k = j; k < i + j; k++) {
					// j ~ i + j 구간과 j ~ k + k ~ i + j 구간의 비교
					// pref : 합칠 때 드는 비용
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + pref[i + j] - pref[j - 1]);
				}
			}
		}

		cout << dp[1][n] << "\n";
	}


	return 0;
}