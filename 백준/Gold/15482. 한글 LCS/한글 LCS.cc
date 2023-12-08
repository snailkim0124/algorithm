#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s1, s2;
int dp[3005][3005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s1;
	cin >> s2;

	for (int i = 3; i <= s1.size(); i += 3) {
		for (int j = 3; j <= s2.size(); j += 3) {
			if (s1.substr(i - 3, 3) == s2.substr(j-3, 3)) {
				dp[i][j] = dp[i - 3][j - 3] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 3][j], dp[i][j - 3]);
			}
		}
	}

	cout << dp[s1.size()][s2.size()];
	return 0;
}