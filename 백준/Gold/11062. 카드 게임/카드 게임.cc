#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
int n;
int res = 0;
int arr[1005];
int dp[1005][1005];

int go(int left, int right, int round) {
	if (left > right) return 0;
	if (dp[left][right]) return dp[left][right];

	// 근우는 최대, 명우는 최소
	if (round % 2 == 0) {
		dp[left][right] = max(arr[left] + go(left + 1, right, round + 1), arr[right] + go(left, right - 1, round + 1));
	}
	else {
		dp[left][right] = min(go(left + 1, right, round + 1), go(left, right - 1, round + 1));
	}
	return dp[left][right];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cout << go(0, n - 1, 0) << "\n";
	}

	return 0;
}