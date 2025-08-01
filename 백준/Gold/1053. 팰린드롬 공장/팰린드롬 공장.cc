#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int dp[55][55];
int res = 987654321;

int go(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l >= r) return 0;
	
	// 왼쪽 삭제, 오른쪽 삭제, 3번 교환
	return dp[l][r] = min({ go(l + 1, r) + 1, go(l, r - 1) + 1, go(l + 1, r - 1) + (int)(s[l] != s[r]) });

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	memset(dp, -1, sizeof(dp));
	res = min(res, go(0, s.size() - 1));

	for (int i = 0; i < s.size(); i++) {
		for (int j = i + 1; j < s.size(); j++) {
			memset(dp, -1, sizeof(dp));
			swap(s[i], s[j]);
			// 4번 교환
			res = min(res, go(0, s.size() - 1) + 1);
			swap(s[i], s[j]);
		}
	}

	cout << res;

	return 0;
}