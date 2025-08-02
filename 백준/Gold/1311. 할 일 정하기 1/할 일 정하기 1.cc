#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[25][25];
int dp[25][1 << 20]; // 사람, 일
const int INF = 987654321;

int go(int y, int x) {
	if (dp[y][x]) return dp[y][x];
	if (y >= n) return 0;

	int res = INF;

	for (int i = 0; i < n; i++) {
		// 완탐
		if (!(x & (1 << i))) {
			x |= (1 << i); 
			res = min(res, go(y + 1, x) + arr[y][i]);
			x &= ~(1 << i);
		}
	}

	return dp[y][x] = res;
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
	
	cout << go(0, 0);

	return 0;
}