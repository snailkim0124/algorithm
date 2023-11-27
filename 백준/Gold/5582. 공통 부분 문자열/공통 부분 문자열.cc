#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string a, b;
int dp[4005][4005];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a;
	cin >> b;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				dp[i][j] = 1;
				if (i >= 1 && j >= 1) {
					 dp[i][j] += dp[i - 1][j - 1];
				}
			}
			res = max(res, dp[i][j]);
		}
	}

	cout << res;

	return 0;
}