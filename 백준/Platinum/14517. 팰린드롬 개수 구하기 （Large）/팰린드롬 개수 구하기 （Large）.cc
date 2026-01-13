#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int mod = 10007;
string s;
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	int n = s.size();
	for (int sz = 1; sz <= n; sz++) {
		for (int l = 0; l + sz - 1 < n; l++) {
			int r = l + sz - 1;
			int tmp = 0;
			tmp = (tmp + dp[l + 1][r]) % mod; // l 제외
			tmp = (tmp + dp[l][r - 1]) % mod; // r 제외
			tmp = (tmp - dp[l + 1][r - 1] + mod) % mod; // 중복

			// 양끝이 같을 때
			if (s[l] == s[r]) {
				tmp = tmp + dp[l + 1][r - 1] + 1; // (l, r) 만큼 만들어짐
			}

			dp[l][r] = tmp % mod;
		}
	}

	cout << dp[0][n - 1] << "\n";
	
	return 0;
}