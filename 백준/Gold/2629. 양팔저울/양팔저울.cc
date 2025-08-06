#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[35];
int dp[35][40005];
int sum;
int m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i][arr[i]] = 1;

		if (i == 0) continue;

		for (int j = 1; j <= sum; j++) {
			if (dp[i - 1][j]) {
				dp[i][j + arr[i]] = 1;
				dp[i][j] = 1;
				dp[i][abs(j - arr[i])] = 1;
			}
		}
	}

	//for (int j = 1; j <= sum; j++) {
	//	cout << dp[n - 1][j] << " ";
	//}

	cin >> m;
	while (m--) {
		int marble;
		cin >> marble;
		cout << (dp[n - 1][marble] ? "Y" : "N") << " ";
	}

	return 0;
}