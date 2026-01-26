#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int dp[505][505];

int go(int n, int k) {
	if (k == 1) return n; // k가 1이면 n 그대로임
	if (n == 0) return 0;
	if (dp[n][k] != -1) return dp[n][k];
	
	// 깨지면 바로 아래층 찾기
	// 안깨지면 위층 찾기
	int res = 987654321;
	for (int i = 1; i <= n; i++) {
		// 최대 중 최소
		int mx = max(go(i - 1, k - 1), go(n - i, k));
		res = min(res, mx + 1);
	}

	return dp[n][k] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));

	cout << go(n, k) << "\n";
	
	return 0;
}