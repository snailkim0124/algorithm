#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp[100005];
int n, k, w, v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	while (n--) {
		cin >> w >> v;
		for (int i = k; i >= w; i--) {
			dp[i] = max(dp[i], dp[i - w] + v);
		}
	}
	
	cout << dp[k] << "\n";

	return 0;
}