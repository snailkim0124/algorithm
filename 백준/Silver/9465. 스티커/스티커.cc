#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int tt;
int n;
int arr[2][200005], dp[200005][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> tt;
	while (tt--) {
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));

		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		dp[0][1] = arr[0][0];
		dp[0][2] = arr[1][0];
		dp[0][0] = 0;

		for (int j = 1; j < n; j++) {
			dp[j][1] = max(dp[j - 1][2], dp[j - 1][0]) + arr[0][j]; // 위
			dp[j][2] = max(dp[j - 1][1], dp[j - 1][0]) + arr[1][j]; // 아래
			dp[j][0] = max({ dp[j - 1][0], dp[j - 1][1], dp[j - 1][2] });
		}

		cout << max({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] }) << "\n";
	}
	

	return 0;
}