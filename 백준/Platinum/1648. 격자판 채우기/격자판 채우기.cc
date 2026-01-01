#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int mod = 9901;
int n, m;
int dp[15 * 15][1 << 15];

int go(int idx, int mask) {
	// 끝까지 도달한 경우
	if (idx == n * m) return 1;
	if (dp[idx][mask] != -1) return dp[idx][mask] % mod;

	int y = idx / m;
	int x = idx % m;
	int res = 0;

	// 이미 채워진 경우
	if (mask & 1) {
		res = go(idx + 1, mask >> 1);
	}
	else {
		if (x + 1 < m && !(mask & 2)) {
			// x : 2줄 옮기기
			res += go(idx + 2, mask >> 2);
		}

		if (y + 1 < n) {
			// x : 1줄 옮기기, y : 전 칸 채우기
			res += go(idx + 1, (mask >> 1) | (1 << (m - 1)));
		}
	}

	return dp[idx][mask] = res % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	memset(dp, -1, sizeof(dp));

	cout << go(0, 0) << "\n";

	
	return 0;
}