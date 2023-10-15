#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int dp[2505][2505];
int dp2[2505];
const int INF = 987654321;

int palindrome(int n) {
	if (n == s.size()) return 0;
	if (dp2[n] != INF) return dp2[n];
	int& res = dp2[n]; // 계속 누적
	for (int i = 1; i <= s.size() - n; i++) { // i ~ s.size() 체크
		if (dp[n][i]) res = min(res, palindrome(n + i) + 1);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s; 

	for (int i = 0; i < s.size() ; i++) { // 1개일 때
		dp[i][1] = 1;
	}

	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) dp[i][2] = 1; // 연속되면 팰린드롬
	}

	for (int i = 3; i <= s.size(); i++) {
		for (int j = 0; j <= s.size() - i; j++) {
			if (s[j] == s[j + i - 1] && dp[j + 1][i - 2]) dp[j][i] = 1;
		}
	}

	fill(dp2, dp2 + 2505, INF);
	cout << palindrome(0) << "\n";


	return 0;
}