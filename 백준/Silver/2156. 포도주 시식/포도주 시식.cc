#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int a[10004];
int dp[10004];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	dp[3] = max(max(a[1], a[2]) + a[3], dp[2]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(max(a[i - 1] + dp[i - 3], dp[i - 2]) + a[i], dp[i - 1]);
	}

	cout << dp[n];
}