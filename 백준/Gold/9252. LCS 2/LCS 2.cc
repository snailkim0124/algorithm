#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int dp[1005][1005];
string ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s1;
	cin >> s2;

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int x = s1.size();
	int y = s2.size();
	while (x >= 1 && y >= 1) {
		if (dp[x][y] == dp[x - 1][y]) {
			x--;
		}
		else if (dp[x][y] == dp[x][y - 1]) {
			y--;
		}
		else {
			ans += s1[x - 1];
			x--;
			y--;
		}
	}

	cout << dp[s1.size()][s2.size()] << "\n";
	if (dp[s1.size()][s2.size()]) {
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
	return 0;
}