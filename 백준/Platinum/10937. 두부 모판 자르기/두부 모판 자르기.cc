#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
char arr[15][15];
int dp[15 * 15][1 << 12];
map<string, int> score = {
	{"AA", 100}, {"AB", 70}, {"AC", 40}, {"AF", 0},
	{"BA", 70}, {"BB", 50}, {"BC", 30}, {"BF", 0},
	{"CA", 40}, {"CB", 30}, {"CC", 20}, {"CF", 0},
	{"FA", 0}, {"FB", 0}, {"FC", 0}, {"FF", 0},
};


int go(int idx, int mask) {
	if (idx == n * n) return 0;
	if (dp[idx][mask] != -1) return dp[idx][mask];

	int y = idx / n;
	int x = idx % n;
	int res = 0;

	if (mask & 1) {
		res = go(idx + 1, mask >> 1);
	}
	else {
		res = go(idx + 1, mask >> 1);

		// 가로
		if (x + 1 < n && !(mask & 2)) {
			string tmp = "";
			tmp += arr[y][x];
			tmp += arr[y][x + 1];

			res = max(res, score[tmp] + go(idx + 2, mask >> 2));
		}

		// 세로
		if (y + 1 < n) {
			string tmp = "";
			tmp += arr[y][x];
			tmp += arr[y + 1][x];

			res = max(res, score[tmp] + go(idx + 1, (mask >> 1) | 1 << (n - 1)));
		}
	}

	return dp[idx][mask] = res;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << go(0, 0) << "\n";


	return 0;
}