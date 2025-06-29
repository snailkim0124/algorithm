#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
ll arr[105][105];
ll dp[105][105];

ll go(int y, int x) {
	ll& res = dp[y][x];
	if (y == n && x == n) return 1;
	if (res != -1) return res;

	res = 0;
	if (y + arr[y][x] <= n) {
		res += go(y + arr[y][x], x);
	}
	if (x + arr[y][x] <= n) {
		res += go(y, x + arr[y][x]);
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << go(1, 1) << "\n";

	return 0;
}