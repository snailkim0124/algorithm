#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<pii> w;
double dp[20][1 << 16];
int visited[20];
const int INF = 987654321;
double mn = INF;

double dist(pii a, pii b) {
	return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}

double go(int now, int bit) {
	if (bit == (1 << n) - 1) {
	 	// 마지막은 다시 돌아와야 됨
		return dist(w[now], w[0]);
	}

	if (dp[now][bit] != -1.0) return dp[now][bit];
	dp[now][bit] = INF;

	for (int i = 0; i < n; i++) {
		if (!(bit & (1 << i))) {
			dp[now][bit] = min(dp[now][bit], dist(w[now], w[i]) + go(i, bit | (1 << i)));
		}
	}

	return dp[now][bit];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		w.push_back({ x, y });
	}

	cout << fixed;
	cout.precision(6);

	// dp 배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			dp[i][j] = -1.0;
		}
	}

	cout << go(0, 1);

	return 0;
}