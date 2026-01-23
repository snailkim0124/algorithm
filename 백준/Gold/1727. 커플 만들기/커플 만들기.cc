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
int arr[1005], brr[1005];
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> brr[i];
	}

	if (n > m) {
		swap(n, m);
		swap(arr, brr);
	}

	sort(arr + 1, arr + n + 1);
	sort(brr + 1, brr + m + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 매칭
			dp[i][j] = dp[i - 1][j - 1] + abs(arr[i] - brr[j]);

			// 스킵
			if (j > i) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			}

		}
	}


	cout << dp[n][m] << "\n";

	return 0;
}