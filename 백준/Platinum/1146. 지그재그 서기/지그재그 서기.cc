#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int mod = 1e6;
int n;
int dp[105][105];

// 작은수, 큰수
int go(int l, int r) {
	if (l + r == 0) return 1;
	if (l == 0) return 0;
	if (dp[l][r] != -1) return dp[l][r] % mod;


	int res = 0;
	for (int i = 1; i <= l; i++) {
		res = (res + go(r + l - i, i - 1)) % mod;
	}

	return dp[l][r] = res % mod;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	if (n == 1) {
		cout << 1 << "\n";
		exit(0);
	}

	memset(dp, -1, sizeof(dp));

	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = (res + go(i - 1, n - i)) % mod; // 내려가기
		res = (res + go(n - i, i - 1)) % mod; // 올라가기
	}

	cout << res << "\n";

	return 0;
}