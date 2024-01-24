#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[105];
int c[105];
int dp[10005];
int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> c[i];
		sum += c[i];
	}

	// 냅색
	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= c[i]; j--) {
			dp[j] = max(dp[j], dp[j - c[i]] + arr[i]);
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[i] >= m) { // 최소 비용
			cout << i;
			break;
		}
	}

	return 0;
}