#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int w[20][20]; // i -> j
int dp[20][1 << 16];
int visited[20];
const int INF = 987654321;
int mn = INF;

int go(int now, int bit) {
	if (bit == (1 << n) - 1) {
	 	// 마지막은 다시 돌아와야 됨
		if (w[now][0] != 0) return w[now][0];
		else return INF;
	}

	if (dp[now][bit] != -1) return dp[now][bit];
	dp[now][bit] = INF;

	for (int i = 0; i < n; i++) {
		if (w[now][i] != 0 && !(bit & (1 << i))) {
			dp[now][bit] = min(dp[now][bit], w[now][i] + go(i, bit | (1 << i)));
		}
	}

	return dp[now][bit];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0, 1);

	return 0;
}