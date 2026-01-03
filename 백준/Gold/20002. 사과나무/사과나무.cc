#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[305][305];
int dp[305][305];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	int res = INT_MIN;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i + k -1<= n; i++) {
			for (int j = 1; j + k - 1 <= n; j++) {
				res = max(res, dp[i + k - 1][j + k - 1] - dp[i - 1][j + k - 1] - dp[i + k - 1][j - 1] + dp[i - 1][j - 1]);
			}
		}
	}

	cout << res << "\n";
	

	return 0;
}