#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;
int arr[5005];
int pref[5005];
int dp[5005][5005];
int mid[5005][5005];
const int INF = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(mid, 0, sizeof(mid));
		memset(dp, 0, sizeof(dp));
		memset(pref, 0, sizeof(pref));
		memset(arr, 0, sizeof(arr));

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			pref[i] = pref[i - 1] + arr[i];
		}

		// 중간다리 만들기
		for (int i = 1; i <= n; i++) {
			mid[i][i] = i;
		}

		for (int sz = 1; sz <= n; sz++) {
			for (int l = 1; l + sz <= n; l++) {
				int r = l + sz;

				dp[l][r] = INF;

				int start = mid[l][r - 1];
				int end = mid[l + 1][r];

				for (int k = start; k <= end; k++) {
					int cost = dp[l][k] + dp[k + 1][r] + pref[r] - pref[l - 1];
					if (cost < dp[l][r]) {
						dp[l][r] = cost;
						mid[l][r] = k;
					}
				}
			}
		}

		cout << dp[1][n] << "\n";
	}

	return 0;
}