#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
char arr[15][15];
int dp[15 * 15][1 << 11];

int go(int idx, int mask) {
	// mask 제한 걸기
	mask &= (1 << (m + 1)) - 1;

	if (idx == n * m) return 0;
	if (dp[idx][mask] != -1) return dp[idx][mask];

	int y = idx / m;
	int x = idx % m;
	int res = 0;

	// 스킵
	res = go(idx + 1, mask << 1);

	if (arr[y][x] == '.') {
		bool flag = true;
		// 왼쪽
		if (x > 0 && (mask & 1)) flag = false;
		// 왼쪽 위
		if (y > 0 && x > 0 && (mask & (1 << m))) flag = false;
		// 오른쪽 위
		if (y > 0 && x + 1 < m && (mask & (1 << (m - 2)))) flag = false;

		if (flag) {
			// 현재 채우고 넘어가기
			res = max(res, go(idx + 1, ((mask << 1) | 1)) + 1);
		}
	}

	return dp[idx][mask] = res;
}

void solve() {
	memset(arr, 0, sizeof(arr));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << go(0, 0) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	
	return 0;
}