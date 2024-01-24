#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int c, n;
int cost[25];
int client[25];
int dp[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> c >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost[i] >> client[i];
	}

	// 냅색
	for (int i = 0; i < n; i++) {
		for (int j = cost[i]; j <= 100000; j++) { // 최대 100*1000
			dp[j] = max(dp[j], dp[j - cost[i]] + client[i]);
		}
	}

	for (int i = 0; i <= 100000; i++) {
		if (dp[i] >= c) { // 최소 비용
			cout << i;
			break;
		}
	}

	return 0;
}